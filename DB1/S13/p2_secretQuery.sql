-- Muestre los libros de "base de datos" que fueron prestados más de una vez entre 2018 y 2023, Sin USAR JOUN ni BETWEEN

SELECT * FROM libro;
SELECT * FROM edicion;
SELECT * FROM detalleprestamo;


SELECT *
FROM libro
JOIN autor a on libro.dni = a.dni
JOIN edicion e on libro.nombre = e.nombre
JOIN detalleprestamo d on e.isbn = d.isbn
WHERE d.pnumero IN (
    SELECT D.pnumero
    FROM detalleprestamo D
    GROUP BY D.pnumero
    HAVING COUNT(*) > 1
) AND a.especialidad = 'Base de datos'

SELECT *
FROM autor A
JOIN libro l on A.dni = l.dni
WHERE A.especialidad = 'Base de datos'




SELECT D.pnumero, COUNT(*)
FROM detalleprestamo D
GROUP BY D.pnumero
HAVING COUNT(*) > 1;

SELECT D.pnumero, D.isbn
FROM detalleprestamo D
WHERE D.pnumero IN (
    SELECT D1.pnumero
    FROM detalleprestamo D1
    GROUP BY D1.pnumero
    HAVING COUNT(*) > 1
    )

SELECT E.nombre
FROM edicion E
WHERE E.isbn IN (
    SELECT D.isbn
    FROM detalleprestamo D
    WHERE D.pnumero IN (
        SELECT D1.pnumero
        FROM detalleprestamo D1
        GROUP BY D1.pnumero
        HAVING COUNT(*) > 1
        )
    )

SELECT L.dni
FROM libro L
WHERE L.nombre IN (
    SELECT E.nombre
    FROM edicion E
    WHERE E.isbn IN (
        SELECT D.isbn
        FROM detalleprestamo D
        WHERE D.pnumero IN (
            SELECT D1.pnumero
            FROM detalleprestamo D1
            GROUP BY D1.pnumero
            HAVING COUNT(*) > 1
            )
        )
    )

SELECT A.dni
FROM autor A
WHERE A.dni IN (
    SELECT L.dni
    FROM libro L
    WHERE L.nombre IN (
        SELECT E.nombre
        FROM edicion E
        WHERE E.isbn IN (
            SELECT D.isbn
            FROM detalleprestamo D
            WHERE D.pnumero IN (
                SELECT D1.pnumero
                FROM detalleprestamo D1
                GROUP BY D1.pnumero
                HAVING COUNT(*) > 1
                )
            )
        )
    )
AND A.especialidad = 'Base de datos'

SELECT L.nombre
FROM libro L
WHERE L.dni IN (
    SELECT A.dni
    FROM autor A
    WHERE A.dni IN (
        SELECT L.dni
        FROM libro L
        WHERE L.nombre IN (
            SELECT E.nombre
            FROM edicion E
            WHERE E.isbn IN (
                SELECT D.isbn
                FROM detalleprestamo D
                WHERE D.pnumero IN (
                    SELECT D1.pnumero
                    FROM detalleprestamo D1
                    GROUP BY D1.pnumero
                    HAVING COUNT(*) > 1
                    )
                )
            )
        )
    AND A.especialidad = 'Base de datos'
)