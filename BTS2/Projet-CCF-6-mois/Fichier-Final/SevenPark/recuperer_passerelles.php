<?php
include("connection.php");

try {
  // Récupérer le nombre de passerelles
  $sql = "SELECT COUNT(*) AS nb_passerelles FROM Passerelle";
  $result = $con->query($sql);
  $row = $result->fetch_assoc();
  $nb_passerelles = $row['nb_passerelles'];
  unset($result);
} catch(PDOException $e) {
  die('Erreur lors de la requête pour les passerelles : ' . $e->getMessage());
}

try {
  // Récupérer les données des passerelles
  $sql = "SELECT * FROM Passerelle";
  $result = $con->query($sql);
  $passerelles = array();
  while ($row = $result->fetch_assoc()) {
    $passerelle = array(
      "id" => $row["IDPasserelle"],
      "ip" => $row["AdresseIP"],
      "emplacement" => $row["Emplacement"],
      "NBCapteur" => $row["NBCapteur"],
      "Zone" => $row["Zone"]
    );
    array_push($passerelles, $passerelle);
  }
  unset($result);
} catch(PDOException $e) {
  die('Erreur lors de la requête pour les passerelles : ' . $e->getMessage());
}

// Retourner le tableau au format JSON
$resultPasserelle = array('nb_passerelles' => $nb_passerelles, 'passerelles' => $passerelles);
echo json_encode($resultPasserelle);
?>
