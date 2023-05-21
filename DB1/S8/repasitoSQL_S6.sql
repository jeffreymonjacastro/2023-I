CREATE SCHEMA repasitoSQL;
SET search_path TO repasitoSQL;

/* REPASITO GOD */
-- Cargando Data
-- Base de datos de la asesoría de ACL Valeria Espinoza

/* RECOMENDACIONES */
-- No olvidar el ; después de cada consulta
-- Escribir las tablas y sus atributos en minúscula
-- Escribir el código SQL en MAYÚSCULA (para diferenciar)
-- El renombramiento de las tablas debe tener una letra en mayúscula seguida de un punto

/* FORMA BÁSICA DE UNA CONSULTA EN SQL

   SELECT atributo1, atributo2...
   FROM tabla1, tabla2....
   WHERE condición1 AND/OR condición2...

*/

/* SELECT */
-- La sentencia SELECT permite recuperar información de la BD.

-- Proyectar toda la tabla
SELECT *
FROM album;

-- Proyectar algunos atributos
SELECT nombre, cnombre
FROM album;

-- Proyectar con una condición
SELECT nombre, cnombre, genero
FROM album
WHERE cnombre = 'Taylor Swift';

-- Proyectar con condiciones
SELECT nombre, cnombre, fechalanzamiento
FROM album
WHERE cnombre = 'Bad Bunny'
AND fechalanzamiento > '2019-01-01';

/* DISTINCT */
-- OJO: SQL rompe las reglas del álgebra relacional a veces, por ejemplo, para
-- permitir duplicados, orden, extensiones

SELECT cnombre
FROM album; -- En esta consulta hay 70 tuplas (Con repeticiones)

SELECT DISTINCT cnombre
FROM album; -- En esta otra solo hay 53 (Distintos)

/* ORDERED BY */
-- Ordenar la consulta
SELECT *
FROM album
ORDER BY fechalanzamiento; -- De menor a mayor

SELECT *
FROM album
ORDER BY fechalanzamiento DESC; -- De mayor a menor

/* JOIN (simple) */
-- Se puede realizar join seleccionando las tablas por comas

-- Aquí se realiza un producto cruz
SELECT cnombre, paisorigen
FROM album, cantante;

-- Aquí se realiza un tipo INNER JOIN
-- se le pone el nombre de la tabla seguido de un punto para evitar ambiguedades
SELECT DISTINCT cnombre, paisorigen
FROM album, cantante
WHERE album.cnombre = cantante.nombre
AND fechalanzamiento > '2020-01-01';

/* ALIAS */
-- Es como un renombramiento de la consulta
-- También se puede renombrar las tablas colocando una letra mayúscula
-- Facilita el JOIN's de tablas

SELECT DISTINCT A.cnombre AS cantante, C.paisorigen AS pais
FROM album A, cantante C
WHERE A.cnombre = C.nombre;

--> Los pares de nombres de álbumes con el mismo sello discográfico
SELECT A1.nombre AS n_album1, A2.nombre AS n_album2
FROM album A1, album A2
WHERE A1.sellodiscografico = A2.sellodiscografico;

/* UNIÓN */
-- Une el resultado de dos consultas

SELECT nombre
FROM cantante
UNION -- Unión normal, respeta el álgebra relacional
SELECT cnombre
FROM album;

SELECT nombre
FROM cantante
UNION ALL -- No respeta el álgebra relacional, junta todo
SELECT cnombre
FROM album;

/* EXCEPT (Diferencia) */
-- Se restan los resultados de las consultas

--> Cantantes menores de 30 años que no hagan música Pop
SELECT nombre
FROM cantante
WHERE fechanacimiento > '1993-01-01'
EXCEPT
SELECT cnombre
FROM album
WHERE genero = 'Pop';

/* INTERSECT */
-- Elementos en común entre las consultas

--> Cantantes menores a 30 años que cantan Pop
SELECT nombre
FROM cantante
WHERE fechanacimiento > '1993-01-01'
INTERSECT
SELECT cnombre
FROM album
WHERE genero = 'Pop';

/* LIKE (Patrones simples) */
-- Patrones de string, puede tomar más de un carácter

--> Cantantes con una letra 'A' al inicio de su nombre
SELECT nombre
FROM cantante
WHERE nombre LIKE 'A%';

--> Cantantes que su nombre no termine en 'e'
SELECT nombre
FROM cantante
WHERE nombre NOT LIKE '%e';

/* IN */
-- Consultas que pertenencen a un conjunto

--> Nombre de los albumes que pertenezcan a los cantantes BM, ES y TS
SELECT nombre
FROM album
WHERE cnombre IN ('Bruno Mars', 'Ed Sheeran', 'Taylor Swift');

/* BETWEEN */
-- Consultas entre un rango o intervalo

--> Nombre y cantante de los álbumes donde su duración esté entre 200 y 300
SELECT nombre, cnombre
FROM album
WHERE duracion BETWEEN 200 AND 300;

