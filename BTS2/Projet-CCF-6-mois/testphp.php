<?php// Connexion à la base de données
$serveur = "localhost";
$utilisateur = "root";
$mot_de_passe = "admin";
$base_de_donnees = "BDDPrincipal";

$connexion = new mysqli($serveur, $utilisateur, $mot_de_passe, $base_de_donnees);

// Récupération du chiffre entré par l'utilisateur
$chiffre = $_POST["chiffre"];

// Requête SQL pour mettre à jour la valeur de la colonne dans la table
$requete = "UPDATE ma_table SET colonne1 = '$chiffre' WHERE id = 1"; // Remplacez id par l'identifiant de la ligne que vous souhaitez mettre à jour

// Exécution de la requête
if ($connexion->query($requete) === TRUE) {
  echo "La valeur a été mise à jour avec succès.";
} else {
  echo "Erreur : " . $requete . "<br>" . $connexion->error;
}

// Fermeture de la connexion à la base de données
$connexion->close();
?>