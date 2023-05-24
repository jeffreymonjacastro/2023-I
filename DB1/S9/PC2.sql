-- CREATE SCHEMA PC2_2023_I_Teofilo;
-- SET search_path TO PC2_2023_I_Teofilo;

/* COLOCANDO DATA */
-- Gist:
-- https://gist.github.com/tchambil/8614fd7ccc089c8c822976c2aa0cde61


/* Querys */

-- a)
-- 1. Tabla inhabilitado
CREATE TABLE inhabilitado (
    dni_estudiante INTEGER,
    tiempo_inhab DATE
);

ALTER TABLE inhabilitado ADD CONSTRAINT inhabilitado_pk_dni PRIMARY KEY (dni_estudiante);
ALTER TABLE inhabilitado ADD CONSTRAINT inhabilitado_fk_dni FOREIGN KEY (dni_estudiante) REFERENCES estudiante(dni);

-- 2. TRIGGERS
CREATE OR REPLACE FUNCTION fncInhabilitar()
RETURNS TRIGGER AS
$$
    BEGIN
        IF ((365 * DATE_PART('year', AGE(NEW.fdevolucion,NEW.fprestamo))) +
            (30 * DATE_PART('month', AGE(NEW.fdevolucion,NEW.fprestamo)) +
             DATE_PART('day', AGE(NEW.fdevolucion,NEW.fprestamo))) > 7)
        THEN
            INSERT INTO inhabilitado VALUES
            (NEW.dni, NEW.fprestamo + INTERVAL '4 MONTH');
        END IF;

        RETURN NEW;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_inhabilitar
AFTER UPDATE ON prestamo
FOR EACH ROW EXECUTE PROCEDURE fncInhabilitar();

UPDATE prestamo
SET fdevolucion = CURRENT_DATE
WHERE numero = 58;


CREATE OR REPLACE FUNCTION fncPrestarLibro()
RETURNS TRIGGER AS
$$
    BEGIN
        IF EXISTS(
            SELECT *
            FROM inhabilitado I
            JOIN prestamo P ON I.dni_estudiante = P.dni
        )
        THEN
            RAISE NOTICE 'No se puede prestar el libro';
        ELSE
            RAISE NOTICE 'Si se puede prestar el libro';
        END IF;
        RETURN NULL;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_PrestarLibro
BEFORE INSERT ON prestamo
FOR EACH ROW EXECUTE PROCEDURE fncPrestarLibro();

INSERT INTO prestamo VALUES
(74, 1570951, '2023-12-08','2024-01-07');

-- b)

SELECT Ans2.dni, Ans2.nombres, Ans2.cantidad FROM (
    SELECT RANK() OVER (ORDER BY cantidad DESC) AS row, *
    FROM (
        SELECT E.dni, PER.nombres, COUNT(D.cnumero) AS cantidad
        FROM persona PER
        JOIN estudiante E ON E.dni = PER.dni
        JOIN prestamo P ON P.dni = E.dni
        JOIN detalleprestamo D ON P.numero = D.pnumero
        GROUP BY E.dni, PER.nombres
        ORDER BY cantidad DESC
         ) AS Ans
    ) AS Ans2
WHERE row = 2;

-- c)
SELECT numero, fprestamo, fdevolucion, (years + (30 * months) + days) AS dias
FROM (
    SELECT numero, fprestamo, fdevolucion,
        DATE_PART('year', AGE(fdevolucion,fprestamo)) AS years,
        DATE_PART('month', AGE(fdevolucion,fprestamo)) AS months,
        DATE_PART('day', AGE(fdevolucion,fprestamo)) AS days
    FROM prestamo
    ) AS dates
GROUP BY numero, fprestamo, fdevolucion, dias
HAVING (years + (30 * months) + days) >= (
    SELECT dias
    FROM (
        SELECT RANK() OVER (ORDER BY dias DESC) AS row, *
        FROM (
            SELECT (years + (30 * months) + days) AS dias
            FROM (
                SELECT numero, fprestamo, fdevolucion,
                    DATE_PART('year', AGE(fdevolucion,fprestamo)) AS years,
                    DATE_PART('month', AGE(fdevolucion,fprestamo)) AS months,
                    DATE_PART('day', AGE(fdevolucion,fprestamo)) AS days
                FROM prestamo
                ) AS dates
            GROUP BY dias
            ORDER BY dias DESC
             ) AS Ans
        ) AS Ans2
    WHERE row = 1
    )
ORDER BY dias DESC;


SELECT numero, (fprestamo + INTERVAL '4 MONTH') AS new
FROM prestamo
