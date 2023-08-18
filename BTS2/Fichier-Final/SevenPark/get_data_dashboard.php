<?php
include("connection.php");

try {
  $sql = "SELECT COUNT(*) as nb_libre_int FROM `CapteurInt` WHERE `EtatPlace` = 0";
  $result = $con->query($sql);
  $row = $result->fetch_assoc();
  $nb_libre_int = $row['nb_libre_int'];
  unset($result);
} catch(PDOException $e) {
  die('Erreur lors de la requête pour les capteurs internes libres : ' . $e->getMessage());
}

try {
  $sql = "SELECT COUNT(*) as nb_libre_ext FROM `CapteurExt` WHERE `EtatPlace` = 0";
  $result = $con->query($sql);
  $row = $result->fetch_assoc();
  $nb_libre_ext = $row['nb_libre_ext'];
  unset($result);
} catch(PDOException $e) {
  die('Erreur lors de la requête pour les capteurs externes libres : ' . $e->getMessage());
}

try {
  $sql = "SELECT COUNT(*) as nb_prise_int FROM `CapteurInt` WHERE `EtatPlace` = 1";
  $result = $con->query($sql);
  $row = $result->fetch_assoc();
  $nb_prise_int = $row['nb_prise_int'];
  unset($result);
} catch(PDOException $e) {
  die('Erreur lors de la requête pour les capteurs internes pris : ' . $e->getMessage());
}

try {
  $sql = "SELECT COUNT(*) as nb_prise_ext FROM `CapteurExt` WHERE `EtatPlace` = 1";
  $result = $con->query($sql);
  $row = $result->fetch_assoc();
  $nb_prise_ext = $row['nb_prise_ext'];
  unset($result);
} catch(PDOException $e) {
  die('Erreur lors de la requête pour les capteurs externes pris : ' . $e->getMessage());
}

try {
  $sql = "SELECT ROUND(AVG(TemperatureCapteur),1) as avg_temperature, ROUND(AVG(HumiditeCapteur),1) as avg_humidite FROM `CapteurEnvironnemental`";
  $result = $con->query($sql);
  $row = $result->fetch_assoc();
  $avg_temperature = $row['avg_temperature'];
  $avg_humidite = $row['avg_humidite'];
  unset($result);
} catch(PDOException $e) {
  die('Erreur lors de la requête pour les capteurs : ' . $e->getMessage());
}

$nb_libre = $nb_libre_int + $nb_libre_ext;
$nb_prise = $nb_prise_int + $nb_prise_ext;

// Return the data as a JSON-encoded string
$data = array(
  'nb_libre' => $nb_libre,
  'nb_prise' => $nb_prise,
  'avg_temperature' => $avg_temperature,
  'avg_humidite' => $avg_humidite
);

echo json_encode($data);
?>