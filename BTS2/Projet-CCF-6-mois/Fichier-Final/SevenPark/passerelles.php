<?php
    session_start();
    include("connection.php");
    include("functions.php");

    // Vérifier si l'utilisateur est connecté
    if(!isset($_SESSION['user_id']))
    {
      header("Location: login.php");
      die;
    }
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Passerelles</title>
    <script src="javascript.js"></script>
    <link rel="stylesheet" href="style-passerelles.css">
</head>
<body onload="mettreAJourPasserelles()">
    <div class="top-bar-container">
        <div class="top-bar-left">
            <div class="top-bar-logo-container"></div>
        </div>
        <div class="top-bar-right">
            <button id="logout" onclick="logout()"></button>
        </div>
    </div>

    <div class="navbar">
        <div class="navbar__menu">
            <ul>
                <li><a href="dashboard.php">Dashboard</a></li>
                <li><a href="passerelles.php">Passerelles</a></li>
                <li><a href="capteur.php">Capteur</a></li>
                <li><a href="capteurEnv.php">Capteur Environnemental</a></li>
                <li><a href="afficheur.php">Afficheur</a></li>
            </ul>
        </div>
    </div>

    <div class="switch-container">
        <input type="checkbox" onchange="toggleTheme()" id="switch" />
        <label for="switch"></label>
    </div>

    <div class="overview-container">
        <p>Passerelles</p>
    </div>

    <div class="passerelles-container"></div>

    <!-- Overlay pour afficher les données de la passerelle -->
    <div class="overlay">
        <div class="overlay-content">
        <div class="passerelle-data"></div>
        </div>
    </div>
 
</body>
</html>