<?php

$db_host = "localhost";
$db_user = "root";
$db_password = "admin";
$db_name = "BDDPrincipal";

if(!$con = mysqli_connect($db_host, $db_user, $db_password, $db_name))
{
    die("Failed to connect to MySQL: " . mysqli_connect_error());
}

?>