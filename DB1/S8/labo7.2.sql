-- 1) Modelo Relacional
/*
Deposito(_id_ , dimension , capacidad_galones , abastecido_galones (mutivalue), Combustible.tipo)

Combustible(_tipo_)

Abastecimiento(_nro(INT)_ , fecha , Deposito.id ,  Proveedor.nro_licencia , Proveedor.placa_camion)

Proveedor(_placa_camion_ , _nro_licencia_)

SurtidorCombustible(_nroserie_ , _lado_ , marca , Deposito.id )

Venta(_nro_ , fecha , monto_total , SurtidorCombustible.nroserie, SurtidorCombustible.lado , cantidad_galones , precio_unitario)

PersonaNatural(_nro_documento_)

DespachoCombustible(_PersonaNatural.nro_documento_ , sueldo)

CLiente(_PersonaNatural.nro_documento_)

*/
SET search_path = petrogasgrupo5_3;

-- 2.a) Creación de tablas en SQL (sin restricciones)

CREATE TABLE Deposito(
    id integer ,
    dimensionX REAL ,
    dimensionY REAL,
    dimensionZ REAL ,
    capacidad_galones REAL ,
    abastecido_galones REAL,
    Combustible_tipo varchar(50)
);

CREATE TABLE  Combustible(
    tipo varchar(50)
);

CREATE TABLE Abastecimiento(
    nro integer,
    fecha timestamp,
    Deposito_id integer,
    Proveedor_nro_licencia varchar(50),
    Proveedor_placa_camion varchar(50),
    cantidad_galones integer,
    precio REAL
);

CREATE TABLE Proveedor(
    nro_licencia varchar(50),
    placa_camion varchar(50)
);

CREATE TABLE SurtidorCombustible(
  numero_serie varchar(50),
  lado varchar(50),
  marca varchar(50),
  Deposito_id integer
);

CREATE TABLE Venta(
  nro integer,
  fecha date,
  monto_total real,
  Surtidor_nros varchar(50),
  Surtidor_lado varchar(50),
  cantidad_galones integer,
  precio_unitario real,
  Despachador_nro varchar(50),
  Cliente_nro varchar(50)
);

CREATE TABLE PersonaNatural(
    nro_documento varchar(50)
);

CREATE TABLE DespachadorCombustible(
    PersonaD_nro varchar(50),
    sueldo  integer
);

CREATE TABLE Cliente(
  PersonaC_nro varchar(50)
);


-- 2.b) Agregar primary keys, foreign keys y otras restricciones

/* PRIMARY KEYS */
ALTER TABLE deposito ADD CONSTRAINT deposito_pk_id PRIMARY KEY (id);
ALTER TABLE combustible ADD CONSTRAINT combustible_pk_tipo PRIMARY KEY (tipo);
ALTER TABLE abastecimiento ADD CONSTRAINT abastecimiento_pk_nro PRIMARY KEY (nro);
ALTER TABLE proveedor ADD CONSTRAINT proveedor_pk_nro_placa PRIMARY KEY (nro_licencia, placa_camion);
ALTER TABLE SurtidorCombustible ADD CONSTRAINT SurtidorCombustible_pk_numero_lado PRIMARY KEY (numero_serie,lado);
ALTER TABLE Venta ADD CONSTRAINT Venta_pk_nro PRIMARY KEY (nro);
ALTER TABLE PersonaNatural ADD CONSTRAINT PersonaNatural_pk_nro_documento PRIMARY KEY (nro_documento);
ALTER TABLE DespachadorCombustible ADD CONSTRAINT DespachadorCombustible_pk_PersonaD_nro PRIMARY KEY (PersonaD_nro);
ALTER TABLE Cliente ADD CONSTRAINT Cliente_pk_PersonaC_nro PRIMARY KEY (PersonaC_nro);

