# MyData
import mysql.connector

# informations de connexion
config = {
  'user': 'AfficheurUser',
  'password': 'Azerty77afficheur',
  'host': '10.198.214.76',
  'database': 'BDDPrincipal'
}

# se connecter à la base de données
cnx = mysql.connector.connect(**config)
cursor = cnx.cursor()

# exécuter une requête SQL
query = ("select * from Afficheurs")
cursor.execute(query)

# récupérer les résultats
for (Id_Afficheurs, Contenu, Emplacement) in cursor:
  print("Numéro de l'afficheur {} Message : {} {} .".format(Id_Afficheurs, Contenu, Emplacement))

# fermer la connexion
cursor.close()
cnx.close()
