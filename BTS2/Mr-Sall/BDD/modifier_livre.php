<!doctype html>
<html lang="fr">
<head>
  <meta charset="utf-8">
  <title>modifier des livres</title>
  <link rel="stylesheet" href="style.css">
 </head>
<body>
	
	<?php
	/*
		Nom du script: modifier_livres.php
		Description  : 	script qui récupere le numero du livre à modifier puis
						se connecte au SGBD MySQL sur le poste local
						puis envoie une requete SQL pour obtenir les données sur 
						le livre à modifier. 
						Ensuite récupère les informations et les intégres
						dans un formulaire.
						Une fois le formulaire validé, envoie une requête pour
						inserer les données dans SGBD
		Date		 : 01/02/2022
		version 	 : 1.0
		Auteur		 : Prof
	*/
	// On determine si on doit afficher ( $_Post['titre'] n'existe pas)
	// ou traiter le formulaire ($_Post['titre'] existe)
	if(!isset($_POST["titre"]))
	{
		$numLivreRecherche = nettoyer($_GET['numlivre']);
		// se connecter au SGBD
		// paramètres de connexion
		$serveur 	= 'localhost';
		$user 		= 'root';
		$password   = '';
		$NomBD		= 'biblio';
		
		// connexion au SQBD MySQL
		if($bdd = mysqli_connect($serveur, $user,$password, $NomBD))
		{
			// envoyer une requete pour recuperer les donnees sur le livre 
			// on s'assure que le résultat sera en utf8
			mysqli_set_charset( $bdd, 'utf8');
			
		   // connexion ok on envoie une requete pour interroger la table livre
		   $requete = "SELECT * FROM livre WHERE numlivre=$numLivreRecherche";
		   if($resultat = mysqli_query($bdd, $requete))
		   {
			   //Ensuite récupère les données et les intégresdans un formulaire.
			   $ligne = mysqli_fetch_assoc($resultat);
			   // extraire les champs 
				$leNumLivre = $ligne['numlivre'];
				$leTitre    = $ligne['titre'];
				$lAuteur    = $ligne['auteur'];
				$leGenre    = $ligne['genre'];
				$lePrix     = $ligne['prix'];
			   // incorporer dans un formulaire 
			?>
			<form method="post" action="">
				<label>N° livre :</label>
				<input type="text" name="numlivre" value=<?php echo $leNumLivre; ?>
				readonly><br> 
				<label for="titre">titre :</label>
				<input type="text" name="titre" id="titre" placeholder="Entrer le titre" 
				required value="<?php echo $leTitre; ?>"/></br>
				<label for="auteur">Auteur :</label>
				<input type="text" name="auteur" id="auteur" required 
				placeholder="Entrer l'auteur" value="<?php echo $lAuteur; ?>"/></br>
				<label for="genre">genre :</label>
				<select name="genre" id="genre" value="<?php echo $leGenre; ?>">
					   <option  value="roman">roman</option>
						<option value="poésie">poésie</option>
						<option value="nouvelles">nouvelles</option>
						<option value="autres">autres</option>
				</select><br>
				<label for="prix">prix :</label>
				<input type="number" name="prix" id="prix" placeholder="Entrer le prix" 
				required  value="<?php echo $lePrix; ?>" /></br>
				<input type="submit" value="Envoyer" />
			</form>
	  
			   
			<?php   
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
	else
	{
		// le formulaire à été complété et envoyé, netoyer les données
		// avant de les utiliser
		
		$leNumLivre = nettoyer($_POST["numlivre"]);
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
			$requete = "UPDATE livre
						SET titre='$leTitre', auteur='$lAuteur', genre ='$leGenre',
						prix =$lePrix
						WHERE numlivre = $leNumLivre"  ;           
						
		
			// on envoie la requette
			if($resultat = mysqli_query($bdd, $requete))
			{
			   require_once("afficher_livres.php");
			}
			else
			{
				// erreur de requête
				echo $requete;
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