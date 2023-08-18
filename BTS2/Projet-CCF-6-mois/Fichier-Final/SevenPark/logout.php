<?php
  session_start();

  // Vérifier si l'utilisateur est connecté
  if(isset($_SESSION['user_id']))
  {
    // Détruire la session
    session_unset();
    session_destroy();
  }
  header("Location: login.php");
  exit();
?>