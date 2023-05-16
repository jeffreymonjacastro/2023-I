/* crear esquemas */
-- CREATE SCHEMA asesorias

/* settear esquema */
SET search_path = asesorias; -- Para cambiar la consola al esquema creado

/* crear y agregar restricciones a las tablas

   CREATE TABLE <nombre_tabla>(
        <nombre_variable> <TIPO_VARIABLE> <RESTRICCIÓN (opc.)>,
        <nombre_variable> <TIPO_VARIABLE>
   );

   Tipos de restricciones: PRIMARY KEY, NOT NULL, DEFAULT (val), UNIQUE(val,val..)

   Otra opción:
   CONSTRAIT <nombre_restricc> <TIPO_CONSTR> (val, val...)

   Llaves foráneas:
   FOREIGN KEY (var, var...) REFERENCES <TABLE> (val_principal, val_principal...)

*/

CREATE TABLE persona(
    dni VARCHAR(8) PRIMARY KEY,
    nombre VARCHAR(20),
    edad INT
    -- fecha_nac TIMESTAMP, <- tipo fecha
    -- dinero BIGINT <- Tipo long int
    -- PRIMARY KEY (dni) <- Otra opción
);

/* Creando tuplas

   INSERT INTO <nombre_tabla>(att1, att2,.. ) VALUES
        (val1, val2,...),
        ...
        (val1, val2,...);

*/

INSERT INTO persona (dni, nombre, edad) VALUES
    ('76169761', 'Jeffrey', 18),
    ('70731718', 'Romy', 18),
    ('12345678', 'Juan', 25),
    ('23456789', 'María', 30),
    ('34567890', 'Pedro', 40),
    ('45678901', 'Luis', 22),
    ('56789012', 'Ana', 27),
    ('67890123', 'Jorge', 35),
    ('78901234', 'Sofía', 29),
    ('89012345', 'Diego', 33),
    ('90123456', 'Lucía', 26),
    ('01234567', 'Carla', 31);