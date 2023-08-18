#RecupDonnee.py

import mysql.connector

mydb = mysql.connector.connect(
host='10.198.214.76', 
port='3306', 
user='root', 
password='admin', 
database='BDDPrincipal')

mycursor = mydb.cursor()
mycursor.execute("SELECT contenu FROM Message_Register WHERE Id_Message_Register = 8")
myresult = mycursor.fetchall()
message = myresult[0]




