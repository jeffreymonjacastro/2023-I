/* REPASITO GOD Semana 7 */

/* GESTIONAR Y CREAR TABLAS */

/* ESQUEMAS */
-- Creación de esquemas

CREATE SCHEMA repasitosql;

-- Setear
SET search_path TO repasitosql;

-- Setear esquema por defecto
ALTER USER jeffrey_amc SET search_path TO repasitosql;

-- Ver los esquemas
SHOW search_path;

-- Privilegios de esquemas
GRANT USAGE ON SCHEMA repasitosql TO jeffrey_amc; -- Solo lectura

GRANT ALL PRIVILEGES ON SCHEMA repasitosql TO nombre_usuario; -- todo

/* TABLAS */
-- Creación de tablas

CREATE TABLE spotify (
    id INTEGER, -- [NOT NULL] [DEFAULT valor] [CONSTRAINT nombre_constraint]
    nombre_s VARCHAR(50),
    nombre_c VARCHAR(50),
    visitas INTEGER,
    likes INTEGER
);

-- Eliminación de tablas
DROP TABLE spotify;

/* ACTIALIZAR TABLAS */
-- Insertar turplas
INSERT INTO spotify VALUES (1, 'Shape of you', 'Ed Sheeran', 1000000, 500000);

INSERT INTO spotify (id, nombre_s, nombre_c, visitas, likes) VALUES
    (2, 'Shake It Off', 'Taylor Swift', 2000000, 900000);

INSERT INTO spotify (likes, visitas, nombre_c, nombre_s, id) VALUES
    (100000, 3000000, 'Ariana Grande', '7 Rings', 3);

INSERT INTO spotify(id, nombre_c, nombre_s) VALUES
    (4, 'Ariana Grande', 'Thank U, Next');

-- Editar tuplas
UPDATE spotify SET likes = 999999 WHERE id = 4;

-- Eliminar tuplas
DELETE FROM spotify WHERE id = 4;

-- Eliminar columnas
ALTER TABLE spotify DROP COLUMN likes;

-- Agregar columnas
ALTER TABLE spotify ADD COLUMN fechasubida DATE;

-- Modificar columnas
ALTER TABLE spotify ALTER COLUMN fechasubida TYPE VARCHAR(255);


/* RESTRICCIONES */
-- Llaves, nulos, dominio en la creación de tablas

CREATE TABLE youtube (
    id INTEGER PRIMARY KEY,
    nombre_s VARCHAR(50) NOT NULL,
    nombre_c VARCHAR(50) NOT NULL,
    visitas INTEGER NOT NULL,
    likes INTEGER NOT NULL,
    compartido BOOLEAN NOT NULL,
    fechasubida DATE NOT NULL
);

-- Default
CREATE TABLE youtube (
    id INTEGER PRIMARY KEY,
    nombre_s VARCHAR(50) NOT NULL,
    nombre_c VARCHAR(50) NOT NULL,
    visitas INTEGER NOT NULL DEFAULT 0,
    likes INTEGER NOT NULL DEFAULT 0,
    compartido BOOLEAN NOT NULL DEFAULT FALSE,
    fechasubida DATE NOT NULL
);

-- Unicidad
CREATE TABLE youtube (
    id INTEGER PRIMARY KEY,
    nombre_s VARCHAR(50) NOT NULL,
    nombre_c VARCHAR(50) NOT NULL,
    visitas INTEGER NOT NULL,
    likes INTEGER NOT NULL,
    compartido BOOLEAN NOT NULL,
    fechasubida DATE NOT NULL,

    UNIQUE(nombre_s, nombre_c)
);

-- Nombrer y borrar restricciones
    -- Más fácil cambiar restricciones posteriormente.
    -- Si hay una violación, el mensaje de error será más intuitiva si las restricciones
    -- tienen nombres intuitivos.

CREATE TABLE youtube (
    id INTEGER,
    nombre_s VARCHAR(50) NOT NULL,
    nombre_c VARCHAR(50) NOT NULL,
    visitas INTEGER NOT NULL,
    likes INTEGER NOT NULL,
    compartido BOOLEAN NOT NULL,
    fechasubida DATE NOT NULL,

    CONSTRAINT pk_youtube PRIMARY KEY (id),
    CONSTRAINT cuenta_uni_youtube UNIQUE (nombre_s, nombre_c)
);

