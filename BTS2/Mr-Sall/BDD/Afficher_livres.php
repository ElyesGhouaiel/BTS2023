<!doctype html>
<html lang="fr">
<head>
  <meta charset="utf-8">
  <title>liste des livres</title>
  <link rel="stylesheet" href="style.css">
 </head>
<body>
	<h1> Liste des livres </h1>
	<table>
		<tr> 
			<th>N° livre</th><th>titre</th>
			<th>auteur</th><th>genre</th><th>prix</th>		
		</tr>
	<?php
	/*
		Nom du script: Afficher_livres.php
		Description  : 	script qui se connecte au SGBD MySQL sur le poste local
						puis envoie une requete SQL pour obtenir les données sur 
						les livres. 
						Ensuite récupère les informations et les affiches dans un
						tableau HTML.
		Date		 : 01/02/2022
		version 	 : 1.0
		Auteur		 : Prof
	*/
	// paramètres de connexion
	$serveur 	= 'localhost';
	$user 		= 'root';
	$password   = '';
	$NomBD		= 'biblio';
	
	// connexion au SQBD MySQL
	if($bdd = mysqli_connect($serveur, $user,$password, $NomBD))
	{
		// on s'assure que le résultat sera en utf8
		mysqli_set_charset( $bdd, 'utf8');
		
	   // connexion ok on envoie une requete pour interroger la table livre
	   $requete = "SELECT * FROM livre";
	   if($resultat = mysqli_query($bdd, $requete))
	   {
		 // requete ok, on extrait les données ligne par ligne
		 while($ligne = mysqli_fetch_assoc($resultat))
		{
			// extraire les champs 
			$leNumLivre = $ligne['numlivre'];
			$leTitre    = $ligne['titre'];
			$lAuteur    = $ligne['auteur'];
			$leGenre    = $ligne['genre'];
			$lePrix     = $ligne['prix'];
			
			// on affiche
			echo "<tr>
			        <td>$leNumLivre</td><td>$leTitre</td> 
					<td>$lAuteur</td><td>$leGenre</td><td>$lePrix</td> 
			</tr>";
		}
		mysqli_free_result($resultat);
		
	   }
	   else
	   {
		    // erreur de requête
			die("erreur de requete SQL");
	   }
	}
	else{
		// echec de connexion
		die("erreur de connexion au SGBD ");
	}
	
	
	?> 
	 </table>
	 <a href="index.html"><img src="back.ico"></a>
</body>
</html>