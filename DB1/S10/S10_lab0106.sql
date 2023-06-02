CREATE SCHEMA prueba_lab0106;

SET search_path TO prueba_lab0106;

CREATE TABLE Prueba(
    uid int primary key,
    c1 int,
    c2 text,
    c3 numeric,
    c4 timestamp,
    c5 interval,
    c6 int
);

-- Se insertan 1 millón de datos aleatoriamente
INSERT INTO Prueba select id,
    random()*10000,
    md5(random()::text),
    10000*random(),
    clock_timestamp(),
    (random()*1000::int||' hour')::interval,
    random()*99999
from generate_series(1,1000000) t(id);


-- EXPLAIN returna un plan de consulta y su pesos
EXPLAIN SELECT * FROM Prueba;

-- ANALYZE ejecuta la consulta y muestra el tiempo de ejecución
EXPLAIN ANALYZE
SELECT *
FROM Prueba;

-- BUFFERS muestra el uso de buffers
EXPLAIN (ANALYZE, BUFFERS)
SELECT *
FROM Prueba;

-- Se usa un EXPLAIN para ver el plan de consulta con el WHERE
EXPLAIN (ANALYZE,BUFFERS)
SELECT *
FROM Prueba
WHERE c1 > 100;


-- INDICES
/*
    CREATE INDEX nombre ON tabla(attr) USING method
    CREATE INDEX nombre ON tabla USING method(attr)
*/

-- Se crea un índice en la columna c1
CREATE INDEX idx_c1 ON Prueba USING btree(c1);

-- Apagando el sec scan
SET enable_seqscan TO off;
