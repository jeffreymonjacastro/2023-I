--CREATE SCHEMA "estacion";
-- set search_path = "estacion";

/* CREACIÓN DE LA DATA */

/*
CREATE TABLE combustible(
	nombre VARCHAR(10)
);
CREATE TABLE deposito (
	id varchar(4),
	dimension VARCHAR(10),
	capacidad int,
	abastecido int,
	combustible VARCHAR(10)
);
CREATE TABLE proveedor(
	placa VARCHAR(6),
	nrolicencia VARCHAR(10)
);
CREATE TABLE abastecimiento(
	nro bigint,
	fecha date,
	depositoId VARCHAR(15),
	placa VARCHAR(6),
	nrolicencia VARCHAR(10),
	cantidad DOUBLE PRECISION,
	precio DOUBLE PRECISION
);
CREATE TABLE despachador (
	nrodocumento VARCHAR(8),
	sueldo int
);
CREATE TABLE cliente(
	nrodocumento VARCHAR(8)
);
CREATE TABLE surtidor (
	nroserie VARCHAR(12),
	lado VARCHAR(1),
	marca VARCHAR(15),
	depositoid varchar(4)
);

CREATE TABLE venta(
	nro bigint,
	nrodocumentocli VARCHAR(8),
	nrodocumentodes VARCHAR(8),
	nroserie VARCHAR(12),
	lado VARCHAR(1),
	fecha date,
	cantidad DOUBLE PRECISION,
	preciounitario DOUBLE PRECISION,
	montototal DOUBLE PRECISION
);
ALTER TABLE combustible ADD CONSTRAINT pk_combustible PRIMARY KEY (nombre);
ALTER TABLE deposito ADD CONSTRAINT pk_deposito PRIMARY KEY (id);
ALTER TABLE proveedor ADD CONSTRAINT pk_proveedor PRIMARY KEY (placa,nrolicencia);
ALTER TABLE abastecimiento ADD CONSTRAINT pk_abastece PRIMARY KEY (nro);
ALTER TABLE despachador ADD CONSTRAINT pk_despachador PRIMARY KEY (nrodocumento);
ALTER TABLE cliente ADD CONSTRAINT pk_cliente PRIMARY KEY (nrodocumento);
ALTER TABLE surtidor ADD CONSTRAINT pk_surtidor PRIMARY KEY (nroserie,lado );
ALTER TABLE venta ADD CONSTRAINT pk_venta PRIMARY KEY (nro);

ALTER TABLE deposito ADD CONSTRAINT fk_deposito_combustible FOREIGN KEY (combustible)
	REFERENCES combustible(nombre);
ALTER TABLE abastecimiento ADD CONSTRAINT fk_abastece_deposito FOREIGN KEY (depositoId)
	REFERENCES deposito(id);
ALTER TABLE abastecimiento ADD CONSTRAINT fk_abastece_proveedor FOREIGN KEY (placa,nrolicencia)
	REFERENCES proveedor(placa,nrolicencia);
ALTER TABLE surtidor ADD CONSTRAINT fk_surtidor_deposito FOREIGN KEY (depositoid)
	REFERENCES deposito(id);
ALTER TABLE venta ADD CONSTRAINT fk_venta_surtidor FOREIGN KEY (nroserie,lado)
	REFERENCES surtidor(nroserie,lado);
ALTER TABLE venta ADD CONSTRAINT fk_venta_cliente FOREIGN KEY (nrodocumentocli)
	REFERENCES cliente(nrodocumento);
ALTER TABLE venta ADD CONSTRAINT fk_venta_despachador FOREIGN KEY (nrodocumentodes)
	REFERENCES despachador(nrodocumento);

INSERT INTO combustible VALUES('GALOSINA');
INSERT INTO combustible VALUES('GAS');
INSERT INTO combustible VALUES('PETROLEO');
INSERT INTO proveedor VALUES ('ABC123','12345678');
INSERT INTO proveedor VALUES ('ABC124','12345670');

INSERT INTO deposito VALUES ('1','10x52x30',10000,0,'GALOSINA');
INSERT INTO deposito VALUES ('2','10x52x30',3000,0,'GAS');
INSERT INTO deposito VALUES ('3','10x52x30',5000,0,'PETROLEO');

INSERT INTO abastecimiento VALUES (1,(SELECT now()),'1','ABC123','12345678',100, 12);
INSERT INTO abastecimiento VALUES (2,(SELECT now()),'2','ABC123','12345678',50, 12);
INSERT INTO abastecimiento VALUES (3,(SELECT now()),'3','ABC123','12345678',50, 12);
INSERT INTO abastecimiento VALUES (4,(SELECT now()),'1','ABC124','12345670',200, 12.0);
INSERT INTO abastecimiento VALUES (5,(SELECT now()),'2','ABC124','12345670',70, 12.2);
INSERT INTO abastecimiento VALUES (6,(SELECT now()),'3','ABC124','12345670',60, 12.5);

INSERT INTO despachador VALUES ('4214154', 2000);
INSERT INTO despachador VALUES ('4214153', 2700);
INSERT INTO cliente VALUES ('000001');

INSERT INTO surtidor VALUES('S001','A','DESCONOCIDO','1');
INSERT INTO surtidor VALUES('S001','B','DESCONOCIDO','1');
INSERT INTO surtidor VALUES('S002','A','DESCONOCIDO','1');
INSERT INTO surtidor VALUES('S002','B','DESCONOCIDO','1');

INSERT INTO venta VALUES (1,'000001', '4214154','S001','A',(SELECT now()),10,12,120);
INSERT INTO venta VALUES (2,'000001', '4214154','S001','A',(SELECT now()),15,20,300);
INSERT INTO venta VALUES (3,'000001', '4214154','S001','A',(SELECT now()),2,12,24);
INSERT INTO venta VALUES (4,'000001', '4214154','S001','A',(SELECT now()),1,12,12);

*/

