#ici on crée la fonction qui permet d'afficher la bande du jeu et qui demande le nom du joueur 1:
def nom_1():
    print("======== Jeu des Allumettes ========\n")
    nom1=str=(' ')
    nom1=input("entrer le nom du joeur 1: ")
    return(nom1)



#Même chose que pour le joueur 1 mais avec le 2:
def nom_2():
    print("======== Jeu des Allumettes ========\n")
    nom2=str=(' ')
    nom2=input("entrer le nom du joeur 2: ")
    return(nom2)

#Ici on crée une fonction qui permet de crée un nombre aléatoire selon le min et le max envoyé:
def nombrealeatoire(minimum=int,maximum=int):
    import random
    n=int
    n=random.randrange(mini, maxi)
    return n

#Ici on crée un procédure qui permet d'afficher le nombres d'alumettes en focntion du nombre aléatoire:
def nombresalumettes():
    print("\n\n")
    i=int(0)
    for (i;i<n;i++):
        print("|  ")


#ici c'est la fonction qui permet de déterminer à qui de jouer:
def tourpartour(aquidejouer=int,nom1=str,nom2=str):
    if(aquidejouer==1):
        print("\n\n")
        aquidejouer++

#ici se trouve le main: pas besoin de main ...
nom1=str
nom2=str
n=int(1)
aquidejouer=int(1)
nom1=nom_1()
nom2=nom_2()
print("\n\n--- Debut du jeu --- ")
n = nombrealeatoire(5,35)
while (n!=0):
    nombresallumettes(n)
    aquidejouer = TourparTour(aquidejouer,nom1,nom2)
    n = enlever(n)
    
    
