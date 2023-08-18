<?php
include("connection.php");

if (isset($_GET['passerelle'])) {
  $passerelleID = $_GET['passerelle'];

  try {
    // Récupérer les capteurs internes de la passerelle sélectionnée
    $sql_int = "SELECT * FROM CapteurInt WHERE IDPasserelle = '$passerelleID'";
    $result_int = $con->query($sql_int);
    $capteurs_int = array();
    while ($row_int = $result_int->fetch_assoc()) {
      $capteur_int = array(
        "id" => $row_int["IDCapteur"]
      );
      array_push($capteurs_int, $capteur_int);
    }
    unset($result_int);
  } catch(PDOException $e) {
    die('Erreur lors de la requête pour les capteurs internes : ' . $e->getMessage());
  }

  try {
    // Récupérer les capteurs externes de la passerelle sélectionnée
    $sql_ext = "SELECT * FROM CapteurExt WHERE IDPasserelle = '$passerelleID'";
    $result_ext = $con->query($sql_ext);
    $capteurs_ext = array();
    while ($row_ext = $result_ext->fetch_assoc()) {
      $capteur_ext = array(
        "id" => $row_ext["IDCapteur"]
      );
      array_push($capteurs_ext, $capteur_ext);
    }
    unset($result_ext);
  } catch(PDOException $e) {
    die('Erreur lors de la requête pour les capteurs externes : ' . $e->getMessage());
  }

  // Fusionner les tableaux de capteurs internes et externes
  $capteurs = array_merge($capteurs_int, $capteurs_ext);

  // Retourner le tableau au format JSON
  echo json_encode($capteurs);
}
?>
