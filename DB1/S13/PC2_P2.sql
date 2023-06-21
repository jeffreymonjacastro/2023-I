/* Muestre los estudiantes que son de Ciencia de la Computación */
SELECT * FROM estudiante WHERE carrera = 'Ciencia de la Computación';

/* Muestre los estudiantes que ocupan el segundo lugar en el ranking
   de la cantidad de libros que se prestaron */

SELECT E.dni, E.nombres, R.cantidad
FROM persona E
JOIN (
    SELECT P.dni, COUNT(P.numero) as cantidad
    FROM prestamo P
    JOIN detalleprestamo D on P.numero = D.pnumero
    GROUP BY P.dni
) R ON E.dni = R.dni
ORDER BY cantidad DESC;


SELECT P.dni , P.nombres, R.cantidad
FROM persona P JOIN (
    SELECT P.dni , count(numero) as cantidad
    FROM prestamo P
    JOIN detalleprestamo d on P.numero = d.pnumero
    GROUP BY P.dni
    HAVING (
        count(numero) = (
            SELECT max(cantidad)
            FROM (
                SELECT pnumero , count(pnumero) as cantidad
                FROM detalleprestamo
                GROUP BY pnumero
                HAVING (
                    count(pnumero) != (
                    SELECT max(cantidad)
                    FROM (
                        SELECT pnumero , count(pnumero) as cantidad
                        FROM detalleprestamo
                        GROUP BY pnumero
                        ORDER BY cantidad DESC
                        ) T
                    )
                )
            ) R
        )
    )
) R ON P.dni =  R.dni
ORDER BY P.nombres