/* FOREIGN KEYS */
ALTER TABLE deposito ADD CONSTRAINT  deposito_fk_tipo FOREIGN KEY (Combustible_tipo) REFERENCES combustible(tipo);
ALTER TABLE abastecimiento ADD CONSTRAINT abastecimiento_fk_id FOREIGN KEY  (deposito_id) REFERENCES deposito(id);
ALTER TABLE abastecimiento ADD CONSTRAINT abastecimiento_fk_nro_placa FOREIGN KEY  (Proveedor_nro_licencia, Proveedor_placa_camion) REFERENCES Proveedor(nro_licencia, placa_camion) ;
ALTER TABLE SurtidorCombustible ADD CONSTRAINT SurtidorCombustible_fk_depositoid FOREIGN KEY (Deposito_id) REFERENCES Deposito(id);
ALTER TABLE Venta ADD CONSTRAINT Venta_fk_surt FOREIGN KEY (Surtidor_nros,Surtidor_lado) REFERENCES SurtidorCombustible(numero_serie,lado);
ALTER TABLE Venta ADD CONSTRAINT Venta_fk_Dnro FOREIGN KEY (Despachador_nro) REFERENCES DespachadorCombustible(PersonaD_nro);
ALTER TABLE Venta ADD CONSTRAINT Venta_fk_Cnro FOREIGN KEY (Cliente_nro) REFERENCES Cliente(PersonaC_nro);

/* Otras restricciones */


-- 2.c) Agregar restricciones:
/* 1. En la tabla persona agregar atributos: nombres, apellidos, fecha nacimiento, email, ciudad. */
/* 2. Para que el email no se repita */
ALTER TABLE PersonaNatural ADD nombres varchar(50);
ALTER TABLE PersonaNatural ADD apellidos varchar(50);
ALTER TABLE PersonaNatural ADD fecha_nac date;
ALTER TABLE PersonaNatural ADD email varchar(50) UNIQUE ;
ALTER TABLE PersonaNatural ADD ciudad varchar(50);

/* 3. Que la edad esté en el intervalo de 12 y 85. */
ALTER TABLE PersonaNatural ADD CONSTRAINT check_date_Edad CHECK (
    EXTRACT (YEAR FROM age(cast(fecha_nac as date)))  >=12 AND EXTRACT (YEAR FROM age(cast(fecha_nac as date))) <= 85
);

/* 4. La numeración de los proveedores deben iniciar siempre con "P" (Ejemplo: P0001) */
ALTER TABLE proveedor ADD CONSTRAINT  nro_licencia_start_p CHECK (nro_licencia LIKE 'P%');

/* 5. El abastecimiento solo se realizar por las noches, es decir, desde de 23:00 a 23:59hrs. */
ALTER TABLE abastecimiento ADD CHECK ( extract(HOUR  FROM  fecha) = 23 and extract(MINUTE FROM fecha)>0 and extract(MINUTE FROM  fecha )<=59);

/* 6. La cantidad de caracteres de la placa del camión siempre debes ser 6 y es alfanumérico. */
ALTER TABLE proveedor ADD CONSTRAINT alfa_numerico_proov CHECK (Proveedor.placa_camion ~ '^[a-zA-Z0-9]{6}$');

/* 7. Por ningún motivo la cantidad de galones abastecido puede exceder la capacidad del tanque. */
ALTER TABLE deposito ADD CONSTRAINT capacidad_maxima check ( abastecido_galones< Deposito.capacidad_galones );

/* 8. La capacidad del tanque no puede estar en negativo. */
ALTER TABLE deposito ADD CONSTRAINT capacidad_galones_pos check (capacidad_galones > 0);

/* 9. En ninguna de las tablas se debe permitir valores Nulos */
-----------------------NOT NULL DEPOSITO----------------------------------
ALTER TABLE deposito ALTER COLUMN id SET NOT NULL ;
ALTER TABLE deposito ALTER COLUMN dimensionX SET NOT NULL ;
ALTER TABLE deposito ALTER COLUMN dimensionY SET NOT NULL ;
ALTER TABLE deposito ALTER COLUMN dimensionZ SET NOT NULL ;
ALTER TABLE deposito ALTER COLUMN capacidad_galones SET NOT NULL ;
ALTER TABLE deposito ALTER COLUMN abastecido_galones SET NOT NULL ;
ALTER TABLE deposito ALTER COLUMN combustible_tipo SET NOT NULL ;

