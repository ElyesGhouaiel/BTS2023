<!doctype html>
<html lang="fr">
<head>
  <meta charset="utf-8">
  <title>liste des livres</title>
  <link rel="stylesheet" href="style.css">
  </head>
<body>
	<table>
		<tr>		
			<th>N° livre</th><th>titre</th><th>auteur</th><th>genre</th><th>prix</th>
		</tr>
	
	<?php
	/********************************************************************
		Nom du script : Afficher_livre.php
		Description   : script qui se connecte au SGBD sur le poste local,
						puis envoie une requête SQL pour obtenir la liste
						des livres.
						Ensuite récupére les données et les affiches dans
						un tableau HTML
		Date	      : 4/03/2022
		Version		  : 1.0
		Auteur		  : Prof
	********************************************************************/
	echo "<h1> Liste des livres </h1>";
	
	// paramêtres de connexion
	$serveur      = "localhost";
	$utilisateur  = "user";
	$motDePasse	  = "Azerty77";
	$BD			  = "biblio";
	
	// tentative de connexion au SGBD MySQL
	if($bdd = mysqli_connect($serveur, $utilisateur, $motDePasse, $BD))
	{
		// on s'assure que le résultat sera en utf8
		mysqli_set_charset( $bdd, 'utf8');
		
		// connexion ok, on envoie une requete sql
		$requete = "SELECT * FROM livre";
		
		if($resultat = mysqli_query($bdd,$requete))
		{
			// requete ok on extrait les données et on affiche
			while($donnees = mysqli_fetch_assoc($resultat))
			{
				// on stocke les données de la ligne dans des variables
				$numlivre 	= $donnees['numlivre'];
				$titre 		= $donnees['titre'];
				$auteur 	= $donnees['auteur'];
				$genre 		= $donnees['genre'];
				$prix 		= $donnees['prix'];
				
				// afficher la ligne dans la page HTML
				echo "<tr> 
						<td>$numlivre</td><td>$titre</td>
						<td>$auteur</td><td>$genre</td> <td>$prix</td> 
					</tr>";
			}
			// on libere le jeu de résultat 
			mysqli_free_result($resultat);
		}
		else
		{
			// erreur de requête
			echo "erreur de requête";
		}
	}
	else
	{
	    // erreur de connexion 
		echo "erreur de connexion au serveur";
	}
	
	
	?>
</body>
<html>