#------------------------------------------------------
#Nom: Ghouaiel             Prénom:Elyes
#Date de creation : 21/09/2021
#Date de dernière modif: 21/09/2021
#------------------------------------------------------
#Calcul_du prix TTC
#Le programme calcule le prix TTC sachant que le programme demande le prix hors taxe , le nombre et le taux de TVA .
#//------------------------------------------------------

HT = float(input("Insérer le prix hors taxe"))
Le_nombre = float(input("Insérer le nombre"))
TVA = float(input("Insérer la TVA"))
TTC = float((Le_nombre*HT)*(1+(TVA/100)))
print("Voici le prix TTC =",TTC)
