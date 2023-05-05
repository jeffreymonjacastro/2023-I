/* PRACTICA LABO 6.1 */

-- PREGUNTA 1
SELECT nombre, anho
FROM pelicula
ORDER BY calificacion DESC, nombre, anho
LIMIT 10;

-- PREGUNTA 2
SELECT *
FROM personaje
WHERE EXISTS (SELECT *
              FROM (SELECT *
                    FROM pelicula
                    ORDER BY calificacion DESC, nombre, anho
                    LIMIT 10) Top10
              WHERE nombre = p_nombre AND anho = p_anho
              )
              AND a_nombre IN (
                  SELECT nombre
                  FROM actor
                  WHERE genero = 'F'
              );

-- PREGUNTA 3
SELECT COUNT(nombre)
FROM actor
WHERE genero = 'M';

-- PREGUNTA 4
SELECT COUNT(DISTINCT anho)
FROM pelicula;


-- PREGUNTA 5
SELECT a_nombre, COUNT( DISTINCT (p_nombre, p_anho)) as conteo
FROM personaje
GROUP BY a_nombre
HAVING COUNT(DISTINCT (p_nombre, p_anho)) > 1
ORDER BY conteo DESC;

-- PREGRUNTA 6


-- PREGUNTA 7
SELECT anho, anho%10
FROM pelicula