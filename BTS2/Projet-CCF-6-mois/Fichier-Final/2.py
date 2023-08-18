import mysql.connector
import time
import serial
from flask import Flask, request
import threading

# Informations de connexion
config = {
    'user': 'AfficheurUser',
    'password': 'Afficheur',
    'host': '10.198.214.55',
    'database': 'BDDPrincipal'
}

app = Flask(__name__)

# Variable pour stocker le dernier message affiché
dernier_message = None

# Configuration de la communication série
ser = serial.Serial("/dev/ttyS0", 9600)

def send_to_arduino_Id_Message_Register(Id_Message_Register):
    message = str(Id_Message_Register)
    ser.write(message.encode())

def send_to_arduino_message_perso(custom_message):
    message = "6" + "/" + custom_message 
    ser.write(message.encode())
    print(message)

@app.route('/', methods=['POST'])
def recevoir_donnees():
    Id_Message_Register = request.form.get('Id_Message_Register')
    contenu = request.form.get('Contenu')

    # Récupérer le contenu du message personnalisé
    custom_message = request.form.get('customMessage')

    # Insérer le message personnalisé dans la table MessagePerso
    mettre_a_jour_message_personnalise(custom_message)

    # Mettre à jour les données dans votre base de données
    update_data(Id_Message_Register, contenu)

    # Récupérer le choix sélectionné
    choix = retrieve_choice(Id_Message_Register)
    
    #inserer les données dans la table HistoriqueMess
    inserer_donnees(Id_Message_Register, choix, custom_message)

    if choix is not None:
        print("Numéro de message Pré-enregistrés {} Message : {}".format(Id_Message_Register, choix))
    elif custom_message:
        print("Message personnalisé : {}".format(custom_message))
        send_to_arduino_message_perso(custom_message)
        
    # Comparer le choix avec le dernier message affiché
    global dernier_message
    if choix != dernier_message:
        if Id_Message_Register is not None:
            send_to_arduino_Id_Message_Register(Id_Message_Register)
        print("Le message a changé")
        dernier_message = choix
    else:
        print("Le message n'a pas changé")

    return 'Données reçues avec succès !'

def inserer_donnees(Id_Message_Register, choix, custom_message):
    # Informations de connexion à la base de données
    host = '10.198.214.55'
    user = 'AfficheurUser'
    password = 'Afficheur'
    database = 'BDDPrincipal'

    # Établir la connexion à la base de données
    conn = mysql.connector.connect(host=host, user=user, password=password, database=database)

    # Créer un curseur pour exécuter les requêtes SQL
    cursor = conn.cursor()

    # Requête SQL pour insérer les données dans la table historiquemess
    sql = "INSERT INTO HistoriqueMess (Date,Id_Message_Register, Contenu, Contenu_Mess_Perso) VALUES (NOW(), %s, %s, %s)"

    values = (Id_Message_Register, choix, custom_message)

    # Exécuter la requête SQL
    cursor.execute(sql, values)

    # Valider les modifications dans la base de données
    conn.commit()

    # Fermer le curseur et la connexion
    cursor.close()
    conn.close()

    print("Données insérées avec succès dans la table historiquemess.")
    
def mettre_a_jour_message_personnalise(message):
    try:
        # Informations de connexion à la base de données
        host = '10.198.214.55'
        user = 'AfficheurUser'
        password = 'Afficheur'
        database = 'BDDPrincipal'

        # Établir la connexion à la base de données
        conn = mysql.connector.connect(host=host, user=user, password=password, database=database)

        # Créer un curseur pour exécuter les requêtes SQL
        cursor = conn.cursor()

        # Requête SQL pour mettre à jour le message personnalisé dans la table MessagePerso
        sql = "UPDATE MessagePerso SET Contenu_Mess_Perso = %s WHERE Id_Message_Perso = %s"
        values = (message, 6)  # Utiliser l'ID correspondant à votre message personnalisé

        # Exécuter la requête SQL
        cursor.execute(sql, values)

        # Valider les modifications dans la base de données
        conn.commit()

        # Fermer le curseur et la connexion
        cursor.close()
        conn.close()

        print("Message personnalisé mis à jour dans la table MessagePerso avec succès.")

    except mysql.connector.Error as error:
        print("Erreur lors de la mise à jour du message personnalisé dans la table MessagePerso :", error)

def update_data(Id_Message_Register, contenu):
    # Se connecter à la base de données
    cnx = mysql.connector.connect(**config)
    cursor = cnx.cursor()

    # Exécuter une requête SQL pour mettre à jour les données
    query = "UPDATE Message_Register SET Contenu = %s WHERE Id_Message_Register = %s"
    values = (contenu, Id_Message_Register)
    cursor.execute(query, values)

    # Valider la transaction
    cnx.commit()

    # Fermer la connexion
    cursor.close()
    cnx.close()

def retrieve_choice(Id_Message_Register):
    # Se connecter à la base de données
    cnx = mysql.connector.connect(**config)
    cursor = cnx.cursor()

    # Exécuter une requête SQL
    query = "SELECT Contenu FROM Message_Register WHERE Id_Message_Register = %s"
    values = (Id_Message_Register,)
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

def retrieve_all_data():
    # Se connecter à la base de données
    cnx = mysql.connector.connect(**config)
    cursor = cnx.cursor()

    # Exécuter une requête SQL pour récupérer toutes les données
    query = "SELECT Id_Message_Register, Contenu, Type FROM Message_Register"
    cursor.execute(query)

    # Récupérer tous les résultats
    data = cursor.fetchall()

    # Fermer la connexion
    cursor.close()
    cnx.close()

    return data

def run_flask():
    app.run(host='10.198.214.69', debug=False)  # Écouter sur toutes les adresses IP disponibles
    


if __name__ == "__main__":
    # Lancer le serveur Flask dans un thread séparé
    flask_thread = threading.Thread(target=run_flask)
    flask_thread.start()

    # Exécuter la fonction main() dans le thread principal
    #main()
