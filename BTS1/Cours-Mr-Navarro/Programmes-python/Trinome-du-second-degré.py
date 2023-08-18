#------------------------------------------------------
#Nom: Ghouaiel             Prénom:Elyes
#Date de creation : 21/09/2021
#Date de dernière modif: 21/09/2021
#------------------------------------------------------
#trinome du second degré
#Le programme demande les coefficients a,b et c d'un trinome et qui calcule les racines de ce trinome si elles existent.
#------------------------------------------------------

import math

a = float(input("isérer le premier trinome"))
b = float(input("insérer le second trinome"))
c = float(input("insérer le troisième et dernier trinome"))
D = float((b*b)-4*a*c)
if D > 0 :
    x1 = float(((-b+math.sqrt(D))/(2*a)))
    x2 = float(((-b-math.sqrt(D))/(2*a)))
    print("Les racines de ce trinome sont",x1,x2)
else:
    if D == 0 :
        x0 = float(((-b)/2*a))
        print("Le seul nombre de ce trinome est",x0)
    else:
        print("Aucune racine est possible")
        
        
    
    
