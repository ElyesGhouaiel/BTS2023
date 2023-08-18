<!DOCTYPE html>
<html>
<head>
    <title>Afficheur</title>
    <style>
        .container {
            display: flex;
        }

        .section {
            flex: 1;
            padding: 20px;
        }

        .checkbox-label {
            display: block;
            margin-bottom: 10px;
        }

        .dropdown {
            display: none;
            margin-top: 10px;
        }

        .submit-button {
            margin-top: 10px;
        }
    </style>
</head>
<body>
    <h1>Afficheur</h1>
    <div class="container">
        <div class="section">
            <input type="checkbox" id="customCheckbox">
            <label for="customCheckbox" class="checkbox-label">Case à cocher avec texte personnalisé</label>
            <div class="dropdown" id="customDropdown">
                <select>
                    <option value="Personnalisé">Personnalisé</option>
                </select>
                <textarea></textarea>
            </div>
            <button class="submit-button">Envoyer</button>
        </div>

        <div class="section">
    <input type="checkbox" id="definitCheckbox">
    <label for="definitCheckbox" class="checkbox-label">Case à cocher Définitif</label>
    <div class="dropdown" id="definitDropdown">
        <select>
        <?php
    // Informations de connexion à la base de données
    $servername = '192.168.1.72';
    $port = 3306;
    $username = 'AfficheurUser';
    $password = 'Azerty77afficheur';
    $dbname = 'bddprincipal';

    // Connexion à la base de données
    $conn = new mysqli($servername, $username, $password, $dbname);

    // Vérification de la connexion
    if ($conn->connect_error) {
        die("Connexion échouée : " . $conn->connect_error);
    }

    // Requête SQL pour récupérer les données de la table "afficheurs"
    $sql = "SELECT Id_Afficheurs, Contenu, Emplacement FROM afficheurs";
    $result = $conn->query($sql);

    // Vérification des résultats de la requête
    if ($result->num_rows > 0) {
        // Création de la liste déroulante HTML
        echo '<select name="messages" id="messages">';
        while ($row = $result->fetch_assoc()) {
            $id = $row['Id_Afficheurs'];
            $contenu = $row['Contenu'];
            $emplacement = $row['Emplacement'];
            echo '<option value="' . $id . '">' . $contenu . ' - ' . $emplacement . '</option>';
        }
        echo '</select>';
    } else {
        echo 'Aucun résultat trouvé.';
    }

    // Fermeture de la connexion à la base de données
    $conn->close();
    ?>
        </select>
    </div>
    <button class="submit-button">Envoyer</button>
</div>

    
    <script>
        var customCheckbox = document.getElementById('customCheckbox');
        var customDropdown = document.getElementById('customDropdown');
        var definitCheckbox = document.getElementById('definitCheckbox');
        var definitDropdown = document.getElementById('definitDropdown');

        customCheckbox.addEventListener('change', function () {
            if (this.checked) {
                customDropdown.style.display = 'block';
            } else {
                customDropdown.style.display = 'none';
            }
        });

        definitCheckbox.addEventListener('change', function () {
            if (this.checked) {
                definitDropdown.style.display = 'block';
            } else {
                definitDropdown.style.display = 'none';
            }
        });
    </script>
</body>
</html>
