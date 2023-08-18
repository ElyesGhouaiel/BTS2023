<!doctype html>
<html lang="fr">
<head>
  <meta charset="utf-8">
  <title>Titre de la page</title>
  <link rel="stylesheet" href="style.css">
  <script src="script.js"></script>
</head>
<body>
  <?php
	/*
		Nom du script: inserrer_livres.php
		Description  : 	script qui affiche un formulaire pour que l'utilisateur
						entre les données sur un livre.
						Lorsque le formulaire est envoyé, ce scripte se connecte 
						au SGBD MySQL sur le poste local,
						puis envoie une requete SQL pour inserrer les données 
						dans la table livre, ensuite appelle le script qui affiche 
						les livres.
		Date		 : 03/02/2022
		version 	 : 1.0
		Auteur		 : Prof
	*/
  
	// On determine si on doit afficher ( $_Post['titre'] n'existe pas)
	// ou traiter le formulaire ($_Post['titre'] existe)
	if(!isset($_POST["titre"]))
	{
		// il faut afficher le formulaire html
	?>	
	<h1>ajouter un nouveau livre </h1>
		<form method="post" action="">
			<label for="titre">titre :</label>
			<input type="text" name="titre" id="titre" placeholder="Entrer le titre" 
			required /></br>
			<label for="auteur">Auteur :</label>
			<input type="text" name="auteur" id="auteur" required 
			placeholder="Entrer l'auteur" /></br>
			<label for="genre">genre :</label>
			<select name="genre" id="genre">
				   <option  value="roman" selected>roman</option>
					<option value="poésie">poésie</option>
					<option value="nouvelles">nouvelles</option>
					<option value="autres">autres</option>
			</select><br>
			<label for="prix">prix :</label>
			<input type="number" name="prix" id="prix" placeholder="Entrer le prix" 
			required /></br>
			<input type="submit" value="Envoyer" />
		</form>
	<?php	
	}
	else
	{
		// le formulaire à été complété et envoyé, netoyer les données
		// avant de les utiliser
		
		$leTitre = nettoyer($_POST["titre"]);
		$lAuteur = nettoyer($_POST["auteur"]);
		$leGenre = nettoyer($_POST["genre"]);
		$lePrix  = nettoyer($_POST["prix"]);
		
		// on se connecte au SGBD pour lui envoyer la requête d'insertion
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
			$requete = "INSERT INTO livre(titre,auteur,genre,prix)
			            VALUES('$leTitre','$lAuteur','$leGenre',$lePrix) ";
		
			// on envoie la requette
			if($resultat = mysqli_query($bdd, $requete))
			{
			   echo "insertion ok";
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
		
	}
	
    function nettoyer($chaine)
	{
		//Supprime les antislashs d'une chaîne
		$chaine= stripslashes($chaine);
		
		//Supprime les balises HTML et PHP d'une chaîne
		$chaine = strip_tags($chaine);
		
		// Convertit tous les caractères éligibles en entités HTML
		$chaine  = htmlentities($chaine);
		
		// on retourne la chaine "filtrée"
		return $chaine;
	}
  
  ?>
</body>
</html>