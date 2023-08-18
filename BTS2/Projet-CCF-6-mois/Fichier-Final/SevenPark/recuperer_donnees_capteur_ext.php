<?php
include("connection.php");

if (isset($_GET['passerelle']) && isset($_GET['capteur'])) {
  $passerelleID = $_GET['passerelle'];
  $capteurID = $_GET['capteur'];

  try {
    // Récupérer les données du capteur externe
    $sql_ext = "SELECT * FROM CapteurExt WHERE IDPasserelle = '$passerelleID' AND IDCapteur = '$capteurID'";
    $result_ext = $con->query($sql_ext);
    $capteurData = $result_ext->fetch_assoc();
    unset($result_ext);

    // Vérifier si la donnée EtatBatterie est vide et la remplacer par "Na"
    if (empty($capteurData['EtatBatterie'])) {
      $capteurData['EtatBatterie'] = "Na";
    }

    if ($capteurData['EtatPlace'] == 0) {
      $capteurData['EtatPlace'] = "Libre";
    }
    if ($capteurData['EtatPlace'] == 1) {
      $capteurData['EtatPlace'] = "Occupée";
    }

    if ($capteurData['EtatCapteur'] == 0) {
      $capteurData['EtatCapteur'] = "Capteur de stationnement désactivé";
    }
    if ($capteurData['EtatCapteur'] == 1) {
      $capteurData['EtatCapteur'] = "Capteur de stationnement activé";
    }
    
    // Retourner les données au format JSON
    echo json_encode($capteurData);
  } catch(PDOException $e) {
    die('Erreur lors de la requête pour les données du capteur externe : ' . $e->getMessage());
  }
}
?>