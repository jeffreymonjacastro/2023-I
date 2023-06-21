-- SET search_path TO labS13_2006;

-- GIST: https://gist.github.com/tchambil/f8d3d77937ae1f850403a5561a71d9c4


-- P2: Primary Key

ALTER TABLE candidato ADD CONSTRAINT candidato_pk PRIMARY KEY (partido);
ALTER TABLE centrovotacion ADD CONSTRAINT centrovotacion_pk PRIMARY KEY (codigo);
ALTER TABLE votosporcentro ADD CONSTRAINT votosporcentro_pk PRIMARY KEY (candidato, centro);

-- P3:

INSERT INTO VotosPorCentro (
    SELECT c.nombre, d.id, null, 0
	FROM distrito d, candidato c
);

INSERT INTO SedeDepartamental(
    SELECT d.id, 0
    FROM departamento d
);

INSERT INTO SedeProvincial(
    SELECT p.id,0
    FROM provincia p
);

INSERT INTO CentroVotacion(
    SELECT d.ID, 0, null, (
        SELECT count(c.partido)
        FROM candidato c), 0, 0
    FROM Distrito d
);

--Inicialice sus tablas--
-- CREATE TABLE votos1(
--     candidato varchar(120),
--     centro varchar(6) NOT NULL,
--     HoraReporte timestamp without time zone,
--     votos int
-- );
--
-- INSERT INTO votos1 (
--     SELECT c.nombre,d.id, (SELECT now()), (floor(random()*(10-0+1))+0)
--     FROM distrito D, candidato C
-- );

 -- total de tuplas iniciales
-- SELECT COUNT(*) FROM VotosPorCentro; -- 43102
-- SELECT COUNT(*) FROM SedeDepartamental; -- 25
-- SELECT COUNT(*) FROM SedeProvincial; -- 196
-- SELECT COUNT(*) FROM CentroVotacion; -- 1874
-- SELECT COUNT(*) FROM votos1; -- 43102


START TRANSACTION;
--creando table votos1
CREATE TABLE Votos1(
	candidato varchar(120),
	centro varchar(6) NOT NULL,
	HoraReporte timestamp without time zone ,
	votos int
);

--CREANDO VOTOS1
INSERT INTO Votos1 (
	SELECT NOMBRE, ID, (select now()), (floor(random() * (10 - 0 + 1)) + 0)
	FROM Distrito D, Candidato C
);


--actualizando votos por centro con votos1
UPDATE VotosPorCentro
	SET ultimareporte = Votos1.horareporte, votos = Votos1.votos
	FROM Votos1
	WHERE VotosPorCentro.candidato = Votos1.candidato
	AND VotosPorCentro.centro = Votos1.centro;

--actualizando reportado de SedeProvincial con votos1
UPDATE SedeProvincial SET reportado = P.votos
FROM (
	 SELECT SUM(votos) AS votos, provinciaid
	 FROM Votos1 v1 INNER JOIN distrito d ON v1.centro = d.id
	 GROUP BY provinciaid
	 ) P
WHERE codigo = P.provinciaid;

--actualizando reportado de SedeDepartamental con votos1
UPDATE SedeDepartamental SET reportado = D.votos
FROM (
	 SELECT SUM(votos) AS votos, departamentoid
	 FROM Votos1 v1 INNER JOIN distrito d ON v1.centro = d.id
	 GROUP BY departamentoid
	 ) D
WHERE codigo = D.departamentoid;

--actualizando reportado de CentroVotacion con votos1
UPDATE CentroVotacion SET reportado = CV.votos
FROM (
    SELECT SUM(votos) AS votos, centro
    FROM Votos1
    GROUP BY centro
	) CV
WHERE codigo = CV.centro;


--actualizando totalvotos de candidato con votos1
UPDATE Candidato SET totalvotos = C.votos
FROM (
    SELECT SUM(votos) AS votos, candidato
    FROM Votos1
    GROUP BY candidato
	) C
WHERE nombre = C.candidato;

COMMIT;


-- P5:


START TRANSACTION;
--creando tabla votos2
CREATE TABLE Votos2(
	candidato varchar(120),
	centro varchar(6) NOT NULL,
	HoraReporte timestamp without time zone ,
	votos int
);

--VOTOS2 = VOTOS1 + NuevosVotos hasta esa hora.

INSERT INTO Votos2(
    SELECT v1.candidato,v1.centro,(SELECT NOW()), (v1.votos+Tmptb.nuevosvotos) as total
    FROM (
        SELECT D.ID as centro,c.nombre as candidato, (floor(random() * (10 - 0 + 1)) + 0) as nuevosvotos
        FROM Distrito D, Candidato C
        ) Tmptb, votos1 v1
    WHERE Tmptb.candidato = v1.candidato
         AND Tmptb.centro = v1.centro);

--actualizando votos por centro con Votos2
UPDATE VotosPorCentro
	SET ultimareporte = Votos2.horareporte, votos = Votos2.votos
	FROM Votos2
	WHERE VotosPorCentro.candidato = Votos2.candidato
		  AND VotosPorCentro.centro = Votos2.centro;

--actualizando totalvotos de candidato con votos1
UPDATE Candidato SET totalvotos =  C.votos
FROM (
		SELECT SUM(votos) AS votos, candidato
		FROM Votos2
		GROUP BY candidato
	) C
WHERE nombre = C.candidato;

--actualizando reportado de SedeProvincial con Votos2
UPDATE SedeProvincial SET reportado = P.votos
FROM (
	 SELECT SUM(votos) AS votos, provinciaid
	 FROM Votos2 v2 INNER JOIN distrito d ON v2.centro = d.id
	 GROUP BY provinciaid
		) P
WHERE codigo = P.provinciaid;

--actualizando reportado de SedeDepartamental con Votos2
UPDATE SedeDepartamental SET reportado = D.votos
FROM (
	 SELECT SUM(votos) AS votos, departamentoid
	 FROM Votos2 v2 INNER JOIN distrito d ON v2.centro = d.id
	 GROUP BY departamentoid
	 ) D
WHERE codigo = D.departamentoid;

--actualizando reportado de CentroVotacion con Votos2
UPDATE CentroVotacion SET reportado = CV.votos
FROM (
		SELECT SUM(votos) AS votos, centro
		FROM Votos2
		GROUP BY centro
	) CV
WHERE codigo = CV.centro;
COMMIT;