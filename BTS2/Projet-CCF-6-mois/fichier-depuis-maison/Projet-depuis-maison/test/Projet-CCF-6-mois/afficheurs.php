<!DOCTYPE html>
<html>
<head>
    <title>Afficheurs</title>
</head>
<body>
    <h1>Afficheurs</h1>

    <!DOCTYPE html>
<html>
<head>
    <title>Afficheurs</title>
</head>
<body>
    <h1>Afficheurs</h1>

    <?php
    // Connexion à la base de données
    $servername = "192.168.1.72";
    $port = 3306;
    $username = "AfficheurUser";
    $password = "votre_mot_de_passe";
    $dbname = "bddprincipal";

    $conn = new mysqli($servername, $username, $password, $dbname, $port);

    if ($conn->connect_error) {
        die("La connexion a échoué : " . $conn->connect_error);
    }

    // Récupération des enregistrements de la table "afficheurs"
    $queryAfficheurs = "SELECT Id_Afficheurs, Contenu, Emplacement FROM afficheurs";
    $resultAfficheurs = $conn->query($queryAfficheurs);
    ?>

    <div>
        <label for="messageList">Message préenregistré :</label>
        <select id="messageList">
            <?php
            // Affichage des enregistrements de la table "afficheurs" dans la liste déroulante
            while ($rowAfficheurs = $resultAfficheurs->fetch_assoc()) {
                $idAfficheur = $rowAfficheurs["Id_Afficheurs"];
                $contenu = $rowAfficheurs["Contenu"];
                $emplacement = $rowAfficheurs["Emplacement"];
                echo "<option value='$idAfficheur'>$contenu - $emplacement</option>";
            }
            ?>
        </select>
    </div>

    <?php
    // Fermeture de la connexion à la base de données
    $conn->close();
    ?>

</body>
</html>


</body>
</html>
