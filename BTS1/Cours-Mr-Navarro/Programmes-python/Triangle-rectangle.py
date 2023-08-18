#------------------------------------------------------
#Nom: Ghouaiel             Prénom:Elyes
#Date de creation : 21/09/2021
#Date de dernière modif: 21/09/2021
#------------------------------------------------------
#Triangle rectangle
#Le programme demande longuur des 3 cotes d'un triangle ( dans un ordre quelconque), et qui détermine si celui-ci est rectangle .
#------------------------------------------------------

AB = float(input("Insérer la première longueur"))
BC = float(input("Insérer la deuxième longueur"))
AC = float(input("Insérer la troisième et dernière longueur"))
flag=0
if AB*AB==(BC*BC)+(AC*AC) :
    print("Le triangle est rectangle")
    flag=1
if BC*BC==(AC*AC)+(AB*AB) :
    print("Le triangle est rectangle")
    flag=1
if AC*AC==(AB*AB)+(BC*BC) :
    print("Le triangle est rectangle")
    flag=1
if (flag==0) :
    print("Le triangle n'est pas rectangle")
    
    
