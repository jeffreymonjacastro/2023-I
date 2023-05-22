/* REPASITO GOD Semana 8 */

/* VISTAS */
-- Las vistas son tablas virtuales, no físicas
-- Se acceden a ellas cada vez que se realice la consulta
-- No se almacena información en la vista, solo se almacena la consulta.
-- Ayudan a simplificar las consultas
-- Con la vista, guardamos una sub-consulta frecuente para reutilizarla en varias consultas.
-- Se aumenta la seguridad, ya que se puede dar acceso a una vista y no a la data

/* CREAR VISTA */
CREATE VIEW EvalVentas AS
    SELECT fechaventa, COUNT(cantidad) AS cantidad, SUM(precio) AS totalPrecio, ROUND(AVG(precio)) AS promedioPrecio
    FROM ventas
    GROUP BY fechaventa
    ORDER BY cantidad DESC;

CREATE VIEW MasVendidos AS
    SELECT A.nombre, A.cnombre, COUNT(V.cantidad) AS cantidad, ROUND(AVG(V.precio)) AS promedioPrecio
    FROM album A
    JOIN ventas V ON A.aid = V.aid
    GROUP BY A.nombre, A.cnombre
    ORDER BY cantidad DESC;


/* CONSULTAR VISTA */
SELECT fechaventa, promedioPrecio
FROM EvalVentas
WHERE fechaventa BETWEEN '2022-01-01' AND '2022-01-31';


SELECT nombre, cnombre, cantidad
FROM masvendidos
WHERE promedioPrecio > 30;


/* ELIMINAR VISTA */
DROP VIEW MasVendidos;


/* VISTAS ACTUALIZABLES */
-- Las vistas actualizables permiten realizar operaciones de inserción, actualización y eliminación de datos.
-- Cuando una vista posee funciones de agregación o proyección que elimine
    -- una columna que no admita nulos, no es actualizable, es solo lectura
-- Las tuplas que se ingresen en las vistas actualizables, se ingresan en las tablas que se usaron para crear la vista.

CREATE VIEW Artistas AS
    SELECT *
    FROM cantante;

INSERT INTO Artistas (nombre, sexo, fechanacimiento, paisorigen) VALUES
    ('Jungkook', 'M', '1997-09-01', 'Corea del Sur');


/* VISTA MATERIALIZADA */
-- Las vistas materializadas son vistas que almacenan la información en disco, como si fuera una tabla física.
-- A diferencia de las vistas, las vistas materializadas no se actualizan cada vez que se realiza una consulta, se
    -- actualizan cada cierto tiempo manualmente o automáticamente.
-- Las vistas materializadas se usan para mejorar el rendimiento de las consultas, ya que se almacena la información

CREATE MATERIALIZED VIEW EvalVentas AS
    SELECT fechaventa, COUNT(cantidad) AS cantidad, SUM(precio) AS totalPrecio, ROUND(AVG(precio)) AS promedioPrecio
    FROM ventas
    GROUP BY fechaventa
    ORDER BY cantidad DESC;

SELECT fechaventa, promedioPrecio
FROM EvalVentas;

INSERT INTO ventas (vid, uid, aid, fechaventa, cantidad, precio) VALUES
    (230, 94, 10, '2022-08-25', 4, 90);

-- Se actualiza manualmente
REFRESH MATERIALIZED VIEW EvalVentas;

-- Se actualiza automáticamente cada 1 hora
REFRESH MATERIALIZED VIEW EvalVentas WITH DATA;

/* ACTUALIZAR VISTAS MATERIALIZADAS */
-- ALTER COLUM/RENAME/ADD/DROP/SET DEFAULT/DROP DEFAULT/SET NOT NULL/DROP NOT NULL/OWNER TO...
ALTER MATERIALIZED VIEW EvalVentas RENAME TO EvalVentas2;

/* TRIGGERS */
-- Los triggers son procedimientos almacenados que se ejecutan automáticamente cuando se
    -- realiza una operación de inserción, actualización o eliminación en una tabla.
-- Se caracterizan por un Evento, una Condición y una Acción
-- En PSQL se crea primero la función con la condición y la acción del trigger y luego
    -- se declara dónde se ejecutará el trigger

/* CREACIÓN DEL TRIGGER O STORED PROCEDURE */
CREATE FUNCTION UpdateVentas() RETURNS TRIGGER AS
$$
    BEGIN
        IF EXISTS( -- Condición
            SELECT *
            FROM ventas
            WHERE fechaventa = NEW.fechaventa)
        THEN -- Acción
            UPDATE ventas
            SET cantidad = cantidad + NEW.cantidad
            WHERE fechaventa = NEW.fechaventa;
        ELSE
            INSERT INTO ventas (vid, uid, aid, fechaventa, cantidad, precio) VALUES
                (NEW.vid, NEW.uid, NEW.aid, NEW.fechaventa, NEW.cantidad, NEW.precio);
        END IF;
        RETURN NEW;
    END;
$$ LANGUAGE plpgsql;

/* DECLARACIÓN DEL TRIGGER Y EVENTOS */
CREATE TRIGGER ActualizarVentas
    AFTER INSERT OR UPDATE ON ventas -- Evento
    FOR EACH ROW EXECUTE PROCEDURE UpdateVentas();

-- Ingresar datos
INSERT INTO ventas (vid, uid, aid, fechaventa, cantidad, precio) VALUES
    (231, 93, 10, '2023-03-16', 1, 99.99);

UPDATE ventas
SET cantidad = 5,
    precio = 100,
    aid = 5,
    fechaventa = '2023-03-16'
WHERE vid = 230;

/* ELIMINAR TRIGGERS */
DROP TRIGGER ActualizarVentas ON ventas;


/* STORED PROCEDURES */
-- Los stored procedures son procedimientos almacenados que se ejecutan cuando se llaman.

CREATE OR REPLACE PROCEDURE nombre_proc(
    val integer,
    val2 varchar(50)
)
    LANGUAGE plpgsql AS
$$
    DECLARE
        var1 integer;
        var2 varchar(50);
    BEGIN
        var1 := val;
        var2 := val2;
        RAISE NOTICE 'El valor de var1 es %', var1;
        RAISE NOTICE 'El valor de var2 es %', var2;
    END;

$$;

-- LLAMAR AL PRCEDIMIENTO
CALL nombre_proc(10, 'Hola');