ALTER TABLE youtube DROP CONSTRAINT pk_youtube;

-- Llaves foráneas
    -- No se puede agregar nuevos cantantes si no existe en la tabla cantante.
CREATE TABLE youtube (
    id INTEGER PRIMARY KEY,
    nombre_s VARCHAR(50) NOT NULL,
    nombre_c VARCHAR(50) REFERENCES cantante(nombre), -- Foránea
    visitas INTEGER NOT NULL,
    likes INTEGER NOT NULL,
    compartido BOOLEAN NOT NULL,
    fechasubida DATE NOT NULL

    -- FOREIGN KEY (nombre_c) REFERENCES cantante(nombre) -- Otra forma Foránea
    -- CONSTRAIT fk_youtube FOREIGN KEY (nombre_c) REFERENCES cantante(nombre) -- Otra forma Foránea
);

-- Llaves compuestas
CREATE TABLE youtube (
    id INTEGER,
    nombre_s VARCHAR(50),
    nombre_c VARCHAR(50),
    visitas INTEGER,
    likes INTEGER,
    compartido BOOLEAN,
    fechasubida DATE,

    PRIMARY KEY (nombre_s, nombre_c)
);

-- Hace referencia a todas las llaves de la tabla youtube
CREATE TABLE resumen (
    idr INTEGER,
    cancion VARCHAR(50),
    artista VARCHAR(50),

    FOREIGN KEY (cancion, artista) REFERENCES youtube(nombre_s, nombre_c)
);

-- Restricciones sobre varias columnas (CHECK)
CREATE TABLE youtube (
    id INTEGER,
    nombre_s VARCHAR(50),
    nombre_c VARCHAR(50),
    visitas INTEGER,
    likes INTEGER,
    compartido BOOLEAN,
    fechasubida DATE,

    CHECK (visitas > 0 AND likes > 0),

    -- Este tipo de consultas anidadas en CHECK es muy caro
    CHECK (ROUND((visitas/likes)::NUMERIC - 10 -
           (SELECT visitas
            FROM spotify
            WHERE nombre_s = 'Shape of you'),2) = 0)
);

/* DEFINIR DOMINIOS Y TIPOS */

CREATE DOMAIN nombres VARCHAR(50) NOT NULL;

CREATE DOMAIN valores BIGINT
    CHECK (VALUE >= 0 AND VALUE < 1000000)
    NOT NULL;

CREATE TABLE youtube (
    id INTEGER PRIMARY KEY,
    nombre_s nombres,
    nombre_c nombres,
    visitas valores,
    likes valores,
    compartido BOOLEAN NOT NULL,
    fechasubida DATE NOT NULL
);


/* TIPOS COMPUESTOS */

CREATE TYPE estadisticas AS (
    visitas INTEGER,
    likes INTEGER,
    compartido BOOLEAN
);

-- El tipo estadísitcas toma más de un valor
CREATE TABLE youtube (
    id INTEGER PRIMARY KEY,
    nombre_s VARCHAR(50) NOT NULL,
    nombre_c VARCHAR(50) NOT NULL,
    datos estadisticas,
    fechasubida DATE NOT NULL
);


/* Crear usuarios */
CREATE ROLE usr_jeffreyamc;

-- DAR consulta a usuario en tabla album
GRANT USAGE ON SCHEMA repasitosql TO usr_jeffreyamc;
GRANT SELECT ON album TO usr_jeffreyamc;

-- DAR todos las capacidades a usuario en tabla ventas
GRANT USAGE ON SCHEMA repasitosql to usr_jeffreyamc;
GRANT SELECT , INSERT , DELETE , UPDATE ON ventas TO usr_jeffreyamc;

-- No dar acceso a tablas a usuario 3
    -- NO es necesario hacer nada solo no darle permisos

-- Revocar toda capacidad de poder visualizar cosas en base de datos a usuario
REVOKE SELECT ON ALL TABLES IN SCHEMA repasitosql FROM usr_jeffreyamc;


/* CREAR SECUENCIAS */
-- Una secuencia es un objeto que genera números secuenciales.
CREATE SEQUENCE id_incremento
    START WITH 0
    INCREMENT BY 10;

ALTER TABLE spotify ALTER COLUMN id SET DEFAULT nextval('id_incremento'::regclass);