-------------------------NOT NULL COMBUSTIBLE-------------------------------
ALTER TABLE combustible ALTER COLUMN  tipo SET NOT NULL ;

-------------------------NOT NULL ABASTECIMIENTO-------------------------------
ALTER TABLE abastecimiento ALTER COLUMN nro SET NOT NULL ;
ALTER TABLE abastecimiento ALTER COLUMN fecha SET NOT NULL ;
ALTER TABLE abastecimiento ALTER COLUMN deposito_id SET NOT NULL ;
ALTER TABLE abastecimiento ALTER COLUMN proveedor_nro_licencia SET NOT NULL ;
ALTER TABLE abastecimiento ALTER COLUMN proveedor_placa_camion SET NOT NULL ;

-------------------------NOT NULL PROVEEDOR-------------------------------
ALTER TABLE proveedor ALTER COLUMN placa_camion SET NOT NULL ;
ALTER TABLE proveedor ALTER COLUMN nro_licencia SET NOT NULL ;

----------------------NOT NULL SURTIDORCOMBUSTIBLE------------------------
ALTER TABLE SurtidorCombustible ALTER COLUMN numero_serie SET NOT NULL ;
ALTER TABLE SurtidorCombustible ALTER COLUMN lado SET NOT NULL ;
ALTER TABLE SurtidorCombustible ALTER COLUMN marca SET NOT NULL ;
ALTER TABLE SurtidorCombustible ALTER COLUMN Deposito_id SET NOT NULL ;

--------------------------NOT NULL VENTA--------------------------------
ALTER TABLE Venta ALTER COLUMN nro SET NOT NULL ;
ALTER TABLE Venta ALTER COLUMN fecha SET NOT NULL ;
ALTER TABLE Venta ALTER COLUMN monto_total SET NOT NULL ;
ALTER TABLE Venta ALTER COLUMN Surtidor_nros SET NOT NULL ;
ALTER TABLE Venta ALTER COLUMN Surtidor_lado SET NOT NULL ;
ALTER TABLE Venta ALTER COLUMN cantidad_galones SET NOT NULL ;
ALTER TABLE Venta ALTER COLUMN precio_unitario SET NOT NULL ;
ALTER TABLE Venta ALTER COLUMN Despachador_nro SET NOT NULL;
ALTER TABLE Venta ALTER COLUMN Cliente_nro SET NOT NULL;

--------------------NOT NULL PERSONANATURAL------------------------------
ALTER TABLE PersonaNatural ALTER COLUMN nro_documento SET NOT NULL;
ALTER TABLE PersonaNatural ALTER COLUMN nombres SET NOT NULL ;
ALTER TABLE PersonaNatural ALTER COLUMN apellidos SET NOT NULL ;
ALTER TABLE PersonaNatural ALTER  COLUMN fecha_nac SET NOT NULL ;
ALTER TABLE PersonaNatural ALTER COLUMN email SET NOT NULL;
ALTER TABLE PersonaNatural ALTER COLUMN ciudad SET NOT NULL;

-------------------NOT NULL DESPACHADORCOMBUSTIBLE------------------------
ALTER TABLE DespachadorCombustible ALTER COLUMN PersonaD_nro SET NOT NULL;
ALTER TABLE DespachadorCombustible ALTER COLUMN sueldo SET NOT NULL;

---------------------------NOT NULL CLIENTE------------------------------
ALTER TABLE Cliente ALTER COLUMN PersonaC_nro SET NOT NULL;

/* 10. Los celulares siempre son de 9 dígitos y empiezan con 9. */
ALTER TABLE PersonaNatural ADD nro_celular varchar(9);
ALTER TABLE PersonaNatural ALTER COLUMN nro_celular SET NOT NULL;

ALTER TABLE PersonaNatural ADD CONSTRAINT celular_longitud CHECK ( length(nro_celular) = 9 );

ALTER TABLE PersonaNatural ADD CONSTRAINT primer_digito CHECK (nro_celular LIKE '9%');

