-- CREATE SCHEMA estación;

SET search_path TO estación;

-- PREGUNTA 2
CREATE TABLE cliente (
    dni VARCHAR(8) NOT NULL,
    nombre VARCHAR(50) NOT NULL
);

CREATE TABLE suministros (
    nro_suministro INT NOT NULL,
    tarifa VARCHAR(30) NOT NULL,
    conexion VARCHAR(30) NOT NULL,
    alimentador VARCHAR(30) NOT NULL,
    potencia INT NOT NULL,
    nivel_tension INT NOT NULL,
    medidor VARCHAR(30) NOT NULL,
    fecha DATE NOT NULL,
    direccion VARCHAR(50) NOT NULL,
    cliente_dni VARCHAR(8) NOT NULL
);

CREATE TABLE recibo_consumo (
    nro_recibo INT NOT NULL,
    mes_facturado INT NOT NULL,
    anio_facturado INT NOT NULL,
    lectura_actual INT NOT NULL,
    lectura_anterior INT NOT NULL,
    diferencia_lectura INT NOT NULL,
    factor_medidor INT NOT NULL,
    consumo_facturar INT NOT NULL,
    subtotal_facturado INT NOT NULL,
    total_importes INT NOT NULL,
    codigo_de_barra VARCHAR(50) NOT NULL,
    fecha_emision DATE NOT NULL,
    fecha_vencimiento DATE NOT NULL,
    mensajes_semi_estructurados VARCHAR(50) NOT NULL,
    nro_suministro INT NOT NULL,
    cliente_dni VARCHAR(8) NOT NULL
);

CREATE TABLE importes_facturados (
    nombre VARCHAR(50) NOT NULL,
    precio_unitario INT NOT NULL,
    importe_pagar INT NOT NULL,
    nro_recibo INT NOT NULL
);

-- RESTRICCIONES

ALTER TABLE cliente ADD CONSTRAINT cliente_pk PRIMARY KEY (dni);
ALTER TABLE suministros ADD CONSTRAINT suministros_pk PRIMARY KEY (nro_suministro);
ALTER TABLE recibo_consumo ADD CONSTRAINT recibo_de_consumo_pk PRIMARY KEY (nro_recibo);
ALTER TABLE importes_facturados ADD CONSTRAINT importes_facturados_pk PRIMARY KEY (nombre, nro_recibo);

ALTER TABLE suministros ADD CONSTRAINT suministros_cliente_dni_fk FOREIGN KEY (cliente_dni) REFERENCES cliente (dni);
ALTER TABLE recibo_consumo ADD CONSTRAINT recibo_consumo_cliente_dni_fk FOREIGN KEY (cliente_dni) REFERENCES cliente (dni);
ALTER TABLE recibo_consumo ADD CONSTRAINT recibo_consumo_suministros_nro_suministro_fk FOREIGN KEY (nro_suministro) REFERENCES suministros (nro_suministro);
ALTER TABLE importes_facturados ADD CONSTRAINT importes_facturados_recibo_consumo_nro_recibo_fk FOREIGN KEY (nro_recibo) REFERENCES recibo_consumo (nro_recibo);

ALTER TABLE recibo_consumo ADD CONSTRAINT recibo_consumo_mes_facturado_ck CHECK (mes_facturado BETWEEN 1 AND 12);
ALTER TABLE recibo_consumo ADD CONSTRAINT recibo_consumo_anio_facturado_ck CHECK (anio_facturado BETWEEN 2023 AND 2025);
ALTER TABLE recibo_consumo ADD CONSTRAINT recibo_consumo_lectura_actual_ck CHECK (lectura_actual >= 0);
ALTER TABLE recibo_consumo ADD CONSTRAINT recibo_consumo_lectura_anterior_ck CHECK (lectura_anterior >= 0);
ALTER TABLE recibo_consumo ADD CONSTRAINT recibo_consumo_diferencia_lectura_ck CHECK (diferencia_lectura >= 0);
ALTER TABLE recibo_consumo ADD CONSTRAINT recibo_consumo_factor_medidor_ck CHECK (factor_medidor >= 0);
ALTER TABLE recibo_consumo ADD CONSTRAINT recibo_consumo_consumo_facturar_ck CHECK (consumo_facturar >= 0);
ALTER TABLE recibo_consumo ADD CONSTRAINT recibo_consumo_subtotal_facturado_ck CHECK (subtotal_facturado >= 0);
ALTER TABLE recibo_consumo ADD CONSTRAINT recibo_consumo_total_importes_ck CHECK (total_importes >= 0);




