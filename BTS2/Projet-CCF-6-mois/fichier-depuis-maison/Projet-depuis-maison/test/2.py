import mysql.connector
import time
import serial
from flask import Flask, request
import threading

# Informations de connexion
config = {
    'user': 'AfficheurUser',
    'password': 'Azerty77afficheur',
    'host': '192.168.1.72',
    'database': 'bddprincipal'
}

app = Flask(__name__)

# Variable pour stocker le dernier message affiché
dernier_message = None

@app.route('/', methods=['POST'])
def recevoir_donnees():
    id_afficheur = request.form.get('idAfficheur')
    contenu = request.form.get('contenu')

    # Mettre à jour les données dans votre base de données
    update_data(id_afficheur, contenu)

    # Récupérer le choix sélectionné
    choix = retrieve_choice(id_afficheur)

    # Envoyer le choix à l'Arduino
    if choix is not None:
        print("Numéro de l'afficheur {} Message : {}".format(id_afficheur, choix))
        send_to_arduino(choix)

        # Comparer le choix avec le dernier message affiché
        global dernier_message
        if choix != dernier_message:
            print("Le message a changé")
            dernier_message = choix
        else:
            print("Le message n'a pas changé")

    return 'Données reçues avec succès !'

def update_data(id_afficheur, contenu):
    # Se connecter à la base de données
    cnx = mysql.connector.connect(**config)
    cursor = cnx.cursor()

    # Exécuter une requête SQL pour mettre à jour les données
    query = "UPDATE Afficheurs SET Contenu = %s WHERE Id_Afficheurs = %s"
    values = (contenu, id_afficheur)
    cursor.execute(query, values)

    # Valider la transaction
    cnx.commit()

    # Fermer la connexion
    cursor.close()
    cnx.close()

def retrieve_choice(id_afficheur):
    # Se connecter à la base de données
    cnx = mysql.connector.connect(**config)
    cursor = cnx.cursor()

    # Exécuter une requête SQL
    query = "SELECT Contenu FROM Afficheurs WHERE Id_Afficheurs = %s"
    values = (id_afficheur,)
    cursor.execute(query, values)

    # Récupérer le résultat
    result = cursor.fetchone()

    # Fermer la connexion
    cursor.close()
    cnx.close()

    if result is not None:
        return result[0]
    else:
        return None

def send_to_arduino(message):
    # Se connecter à l'Arduino via la communication série
    ser = serial.Serial('COM1', 9600)  # Modifier le port série selon votre configuration

    # Envoyer le message à l'Arduino
    ser.write(message.encode())

    # Fermer la connexion série
    ser.close()

def retrieve_all_data():
    # Se connecter à la base de données
    cnx = mysql.connector.connect(**config)
    cursor = cnx.cursor()

    # Exécuter une requête SQL pour récupérer toutes les données
    query = "SELECT Id_Afficheurs, Contenu, Emplacement FROM Afficheurs"
    cursor.execute(query)

    # Récupérer tous les résultats
    data = cursor.fetchall()

    # Fermer la connexion
    cursor.close()
    cnx.close()

    return data

def main():
    global dernier_message, temps_dernier_changement

    while True:
        # Récupérer toutes les données de la base de données
        data = retrieve_all_data()

        message_change = False

        for (Id_Afficheurs, Contenu, Emplacement) in data:
            if Contenu != dernier_message:
                message_change = True
                dernier_message = Contenu  # Mettre à jour le dernier message
                send_to_arduino(Contenu)  # Envoyer le message à l'Arduino

        if message_change:
            temps_dernier_changement = time.time()
            print("Le message a changé")
        elif temps_dernier_changement is not None and time.time() - temps_dernier_changement >= 10:
            temps_dernier_changement = None
            print("Le message n'a pas changé")
        else:
            print("Le message n'a pas changé")

        time.sleep(1)  # Attendre 1 seconde avant de vérifier à nouveau

def run_flask():
    app.run(debug=False)

if __name__ == "__main__":
    # Lancer le serveur Flask dans un thread séparé
    flask_thread = threading.Thread(target=run_flask)
    flask_thread.start()

    # Exécuter la fonction main() dans le thread principal
    main()
