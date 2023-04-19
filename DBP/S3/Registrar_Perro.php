<?php
//conexion a la Base de datos (Servidor,usuario,password)
$link = mysqli_connect("localhost", "root","");
mysqli_select_db($link, "pets");
//capturando datos
$v1 = $_REQUEST['Codigo'];
$v2 = $_REQUEST['Nombre'];
$v3 = $_REQUEST['FechNac'];
$v4 = $_REQUEST['Raza'];
$v5 = $_REQUEST['Genero'];
$v6 = $_REQUEST['Foto'];
//conuslta SQL
$sql = "INSERT INTO perros (DNI, Nombre, Raza, Genero, FechaNacimiento, Foto) ";
$sql .= "VALUES ('$v1', '$v2', '$v4', '$v5', '$v3', '$v6' )";
$result = mysqli_query($link, $sql);
//Mensaje de conformidad
echo "<p>Ok, datos ingresados </p>";
?>