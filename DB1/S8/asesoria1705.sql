CREATE SCHEMA asesoria1705;

SET search_path = asesoria1705;

-- Creación de la tabla Cantante
CREATE TABLE Cantante (
	Nombre VARCHAR(50) PRIMARY KEY,
	Sexo CHAR(1) NOT NULL,
	FechaNacimiento DATE,
    PaisOrigen VARCHAR(50)
);

-- Creación de la tabla Álbum
CREATE TABLE Album (
    Aid INT PRIMARY KEY,
    Nombre VARCHAR(50) NOT NULL,
    CNombre VARCHAR(50) NOT NULL,
    FechaLanzamiento DATE,
    Genero VARCHAR(50),
    Duracion INT,
    NumeroCanciones INT,
    SelloDiscografico VARCHAR(50),
	FOREIGN KEY (CNombre) REFERENCES Cantante(Nombre)
);

-- Creación de la tabla Usuarios
CREATE TABLE Usuarios (
    Uid INT PRIMARY KEY,
    Nombre VARCHAR(50) NOT NULL,
    Correo VARCHAR(50) NOT NULL,
    FechaRegistro DATE
);

-- Creación de la tabla Ventas
CREATE TABLE Ventas (
    Vid INT PRIMARY KEY,
    Uid INT,
    Aid INT,
    FechaVenta DATE,
    Cantidad INT,
    Precio DECIMAL(10, 2),
    FOREIGN KEY (Uid) REFERENCES Usuarios (Uid),
    FOREIGN KEY (Aid) REFERENCES Album (Aid)
);


-- PREGUNTA 1
-- Obtener el nombre del cantante y la cantidad total de álbumes lanzados por cada uno
-- en la plataforma

SELECT C.nombre, COUNT(*) AS TotalAlbumes
FROM cantante C
INNER JOIN Album A ON C.nombre = A.cnombre
GROUP BY C.nombre;

-- PREGUNTA 2
-- Obtener el nombre del álbum, la cantidad de ventas y el total de ingresos generados
-- por cada álbum, ordenados por el total de ingresos en orden descendente.

SELECT A.Nombre, SUM(V.Cantidad) AS CantidadVentas, SUM(V.Cantidad * V.Precio) AS TotalIngresos
FROM Album A
JOIN Ventas V on A.Aid = V.Aid
GROUP BY A.nombre
ORDER BY TotalIngresos DESC;

-- PREGUNTA 3
-- Obtener el nombre del cantante y el promedio de duración de sus álbumes, solo para
-- aquellos cantantes cuyo promedio de duración sea superior a 200.

SELECT C.nombre, AVG(A.duracion) AS PromDuracion
FROM cantante C
JOIN album A ON C.Nombre = A.CNombre
GROUP BY C.Nombre
HAVING AVG(A.duracion) > 200
ORDER BY PromDuracion DESC;

-- PREGUNTA 4
-- Mostrar el top 5 de meses con su respectivo año que tienen más ventas.

SELECT EXTRACT(MONTH FROM FechaVenta) AS Mes, EXTRACT(YEAR FROM FechaVenta) AS Año, SUM(Cantidad) AS TotalVentas
FROM Ventas
GROUP BY Mes, Año
ORDER BY TotalVentas DESC
LIMIT 5;

-- PREGUNTA 5
-- Obtener el nombre de los cantantes y el número de usuarios distintos que han comprado
-- al menos uno de sus álbumes, ordenado de forma descendente por este número.

SELECT C.nombre, COUNT(DISTINCT V.uid) AS NumUsuarios
FROM cantante C
JOIN Album A ON C.Nombre = A.CNombre
JOIN ventas V ON A.Aid = V.Aid
GROUP BY C.nombre
ORDER BY NumUsuarios DESC;

-- PREGUNTA 6
-- Mostrar aquellos artistas que no hayan recibido ventas en los últimos 3 meses

SELECT C.nombre
FROM cantante C
WHERE NOT EXISTS(
    SELECT *
    FROM Album A
    INNER JOIN Ventas V on A.Aid = V.Aid
    WHERE C.nombre = A.cnombre AND V.FechaVenta >= (CURRENT_DATE - INTERVAL '3 months')
);

-- PREGUNTA 7
-- Mostrar el top 10 de las cantantes femeninas con más ventas.

SELECT C.nombre, SUM(V.cantidad) AS TotalVentas
FROM cantante C
INNER JOIN Album A on C.Nombre = A.CNombre
INNER JOIN Ventas V on A.Aid = V.Aid
WHERE C.sexo = 'F'
GROUP BY C.nombre
ORDER BY TotalVentas DESC
LIMIT 10;

-- PREGUNTA 8
-- Mostrar el top 2 de los usuarios que hayan comprado más álbumes de Jennie.

SELECT U.nombre, SUM(V.Cantidad) AS TotalCompras
FROM usuarios U
INNER JOIN Ventas V on U.Uid = V.Uid
INNER JOIN (
    SELECT aid
    FROM album
    WHERE CNombre = 'Jennie'
) AS A ON V.aid = A.Aid
GROUP BY U.uid, U.nombre
ORDER BY TotalCompras DESC
LIMIT 2;

-- PREGUNTA 9
-- Mostrar los álbumes que hayan sido comprados por al menos 5 usuarios diferentes,
-- mostrar dicha cantidad y el mes de la última venta con su respectivo año.

SELECT A.nombre, COUNT(DISTINCT v.uid) AS TotalUsuarios, TO_CHAR(MAX(V.fechaVenta), 'Month YYYY') AS UltimaVenta
FROM Album A
INNER JOIN Ventas V on A.Aid = V.Aid
GROUP BY A.Aid, A.nombre
HAVING COUNT(DISTINCT v.uid) > 4;

-- PREGUNTA 10
-- Mostrar los nombres de usuarios que hayan comprado al menos un album de un artista
-- femenino y al menos uno de un artista masculino, y que estos dos sean de géneros
-- musicales distintos. Agruparlo por el año en el que se registraron dichos usuarios.

SELECT U.nombre, EXTRACT(YEAR FROM U.fechaRegistro) AS AnioRegistro
FROM usuarios U
INNER JOIN ventas VF ON U.Uid = VF.Uid
INNER JOIN album AF ON VF.Aid = AF.aid
INNER JOIN cantante CF ON AF.cnombre = CF.nombre AND CF.sexo = 'F'
WHERE EXISTS(
    SELECT 1
    FROM ventas VM
    INNER JOIN album AM ON VM.Aid = AM.Aid
    INNER JOIN cantante CM ON AM.cnombre = CM.nombre AND CM.sexo = 'M' AND AM.genero <> AF.genero
    WHERE U.uid = VM.uid
)
GROUP BY AnioRegistro, U.nombre
ORDER BY AnioRegistro DESC;

-- PREGUNTA 11
-- Ordenar de manera descendente a los usuarios que hayan gastado más que el promedio
-- en los últimos 12 meses en álbumes cuya fecha de lanzamiento fue a partir del año
-- 2021.