/* JOINS INTERNOS */

/* CROSS JOIN (CRUZ)*/
-- Realiza un producto Todos con todos

SELECT C.nombre, A.nombre
FROM album A
CROSS JOIN cantante C;

/* EQUI JOIN */
-- Se utiliza el 'ON' para declarar la condición del join

SELECT C.nombre, A.nombre, genero, numerocanciones
FROM album A
JOIN cantante C
ON A.cnombre = C.nombre;

/* JOIN (USING) */
-- Cuando hay un atributo con el mismo nombre en ambas tablas

/*
SELECT *
FROM album
JOIN cantante USING (nombre)
*/

/* NATURAL JOIN */
-- Igual que el JOIN con USING

/*
SELECT *
FROM album
NATURAL JOIN cantante;
*/

/* SELF JOIN */
-- JOIN entre la tabla misma

--> Pares de albumes con el mismo sello discográfico pero diferente nombre
SELECT A1.nombre AS n_album1, A2.nombre AS n_album2
FROM album A1
JOIN album A2
ON A1.sellodiscografico = A2.sellodiscografico
AND A1.nombre <> A2.nombre; -- Diferente !

/* INNER JOIN */
-- Es el JOIN por defecto

SELECT C.nombre, A.nombre, genero, numerocanciones
FROM album A
INNER JOIN cantante C
ON A.cnombre = C.nombre;


/* JOINS EXTERNOS */

/* LEFT JOIN */
-- Se conservan todas los atributos de la tabla de la izquierda y su intersección

SELECT *
FROM videomusical V
LEFT JOIN album A
ON V.cantante = A.cnombre;

/* RIGHT JOIN */
-- Se conservan los atributos de la tabla de la derecha y su intersección

SELECT *
FROM videomusical V
RIGHT JOIN album A
ON V.cantante = A.cnombre;

/* FULL OUTHER JOIN / FULL JOIN */
-- Se conservan todos los atributos de las tablas

SELECT *
FROM videomusical V
FULL OUTER JOIN album A
ON V.cantante = A.cnombre;

/* NULL VALUES */
-- Son valores desconocidos, no falsos

SELECT nombre
FROM videomusical
WHERE duracion IS NULL; -- Dato null

SELECT nombre
FROM videomusical
WHERE duracion IS NOT NULL; -- Dato no null

/* COALESCE */
-- Transforma los valores null en un valor por defecto

SELECT nombre, COALESCE(duracion, '0') AS duration
FROM videomusical;

/* CONSULTAS ANIDADAS */
-- Las subconsultas deben tener la misma cantidad de atributos con los que se está
-- comparando en la consulta principal, además de estar relacionadas

/* WHERE/IN */

--> Los videos musicales donde el cantante tenga más de 33 años
SELECT nombre, cantante
FROM videomusical
WHERE cantante IN (
    SELECT nombre
    FROM cantante
    WHERE fechanacimiento < '1990-01-01'
    );

/* WHERE/NOT IN */

--> Videos musicales de los cantantes que tengan menos de 33 años
SELECT nombre, cantante
FROM videomusical
WHERE cantante NOT IN (
    SELECT nombre
    FROM cantante
    WHERE fechanacimiento < '1990-01-01'
    );

--> Videos musicales de los cantantes que tengan menos de 33 años o que sus álbumes
-- tengan más de 10 canciones
SELECT *
FROM videomusical
WHERE cantante NOT IN (
    SELECT nombre
    FROM cantante
    WHERE fechanacimiento < '1990-01-01' OR nombre IN (
        SELECT cnombre
        FROM album
        WHERE numerocanciones > 10
        )
    );

/* WHERE/EXISTS */
-- Se realiza la consulta en base a lo que existe en la subconsulta


SELECT nombre, cnombre
FROM album A
WHERE EXISTS (
    SELECT *
    FROM ventas V
    WHERE precio > 30 AND V.aid = A.aid
);

/* WHERE/NOT EXIST */


SELECT nombre, cnombre
FROM album A
WHERE NOT EXISTS (
    SELECT *
    FROM ventas V
    WHERE precio > 30 AND V.aid = A.aid
);

/* WHERE/ANY O SOME */
-- Compara un valor con una lista de valores y devolver true si
-- se cumple la condición AL MENOS para uno de los valores de la lista.

SELECT *
FROM ventas V1
WHERE precio > ANY (
    SELECT precio
    FROM ventas V2
    WHERE precio > 30
    );

/* WHERE ALL */
-- Compara un valor con toda la lista y devuelve true si se cumple la condición
-- para TODOS los valores de la lista

SELECT *
FROM ventas V1
WHERE precio > ALL (
    SELECT precio
    FROM ventas V2
    WHERE precio < 35
    );

/* Anidadas por el FROM */
-- Se hace una subconsulta que devuelve una tabla
-- Es obligatorio el renombramiento

