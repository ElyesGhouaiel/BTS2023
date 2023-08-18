<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Afficheur</title>
    <script src="javascript.js"></script>
    <link rel="stylesheet" href="style-afficheur.css">
    <style>
    table {
      border-collapse: collapse;
      width: 100%;
    }
    th, td {
      border: 1px solid black;
      padding: 8px;
      text-align: left;
    }
  </style>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
</head>
<body onload="CheckBox()">
    <div class="top-bar-container">
        <div class="top-bar-left">
            <div class="top-bar-logo-container"></div>
        </div>
        <div class="top-bar-right"></div>
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
<h1>Afficheur</h1>
    <div class="container">
        <div class="section">
            <input type="checkbox" id="customCheckbox" onclick="CheckBox()">
            <label for="customCheckbox" class="checkbox-label">Case à cocher avec texte personnalisé</label>
            <div class="dropdown" id="customDropdown">
                <textarea id="messageTextarea" oninput="limitTextareaLength(39)"></textarea>
            </div>
            <button class="submit-button" onclick="envoyerMessagePerso()">Envoyer le message personnalisé</button>
        </div>

        <div class="section">
            <input type="checkbox" id="definitCheckbox" onclick="CheckBox()">
            <label for="definitCheckbox" class="checkbox-label">Case à cocher pour le message Pré-enrgistré</label>
            <div class="dropdown" id="definitDropdown">
                <?php
                // Requête SQL pour récupérer les données de la table "Message_Register"
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

                // Requête SQL pour récupérer les données de la table "Message_Register"
                $sql = "SELECT Id_Message_Register,Contenu,Type FROM Message_Register";
                $result = $conn->query($sql);

                // Vérification des résultats de la requête
                if ($result->num_rows > 0) {
                    echo '<select name="messages" id="messages">';
                    while ($row = $result->fetch_assoc()) {
                        $id = $row['Id_Message_Register'];
                        $Contenu = $row['Contenu'];
                        $Type = $row['Type'];
                        echo '<option value="' . $id . '">' . $id . ' - ' . $Contenu . ' - ' . $Type . '</option>';
                    }
                    echo '</select>';
                } else {
                    echo 'Aucun résultat trouvé.';
                }

                ?>
            </div>
            <button class="submit-button" onclick="envoyerDonnees()">Envoyer un Message Pré-enregistrés</button>
        </div>
        <div class="table-container"></div>
    </div>
</body>
</html>
