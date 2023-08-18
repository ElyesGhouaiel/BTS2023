#
#Ghouaiel Elyes
#05/10/2021
#
#saisie bornée d'un nombre
#
#le programme doit demander à l'utilisateur un nombre compris entre 1  et 10 (inclus) jusqu'à que la réponse convienne.
#Début

x=float(input("Saisir un nombre entre 1 et 10 inclus"))
if  1 < x < 10 :
    print("le nombre compris est bien entre 1 et 10 inclus")
else:
    while (x<1 and x>10):
        x=float(input("le nombre n'est pas compris entre 1 et 10 inclus, Reinsérer un nombre"))
#Fin
        