INSERT INTO cliente VALUES
('12345678', 'Juan Perez'),
('87654321', 'Maria Lopez'),
('11111111', 'Pedro Gomez'),
('22222222', 'Ana Garcia'),
('33333333', 'Jose Rodriguez'),
('44444444', 'Luis Martinez'),
('55555555', 'Carlos Fernandez'),
('66666666', 'Laura Sanchez'),
('77777777', 'Miguel Gonzalez'),
('88888888', 'Sofia Diaz'),
('99999999', 'Lucia Martin');

INSERT INTO suministros VALUES
(1, 'Residencial', 'Subterránea', 'A', 10, 220, 'Monofásico', '2023-01-01', 'Calle 1', '12345678'),
(2, 'Casa', 'Subterránea', 'A', 20, 220, 'Monofásico', '2023-02-01', 'Calle 2', '12345678'),
(3, 'Departamento', 'Subterránea', 'B', 20, 220, 'Monofásico', '2023-06-08', 'Calle 2', '11111111'),
(4, 'Residencial', 'Subterránea', 'B', 20, 220, 'Monofásico', '2023-06-08', 'Calle 2', '22222222'),
(5, 'Residencial', 'Subterránea', 'B', 20, 220, 'Monofásico', '2023-06-08', 'Calle 2', '33333333');

INSERT INTO recibo_consumo VALUES
(1, 1, 2023, 100, 1, 99, 1, 100, 100, 100, '111111111', '2023-01-01', '2023-02-01', 'Mensaje 1', 1, '12345678'),
(2, 2, 2023, 200, 100, 100, 1, 100, 100, 100, '222222222', '2023-02-01', '2023-03-01', 'Mensaje 2', 2, '12345678'),
(3, 2, 2023, 200, 100, 100, 1, 100, 100, 100, '222222222', '2023-02-01', '2023-03-01', 'Mensaje 2', 2, '12345678'),
(4, 6, 2023, 300, 200, 100, 1, 100, 100, 100, '333333333', '2023-06-08', '2023-07-08', 'Mensaje 3', 3, '11111111'),
(5, 6, 2023, 400, 300, 100, 1, 100, 100, 150, '444444444', '2023-06-08', '2023-06-08', 'Mensaje 4', 4, '22222222'),
(6, 6, 2023, 500, 400, 100, 1, 100, 100, 100, '555555555', '2023-06-08', '2023-07-15', 'Mensaje 5', 5, '33333333'),
(7, 6, 2023, 600, 500, 100, 1, 100, 100, 150, '666666666', '2023-06-08', '2023-07-08', 'Mensaje 6', 1, '44444444'),
(8, 6, 2023, 700, 600, 100, 1, 100, 100, 150, '777777777', '2023-06-08', '2023-09-08', 'Mensaje 7', 2, '55555555'),
(9, 6, 2023, 800, 700, 100, 1, 100, 100, 100, '888888888', '2023-06-08', '2023-07-08', 'Mensaje 8', 3, '66666666'),
(10, 6, 2023, 900, 800, 100, 1, 100, 100, 150, '999999999', '2023-06-08', '2023-07-08', 'Mensaje 9', 4, '77777777'),
(11, 6, 2023, 1000, 900, 100, 1, 100, 100, 100, '1010101010', '2023-06-08', '2023-11-08', 'Mensaje 10', 5, '88888888'),
(13, 6, 2023, 1100, 1000, 100, 1, 100, 100, 150, '1111111111', '2023-06-08', '2023-07-08', 'Mensaje 11', 1, '99999999'),
(14, 6, 2023, 1200, 1100, 100, 1, 100, 100, 100, '1212121212', '2023-06-08', '2023-07-08', 'Mensaje 12', 2, '12345678');

