<?php
include("connection.php");

if (isset($_GET['passerelle']) && isset($_GET['capteur'])) {
  $passerelleID = $_GET['passerelle'];
  $capteurID = $_GET['capteur'];

  try {
    // Récupérer les données du capteur interne
    $sql_int = "SELECT * FROM CapteurInt WHERE IDPasserelle = '$passerelleID' AND IDCapteur = '$capteurID'";
    $result_int = $con->query($sql_int);
    $capteurData = $result_int->fetch_assoc();
    unset($result_int);

    if ($capteurData['EtatPlace'] == 0) {
      $capteurData['EtatPlace'] = "Libre";
    }
    if ($capteurData['EtatPlace'] == 1) {
      $capteurData['EtatPlace'] = "Occupée";
    }

    // Retourner les données au format JSON
    echo json_encode($capteurData);
  } catch(PDOException $e) {
    die('Erreur lors de la requête pour les données du capteur interne : ' . $e->getMessage());
  }
}
?>