<?php
include("connection.php");

try {
    // Récupérer le nombre de capteurEnv
    $sql = "SELECT COUNT(*) AS nb_capteurEnv FROM CapteurEnvironnemental";
    $result = $con->query($sql);
    $row = $result->fetch_assoc();
    $nb_capteurEnv = $row['nb_capteurEnv'];
    unset($result);
} catch(PDOException $e) {
    die('Erreur lors de la requête pour les capteurs environnementaux : ' . $e->getMessage());
}

try {
    // Récupérer les données de la table CapteurEnvironnemental
    $sql = "SELECT * FROM CapteurEnvironnemental";
    $result = $con->query($sql);
    $capteurEnv = array();
    while ($row = $result->fetch_assoc()) {
        $capteur = array(
            "idCapteur" => $row["IDCapteurEnv"],
            "temperature" => $row["TemperatureCapteur"],
            "humidite" => $row["HumiditeCapteur"],
            "pression" => $row["PressionCapteur"],
            "idPasserelle" => $row["IDPasserelle"]
        );
        array_push($capteurEnv, $capteur);
    }
    unset($result);
} catch(PDOException $e) {
    die('Erreur lors de la requête pour les capteurs environnementaux : ' . $e->getMessage());
}

// Retourner le tableau au format JSON
$resultCapteurEnv = array('nb_capteurEnv' => $nb_capteurEnv, 'capteurEnv' => $capteurEnv);
echo json_encode($resultCapteurEnv);
?>