SELECT miniAlbum.nombre, miniAlbum.cnombre, C.paisorigen
FROM (
    SELECT nombre, cnombre
    FROM album
    WHERE numerocanciones < 12
) miniAlbum
JOIN cantante C
ON miniAlbum.cnombre = C.nombre;

/* OPERADORES DE AGREGACIÓN */
-- No se pueden devolver más de un atributo al utilizar agregación
-- Para devolver más de un atributo se debe utilizar operadores de agregación


/* COUNT */
-- Cuenta la cantidad de repeticiones

-- Cuenta todos los cnombres
SELECT COUNT(cnombre) AS conteo
FROM album;

-- Cuenta todos los cnombres DISTINTOS
SELECT COUNT(DISTINCT cnombre) AS conteo
FROM album;

-- Cuenta todas las filas
SELECT COUNT(*) AS conteo
FROM album;

/* AVG */
-- Promedio, psql muestra en decimal

-- Promedio de todos los precios
SELECT AVG(precio) AS promedio
FROM ventas;

-- Promedio de los precios distintos
SELECT AVG(DISTINCT precio) AS promedio
FROM ventas;

-- Casting para cambiar a entero
SELECT AVG(CAST(precio AS INTEGER)) AS promedio
FROM ventas;

/* MIN */
-- Mínimo

SELECT MIN(precio) AS minimo
FROM ventas;

/*
   AGREGACIÓN POR GROUP BY/HAVING

   El uso correcto de los operadores de agregación es:

   SELECT col1, col2, función_agregación(col3)
   FROM tabla
   GROUP BY col1, col2
   HAVING cond1, cond2
*/

SELECT cnombre, COUNT(*) AS conteo
FROM album
GROUP BY cnombre
HAVING COUNT(*) > 1;

--> El promedio de precio de ventas de cada álbum con la condición
-- que se halla vendido a menos de 50
SELECT cnombre, AVG(CAST(precio AS INTEGER)) AS promedio
FROM ventas V
JOIN album A
ON V.aid = A.aid
GROUP BY cnombre
HAVING MAX(precio) < 50;

/* HAVING EVERY */
SELECT cnombre, AVG(CAST(precio AS INTEGER)) AS promedio
FROM ventas V
JOIN album A
ON V.aid = A.aid
GROUP BY cnombre
HAVING EVERY(precio BETWEEN 10 AND 50);

/* HAVING ANY */
-- En Postgres es bool_or

SELECT cnombre, substr(cnombre, 1, 1) AS inicial, ROUND(AVG(CAST(precio AS INTEGER))) AS promedio, SUM(precio) AS Total, COUNT(*) AS cantidad
FROM ventas V
JOIN album A
ON V.aid = A.aid
GROUP BY cnombre, A.nombre
HAVING bool_or(A.fechalanzamiento BETWEEN '2019-01-01' AND '2022-01-01');


/* FETCH FIRST */
-- Devuelve n resultados

SELECT *
FROM album
ORDER BY fechalanzamiento DESC
FETCH FIRST 5 ROWS ONLY;

/* LIMIT */

SELECT *
FROM album
ORDER BY fechalanzamiento DESC
LIMIT 3;

/* ROW_NUMBER() */
-- Asigna un número a cada fila
-- REPASAR
/*
SELECT cnombre, fechalanzamiento, ROW_NUMBER() OVER (PARTITION BY cnombre ORDER BY fechalanzamiento) AS num_secuencial
FROM album
GROUP BY cnombre, fechalanzamiento;
*/


/* RANK() */
-- Asigna un número a cada fila, pero si hay empate, se salta el siguiente número

/* MÁS FUNCIONES */

/* ABS() */
-- Valor absoluto

/* CEIL() */
-- Redondea hacia arriba

/* FLOOR() */
-- Redondea hacia abajo

/* EXP() */
-- Exponencial

/* ROUND() */
-- Redondea

/* SQRT() */
-- Raíz cuadrada

/* LOWER() */
-- Convierte a minúscula

/* UPPER() */
-- Convierte a mayúscula

/* TRIM() */
-- Elimina espacios en blanco al inicio y al final

/* SUBSTRING() */
-- Extrae una subcadena

/* STARSWITH() */
-- Devuelve true si la cadena empieza con el patrón

---Y MÁS....

/* CASE */
SELECT DISTINCT cnombre, substr(cnombre, 1, 1) AS nombre, AVG(numerocanciones) AS promedio,
        CASE
            WHEN cnombre = 'Maluma' THEN 'Colombiano'
            WHEN cnombre = 'Ed Sheeran' THEN 'UK'
            ELSE 'Otros'
        END AS nacionalidad
FROM album
GROUP BY cnombre ;


SELECT cnombre, genero,
        CASE
            WHEN cnombre = 'Maluma' THEN 'Colombiano'
            WHEN cnombre = 'Ed Sheeran' THEN 'UK'
            ELSE 'Otros'
        END AS nacionalidad,  AVG(numerocanciones) AS promedio
FROM album
GROUP BY 1,2
