SET search_path TO pc2_2023_I_rommel;

/* DATA */
/* https://gist.github.com/rommelDB/5327af83393facc6d89927f87abcf82a */

-- 1.b) CONSULTAS
-- 1. Obtener los códigos de los carros cuyo nombre no contenga ninguna letra ’a’.
SELECT codigo
FROM carro
WHERE nombre NOT LIKE '%a%'
AND nombre NOT LIKE '%A%';

-- 2. Obtener los códigos de los carros vendidos por algún concesionario del distrito ’Centro’.
SELECT C.codigo, C.nombre
FROM carro C
JOIN stock S ON C.codigo = S.carro_codigo
JOIN concesionario CO ON S.concesionario_codigo = CO.codigo
WHERE CO.distrito = 'Centro';

-- 3. Obtener el nombre y apellido de los clientes que compraron un carro a un precio mayor que
    -- todos los clientes que le compraron un carro a los Concesionarios cuyo distrito es ’Centro’.
SELECT CL.nombre, CL.apellido
FROM cliente CL
JOIN venta V ON CL.dni = V.cliente_dni
WHERE V.precio > (
    SELECT AVG(V.precio) AS promedio
    FROM carro C
    JOIN stock S ON C.codigo = S.carro_codigo
    JOIN concesionario CO ON S.concesionario_codigo = CO.codigo
    JOIN venta V ON V.carro_codigo = C.codigo
    WHERE CO.distrito = 'Centro'
    );

-- 4. Obtener los distritos de aquellos clientes que compraron un carro el día 1 y otro carro el
    -- día 4 de Enero del 2020.
SELECT CL.distrito
FROM cliente CL
JOIN venta V ON CL.dni = V.cliente_dni
WHERE V.fecha = '2020-01-01'
OR V.fecha = '2020-01-04';

-- 5. Obtener los números de DNI de aquellos clientes que sólo han comprado carros al concesionario
    -- de código 1. Su consulta NO debe utilizar EXCEPT.
SELECT *
FROM cliente CL
JOIN venta V ON CL.dni = V.cliente_dni
WHERE V.concesionario_codigo = 1;

-- 6. Obtener el nombre de los concesionarios que no sean del distrito ’Centro’ cuyo promedio de
    -- vehículos en stock sea mayor o igual a todos los demás promedios.

SELECT CO.nombre, AVG(S.cantidad) AS promedio
FROM concesionario CO
JOIN stock S ON CO.codigo = S.concesionario_codigo
WHERE CO.distrito <> 'Centro'
GROUP BY CO.nombre
HAVING AVG(S.cantidad) >= ALL (
    SELECT AVG(S.cantidad) AS promedio
    FROM concesionario CO
    JOIN stock S ON CO.codigo = S.concesionario_codigo
    WHERE CO.distrito <> 'Centro'
    GROUP BY CO.nombre
    );

-- 1.c) Sin modificar el script SQL de la creación de tablas, agregue las llaves
    -- primarias y foráneas que el modelo ER describe.
ALTER TABLE marca ADD CONSTRAINT pk_marca PRIMARY KEY (codigo);
ALTER TABLE carro ADD CONSTRAINT pk_carro PRIMARY KEY (codigo);
ALTER TABLE es ADD CONSTRAINT fk_marca_es FOREIGN KEY (marca_codigo) REFERENCES marca(codigo);
ALTER TABLE es ADD CONSTRAINT fk_codigo_es FOREIGN KEY (carro_codigo) REFERENCES carro(codigo);
ALTER TABLE cliente ADD CONSTRAINT pk_cliente PRIMARY KEY (dni);
ALTER TABLE concesionario ADD CONSTRAINT pk_concesionario PRIMARY KEY (codigo);
ALTER TABLE venta ADD CONSTRAINT fk_consecionario_venta FOREIGN KEY (concesionario_codigo) REFERENCES concesionario(codigo);
ALTER TABLE venta ADD CONSTRAINT fk_carro_venta FOREIGN KEY (carro_codigo) REFERENCES carro(codigo);
ALTER TABLE venta ADD CONSTRAINT fk_cliente_venta FOREIGN KEY (cliente_dni) REFERENCES cliente(dni);
ALTER TABLE stock ADD CONSTRAINT fk_carro_stock FOREIGN KEY (carro_codigo) REFERENCES carro(codigo);
ALTER TABLE stock ADD CONSTRAINT fk_consecionario_stock FOREIGN KEY (concesionario_codigo) REFERENCES concesionario(codigo);


-- 1.d) Sin modificar el script SQL de la creación de tablas, agregue las restricciones
-- 1. El nombre de un concesionario y la marca de un carro nunca se deben
    -- repetir para evitar ambigüedades.