-- a) Elabore una función o store procedure para obtener la ventas por un mes
-- y un año especifico

-- Creación de store procedure

CREATE OR REPLACE FUNCTION get_venta_mesanio(p_mes INTEGER, p_anio INTEGER)
RETURNS TABLE (dia NUMERIC, total DOUBLE PRECISION, cant DOUBLE PRECISION)
AS
$$
BEGIN RETURN QUERY
    SELECT EXTRACT(DAY FROM fecha) AS dia,
           SUM(cantidad * preciounitario) AS total,
           SUM(cantidad) AS cant
    FROM venta
    WHERE EXTRACT(MONTH FROM fecha) = p_mes AND
          EXTRACT(YEAR FROM fecha) = p_anio
    GROUP BY Dia;
END;
$$ LANGUAGE plpgsql;

SELECT * FROM get_venta_mesanio(5, 2023);

-- SELECT now()

-- B)  Escriba una función que permita gestionar adecuadamente el stock de
-- cada combustible

CREATE OR REPLACE FUNCTION actualizarstock()
RETURNS TRIGGER AS
$$
BEGIN
    IF EXISTS(
        SELECT D.id FROM surtidor S
        INNER JOIN deposito D ON S.depositoid = D.id
        WHERE S.nroserie = NEW.nroserie AND
              S.lado = NEW.lado
    )
    THEN
        UPDATE deposito
        SET abastecido = abastecido-NEW.cantidad
        WHERE id = (
            SELECT D.id FROM surtidor S
            INNER JOIN deposito D ON S.depositoid = D.id
            WHERE S.nroserie = NEW.nroserie AND
                  S.lado = NEW.lado
            );
    END IF;
    RETURN NEW;
END;

$$ LANGUAGE plpgsql;

CREATE TRIGGER t_actualizastock
    AFTER INSERT ON venta
    FOR EACH ROW EXECUTE PROCEDURE actualizarstock();

ALTER TABLE deposito ADD CONSTRAINT abastecido_not_cero CHECK ( abastecido >= 0 );

INSERT INTO venta VALUES (9,'000001', '4214154','S002','A',(SELECT now()),10,12,120);


-- e) Escriba un store procedure para Insertar una venta

CREATE OR REPLACE PROCEDURE sp_i_venta(
    p_nrodocumentocli VARCHAR(8),
	p_nrodocumentodes VARCHAR(8),
	p_nroserie VARCHAR(12),
	p_lado VARCHAR(1),
	p_cantidad DOUBLE PRECISION,
	p_preciounitario DOUBLE PRECISION
)
    LANGUAGE plpgsql AS
$$
    DECLARE v_nro BIGINT;

    BEGIN
        v_nro := (SELECT MAX(nro) FROM venta) + 1;

        INSERT INTO venta(nro, nrodocumentocli, nrodocumentodes, nroserie,
                          lado, fecha, cantidad, preciounitario, montototal) VALUES
        (v_nro, p_nrodocumentocli, p_nrodocumentodes, p_nroserie, p_lado, (SELECT now()), p_cantidad, p_preciounitario, p_cantidad * p_preciounitario);
    END;
$$;



CALL sp_i_venta('000001','4214154','S002','A',5,12);