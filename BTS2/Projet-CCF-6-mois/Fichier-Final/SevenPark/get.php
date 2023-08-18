<?php
$servername = 'localhost';
$username = 'root';
$password = 'admin';
$dbname = 'BDDPrincipal';

// Connexion à la base de données
$conn = new mysqli($servername, $username, $password, $dbname);

// Vérification de la connexion
if ($conn->connect_error) {
    die("Connexion échouée : " . $conn->connect_error);
}

// Requête SQL pour récupérer les données de la table "historiquemess"
$sql = "SELECT * FROM HistoriqueMess";
$result = $conn->query($sql);

// Vérification des résultats de la requête
if ($result->num_rows > 0) {
    // Tableau pour stocker les données
    $donnees = array();

    // Parcourir les lignes de résultats
    while ($row = $result->fetch_assoc()) {
        $donnees[] = $row;
    }

    // Convertir les données en format JSON
    $json = json_encode($donnees);

    // Envoyer la réponse JSON
    header('Content-Type: application/json');
    echo $json;
} else {
    echo 'Aucun résultat trouvé.';
}

$conn->close();
?>
