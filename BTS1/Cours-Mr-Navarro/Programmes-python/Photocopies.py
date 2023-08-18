#------------------------------------------------------
#Nom: Ghouaiel             Prénom:Elyes
#Date de creation : 21/09/2021
#Date de dernière modif: 21/09/2021
#------------------------------------------------------
#Calcul_d'équation_de_droite
#Le programme affiche le montant à payer sachant que les 10 premières photocopies valent 20 centimes l'une , 10 centimes //(l'une) les vingts suivantes et 5 centimes (l'une) au delà .
#------------------------------------------------------

x = float(input("Insérer le nombre de phtocopies"))
if x<10 and x>=0 :
    y =float(x*0.20)
else :
    if x>10 and x<=30 :
        y=float((10*0.2)+((x-10)*0.10))
    else :
        y=float((10*0.2)+(20*0.1)+((x-30)*0.05))
print("Le montant à payer est de =",y)

    
