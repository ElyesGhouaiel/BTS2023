<?php

//Sign up php code
session_start();

include("connection.php");
include("functions.php");

if ($_SERVER['REQUEST_METHOD'] == "POST") {
    // Something was posted
    $user = $_POST['user'];
    $password = $_POST['password'];

    if (!empty($user) && !empty($password) && !is_numeric($user)) {
        // Read from database
        $query = "SELECT * FROM Employes WHERE User = ? LIMIT 1";
        $stmt = mysqli_prepare($con, $query);
        mysqli_stmt_bind_param($stmt, 's', $user);
        mysqli_stmt_execute($stmt);
        $result = mysqli_stmt_get_result($stmt);

        if ($result && mysqli_num_rows($result) > 0) {
            $user_data = mysqli_fetch_assoc($result);
            // User already exists
            header("Location: signup.php?error=user_already_exists");
            die();
        }
        else {
            // Encrypt password
            $password = password_hash($password, PASSWORD_DEFAULT);

            // Insert into database
            $query = "INSERT INTO Employes (User, Password) VALUES (?, ?)";
            $stmt = mysqli_prepare($con, $query);
            mysqli_stmt_bind_param($stmt, 'ss', $user, $password);
            mysqli_stmt_execute($stmt);

            header("Location: login.php");
            die();
        }
    }
    else {
        // Invalid input
        header("Location: signup.php?error=invalid_input");
        die();
    }
}
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="Cache-Control" content="no-cache, no-store, must-revalidate">
    <meta http-equiv="Pragma" content="no-cache">
    <meta http-equiv="Expires" content="0">

    <title>Seven Park - Signup</title>
    <script src="javascript.js"></script>
    <link rel="stylesheet" href="style-login.css">
</head>
<body>
    <section>
        <div class="form-box">
            <div class="form-value">
                <form method="POST">
                    <h2>Sign Up</h2>
                    <div class="inputbox">
                        <ion-icon name="person-outline"></ion-icon>
                        <input type="text" name="user" required>
                        <label for="">User</label>
                    </div>
                    <div class="inputbox">
                        <ion-icon name="lock-closed-outline"></ion-icon>
                        <input type="password" name="password" required>
                        <label for="">Password</label>
                    </div>
                    <button class="button" name="submit">Sign Up</button>
                </form>
            </div>
        </div>
    </section>
    <script type="module" src="https://unpkg.com/ionicons@7.1.0/dist/ionicons/ionicons.esm.js"></script>
    <script nomodule src="https://unpkg.com/ionicons@7.1.0/dist/ionicons/ionicons.js"></script>
</body>
</html>