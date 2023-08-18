#Nom: Ghouaiel             Prénom:Elyes
#Date de creation : 21/09/2021
#Date de dernière modif: 21/09/2021
#------------------------------------------------------
#Comparaison
#Le programme demande 3 nombres et affiche le plus petit des 3
#------------------------------------------------------

NB1 = float(input("Saisir le premier nombre"))
NB2 = float(input("Saisir le second nombre"))
NB3 = float(input("Saisir le troisième et dernier nombre"))
if NB1 < NB2 and NB1 < NB3 :
    print(NB1)
else:
    if NB2 < NB3 and NB2 < NB1 :
        print(NB2)
    else:
        if NB3 < NB2 and NB3 < NB1 :
            print (NB3)
