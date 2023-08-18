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
    <title>Capteur</title>
    <script src="javascript.js"></script>
    <link rel="stylesheet" href="style-capteur.css">
</head>
<body>
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
        <input type="checkbox" class="theme-light" onchange="toggleTheme()" id="switch" />
        <label for="switch"></label>
    </div>

    <div class="overview-container">
        <p>Capteur</p>
        <div class="dropdown-container">
            <select id="dropdown1" onchange="toggleDropdown1()">
                <option disabled selected>Sélectionnez une Passerelle</option>
                <?php
                include("connection.php");

                try {
                // Récupérer les données des passerelles
                $sql = "SELECT * FROM Passerelle";
                $result = $con->query($sql);
                while ($row = $result->fetch_assoc()) {
                    echo '<option value="' . $row["IDPasserelle"] . '">Passerelle : ' . $row["Emplacement"] . ' | Zone : ' . $row["Zone"] . '</option>';
                }
                unset($result);
                } catch(PDOException $e) {
                die('Erreur lors de la requête pour les passerelles : ' . $e->getMessage());
                }
                ?>
            </select>
            <select id="dropdown2" onchange="toggleDropdown2()">
                <option disabled selected>Sélectionnez un Capteur</option>
            </select>
        </div>
        <div id="info-container" class="info-container">
            <!-- Contenu de la zone d'informations -->
        </div>
    </div>
</body>
</html>