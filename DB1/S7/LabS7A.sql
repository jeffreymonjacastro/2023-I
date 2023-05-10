/*GUIA LAB 6.2*/
/* PREGUNTA 1 */

-- Primera forma
SELECT *
FROM arrienda
    NATURAL JOIN arrendatario
    NATURAL JOIN casa
WHERE calle = '714-8965 Sem Avenue' AND distrito = 'Iqaluit';

-- Segunda forma

SELECT dni_a, nombre, apellidos
FROM arrendatario
WHERE dni_a in(
            SELECT dni_a
            FROM arrienda
            WHERE id_casa in(
                        SELECT id_casa
                        FROM casa
                        WHERE calle = '714-8965 Sem Avenue' AND distrito = 'Iqaluit'
                        )
            );

/* PREGUNTA 2 */


/* PREGUNTA 3 */
SELECT dni_d, deuda
FROM casa C NATURAL JOIN (
                SELECT id_casa, SUM(deuda) AS deuda
                FROM arrienda
                GROUP BY (id_casa)
) NUEVATABLA;

/* PREGUNTA 4
   Lista de todas las personas en la base de datos*/

SELECT dni_d
FROM dueno