ALTER TABLE concesionario ADD CONSTRAINT uq_nombre_concesionario UNIQUE (nombre);
-- ALTER TABLE carro ADD CONSTRAINT uq_modelo_carro UNIQUE (modelo);

-- 2. Las cantidades en stock siempre deben ser mayores o iguales a cero.
ALTER TABLE stock ALTER COLUMN cantidad SET NOT NULL;

-- 2.a) Para tener una mayor exactitud sobre el momento de las ventas (Sin
    -- modificar el script SQL de la creación de tablas):
-- 1. Agregue una columna que contenga la hora cuyo valor por defecto sea
    -- el medio día (’12:00:00’)
ALTER TABLE venta ADD COLUMN hora TIME DEFAULT '12:00:00';

-- 2. Adicione la restricción de que tanto Fecha y Hora no pueden permitir valores nulos.
ALTER TABLE venta ALTER COLUMN fecha SET NOT NULL;
ALTER TABLE venta ALTER COLUMN hora SET NOT NULL;

-- 2.b) Con el objetivo de evitar duplicidad de datos e inconsistencias, se desea
    -- guardar el nombre de los distritos en su propia tabla.
-- 1. Escriba el código de creación de la tabla Distrito con un código único entero, y otro
    -- atributo ’Nombre’ considerando en la creación de la tabla la restricción de llave primaria.

CREATE TABLE distrito (
    codigo INT PRIMARY KEY,
    nombre VARCHAR(50)
);

-- 2. Escriba el código de inserción de distritos conteniendo la unión de todos los distritos
    -- los distritos existentes en Concesionario y Cliente.
SELECT ROW_NUMBER() OVER(ORDER BY distrito) AS codigo, distrito
FROM (
    SELECT DISTINCT distrito
    FROM concesionario
    UNION
    SELECT DISTINCT distrito
    FROM cliente
) AS distrito;

INSERT INTO distrito VALUES
(1, 'Barranco'),
(2, 'La Molina'),
(3, 'Centro'),
(4, 'Villa El Salvador');


-- 3. Agregue la columna distrito_codigo en las tablas Concesionario y Cliente de tal manera que
    -- basado en el valor del nombre de distrito ahora sea el código correspondiente.
ALTER TABLE concesionario ADD COLUMN distrito_codigo INT;
ALTER TABLE cliente ADD COLUMN distrito_codigo INT;

UPDATE concesionario C
SET distrito_codigo = (
    SELECT codigo
    FROM distrito
    WHERE nombre = C.distrito
);

UPDATE cliente CL
SET distrito_codigo = (
    SELECT codigo
    FROM distrito
    WHERE nombre = CL.distrito
);

-- 4. Escriba el código de eliminación de las columnas ’codigo’ en Concesionario
    -- y Cliente pues ya no las necesitamos.
ALTER TABLE concesionario DROP COLUMN distrito;
ALTER TABLE cliente DROP COLUMN distrito;

-- 5. Luego tendrá que crear dos tablas extras (distCliente y distConcesionario) que corresponderán
    -- a las relaciones que indicarán a qué distrito pertenece cada cliente y concesionario respectivamente.
    -- Declare las restricciones de llaves primarias y foráneas adecuadas en la creación de las tablas.
CREATE TABLE distCliente (
    cliente_dni varchar(8),
    distrito_codigo INT,
    PRIMARY KEY (cliente_dni, distrito_codigo),
    FOREIGN KEY (cliente_dni) REFERENCES cliente(dni),
    FOREIGN KEY (distrito_codigo) REFERENCES distrito(codigo)
);

CREATE TABLE distConcesionario (
    concesionario_codigo INT,
    distrito_codigo INT,
    PRIMARY KEY (concesionario_codigo, distrito_codigo),
    FOREIGN KEY (concesionario_codigo) REFERENCES concesionario(codigo),
    FOREIGN KEY (distrito_codigo) REFERENCES distrito(codigo)
);

-- 6. Ecriba el código de inserción en las tablas distCliente y distConcesionario para todos los
    -- distritos de acuerdo a la versión anterior de la base de datos. Agregue las nuevas
    -- restricciones de llaves foráneas a las tablas Cliente y Concesionario.
INSERT INTO distCliente (cliente_dni, distrito_codigo)
SELECT CL.dni, D.codigo
FROM cliente CL
JOIN distrito D ON CL.distrito_codigo = D.codigo;

INSERT INTO distConcesionario (concesionario_codigo, distrito_codigo)
SELECT C.codigo, D.codigo
FROM concesionario C
JOIN distrito D ON C.distrito_codigo = D.codigo;