/* 11. Para la venta, use CREATE SEQUENCE para crear una secuencia ascendente a partir de 100 con un incremento de 5. */
/* 12. Considere usar DEFAULT para valores calculados o estáticos. */
CREATE SEQUENCE nroventa_inc
    START WITH 100
    INCREMENT BY 5;

ALTER TABLE Venta ALTER COLUMN nro SET DEFAULT nextval('nroventa_inc'::regclass);


-- 2.d) Registrar 4 ventas y 2 abastecimientos
INSERT INTO Combustible (tipo) VALUES
('GNV'),
('GLP');

INSERT INTO Deposito (id, dimensionX, dimensionY, dimensionZ, capacidad_galones,
                      abastecido_galones, Combustible_tipo) VALUES
(1, 10.5, 8.2, 6.7, 10000, 7500, 'GNV');

INSERT INTO SurtidorCombustible (numero_serie, lado, marca, Deposito_id) VALUES
('1A', 'Lado A', 'Repsol', 1),
('2B', 'Lado B', 'Repsol', 1);

INSERT INTO PersonaNatural (nro_documento, nombres, apellidos, fecha_nac, email, ciudad, nro_celular) VALUES
('78912345', 'Pablo', 'Suarez', '1995-07-16', 'pablo.suarez@gmail.com', 'Lima', '933322211'),
('75678888', 'Ana', 'Castillo', '1992-04-20', 'ana.castillo@gmail.com', 'Lima', '987654321'),
('71234568', 'Juan', 'Tipula', '2000-01-02', 'juan.tipula@gmail.com', 'Lima', '955533388');

INSERT INTO DespachadorCombustible (PersonaD_nro, sueldo) VALUES
('78912345', 3000),
('75678888', 2500);

INSERT INTO Cliente (PersonaC_nro) VALUES
('71234568');

INSERT INTO Venta (nro, fecha, monto_total, Surtidor_nros, Surtidor_lado, cantidad_galones,
                   precio_unitario, Despachador_nro, Cliente_nro) VALUES
(100, '2023-05-01', 100.25, '1A', 'Lado A', 10, 10.02, '78912345', '71234568'),
(105, '2023-05-02', 85.50, '2B', 'Lado B', 8, 10.69, '75678888', '71234568'),
(110, '2023-05-03', 150.75, '2B', 'Lado B', 15, 10.05, '78912345', '71234568'),
(115, '2023-05-04', 75.30, '1A', 'Lado A', 7, 10.75, '75678888', '71234568');

INSERT INTO Proveedor (nro_licencia, placa_camion) VALUES
('P2345678', 'PBC123'),
('P7654321', 'PYZ789');


INSERT INTO Abastecimiento (nro, fecha, Deposito_id, Proveedor_nro_licencia,
                            Proveedor_placa_camion, cantidad_galones, precio) VALUES
(1, '2023-05-01 23:14:00', 1, 'P2345678', 'PBC123', 100, 3.5),
(2, '2023-05-02 23:45:00', 1, 'P7654321', 'PYZ789', 150, 4.2);


-- 2.e) Crear usuarios
CREATE ROLE usr_fabricio1;
CREATE ROLE usr_jeffrey2;
CREATE ROLE usr_benjamin3;
CREATE ROLE usr_rodrigo4;


/* DAR consulta a usuario 1 en tabla proveedor */
GRANT USAGE on SCHEMA petrogasgrupo5_3 to usr_fabricio1;
GRANT SELECT on proveedor to usr_fabricio1;

/* DAR todos las capacidades a usuario 2 en tabla ventas */
GRANT USAGE on SCHEMA petrogasgrupo5_3 to usr_jeffrey2;
GRANT SELECT , INSERT , DELETE , UPDATE , DELETE on venta to usr_jeffrey2;

/* No dar acceso a tablas a usuario 3 */
--NO es necesario hacer nada solo no darle permisos

/* Revocar toda capacidad de poder visualizar cosas en base de datos a usuario 4 */
REVOKE SELECT ON ALL TABLES IN SCHEMA petrogasgrupo5_3 FROM usr_rodrigo4;

-- 2.f) Agregar IGV
ALTER TABLE venta ADD COLUMN igv REAL DEFAULT 0.18;