INSERT INTO importes_facturados VALUES
('Cargo Fijo', 100, 100, 1),
('Cargo Fijo', 100, 100, 2),
('Importe IGV', 100, 100, 1),
('Importe Alumbrado Público', 100, 100, 2),
('Importe Consumo de energía', 100, 100, 3),
('Importe Cargo fijo', 100, 100, 4),
('Importe Mantenimiento', 100, 100, 5),
('Importe Alumbrado Público', 100, 100, 6),
('Importe Intereses Compensatorio', 100, 100, 7),
('Importe Intereses Moratorio', 100, 100, 8),
('Importe IGV', 100, 100, 9),
('Importe Consumo de energía', 100, 100, 10),
('Importe Cargo fijo', 100, 100, 11),
('Importe Alumbrado Público', 100, 100, 13),
('Importe Intereses Compensatorio', 100, 100, 1),
('Importe Intereses Moratorio', 100, 100, 2),
('Importe IGV', 100, 100, 3),
('Importe Consumo de energía', 100, 100, 4),
('Importe Cargo fijo', 100, 100, 5),
('Importe Mantenimiento', 100, 100, 6),
('Importe Alumbrado Público', 100, 100, 7),
('Importe Intereses Compensatorio', 100, 100, 8),
('Importe Intereses Moratorio', 100, 100, 9),
('Importe IGV', 100, 100, 10),
('Importe Consumo de energía', 100, 100, 11),
('Importe Mantenimiento', 100, 100, 13),
('Importe Alumbrado Público', 100, 100, 1),
('Importe Intereses Compensatorio', 100, 100, 2),
('Importe Intereses Moratorio', 100, 100, 3),
('Importe IGV', 100, 100, 4),
('Importe Consumo de energía', 100, 100, 5),
('Importe Cargo fijo', 100, 100, 6),
('Importe Mantenimiento', 100, 100, 7),
('Importe Alumbrado Público', 100, 100, 8),
('Importe Intereses Compensatorio', 100, 100, 9),
('Importe Intereses Moratorio', 100, 100, 10);

SELECT * FROM importes_facturados;
SELECT * FROM suministros;
SELECT * FROM recibo_consumo;

SELECT S.nro_suministro, C.nombre, R.mes_facturado, R.anio_facturado, R.total_importes
FROM suministros S
JOIN cliente C ON C.dni = S.cliente_dni
JOIN recibo_consumo R ON R.cliente_dni = C.dni
AND R.nro_suministro = S.nro_suministro
WHERE R.total_importes = 150
AND (R.mes_facturado = 6 OR R.mes_facturado = 7)
AND R.anio_facturado = 2023;

/*
4.a)
La complejidad operacional depende de los tipos de índices y operaciones utilizadas por los usuarios.
Una operación de INSERT que coloca datos al final de la tabla puede ser muy rápida a comparación de
una poeración de SELECT que requiere la búsqueda de datos en toda la tabla. Los índices btree, hash
entre otros pueden reducir significativamente el tiempo de búsqueda de datos. No obstante, no es
suficiente al trabajar con más de 1 millón de datos. En estos casos, es recomendable mejorar la
capacidad física de los servidores de base de datos, como por ejemplo, aumentar la memoria RAM. La
arquitectura cliente-servidor no sería suficiente para manejar una gran cantidad de datos, ya que
tardaría mucho tiempo en enviar y recibir datos entre el cliente y el servidor.

4.b)
Los grafos RDF se usan mayormente para representar datos en la web semántica. Con este modelo de
datos, se puede representar información de manera más eficiente y sencilla. Un ejemplo de tripletas
sería el siguiente: Se desea buscar el nombre de las instituciones en la que estudió el personaje
célebre Teófilo Chambilla

Tripleta:
Sujeto  |   Predicado    |   Objeto
<http://dbpedia.org/resource/Teófilo_Chambilla> <http://dbpedia.org/ontology/almaMater> ?institucion .

4.c)
Sí, es necesario modelar las reglas semánticas en otro modelo que no sea el modelo relacional. El
teorema CAP establece que un sistema distribuido no puede garantizar simultáneamente las tres
propiedades: consistencia, disponibilidad y tolerancia a particiones. Por lo tanto, es necesario
modelar las reglas semánticas en otro modelo que no sea el modelo relacional, ya que este modelo
no garantiza la tolerancia de partición de los datos.
*/

