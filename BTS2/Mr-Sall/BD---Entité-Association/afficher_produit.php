<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Liste des produits</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous">
  </head>
  <body>
    <h1>Liste des produits </h1>
		<table class="table-primary">
		<tr> 
			<th>Code</th><th>désignation</th>
			<th>prix</th><th>poids</th><th>couleur</th><th> </th><th> </th>		
		</tr>
      <?php
		/*
			Nom du script :
			Description :
			Date   :
			Auteur :
		*/
		
		if($bdd = mysqli_connect('localhost', 'root', '', 'gestionventes'))
		{
			// on interroge Mysql pour recuperer les données de la table produit
			// on s'assure que le résultat sera en utf8
			mysqli_set_charset( $bdd, 'utf8');
		
			// connexion ok on envoie une requete pour interroger la table livre
			$requete = "SELECT * FROM produit";
			if($resultat = mysqli_query($bdd, $requete))
			{
				// requete ok, il faut extraire le résultat et afficher
				while($ligne = mysqli_fetch_assoc($resultat))
				{
					// extraire les champs 
					$codeProuit = $ligne['IdProduit'];
					$nomProduit = $ligne['nomProduit'];
					$prix       = $ligne['prix'];
					$poids      = $ligne['poids'];
					$couleur    = $ligne['couleur'];
			
					// on affiche
					echo "<tr class=\"table-primary\">
						<td>$codeProuit</td><td>$nomProduit</td> 
						<td>$prix</td><td>$poids</td><td>$couleur</td>
						
						</tr>";
		}
		mysqli_free_result($resultat);
								
			}
			else{
				// requete ko
				die("erreur de requete SQL");
			}
		}
		else
		{
			// echec de connexion
			die("erreur de connexion au SGBD ");
		}
		
		?>  
	   

  
  </body>
</html>