-- (Para crear un esquema dentro de la base de datos)
-- CREATE SCHEMA openday202210514

SET search_path = openday202210514; -- Para cambiar la consola al esquema creado

-- CREANDO TABLAS
CREATE TABLE Programa (
    Pid integer,
    Actividad varchar (50),
    Carrera varchar (50),
    Lugar varchar (255),
    Horario varchar (255)
);

CREATE TABLE Interesado (
    DNI varchar (50),
    Nombre varchar (50),
    Email varchar (50),
    Edad integer,
    Sexo varchar (1),
    Colegio varchar (255)
);

CREATE TABLE Asistencia (
    Pid integer ,
    DNI varchar (50) ,
    Hora timestamp
);


/* SELECCIONANDO LAS LLAVES */
ALTER TABLE programa ADD CONSTRAINT programa_pk_id PRIMARY KEY (pid);

ALTER TABLE interesado ADD CONSTRAINT interesado_pk_dni PRIMARY KEY (dni);

-- Una llave compuesta de dos atributos
ALTER TABLE asistencia ADD CONSTRAINT asistencia_pk_dni_id PRIMARY KEY (pid, dni);

--Para eliminar la restricción
--ALTER TABLE programa DROP CONSTRAINT programa_pk_id;


/* SELECCIONANDO LAS LLAVES FORÁNEAS */
ALTER TABLE Asistencia ADD CONSTRAINT programa_fk_id FOREIGN KEY (pid) REFERENCES programa (pid);

ALTER TABLE Asistencia ADD CONSTRAINT interesado_fk_dni FOREIGN KEY (dni) REFERENCES interesado(dni);


/* PARA QUE EL EMAIL NO SE REPITA */
ALTER TABLE Interesado ADD CONSTRAINT interesando_email_unique UNIQUE (email);


/* QUE EL NOMBRE Y EL COLEGIO SEA UN DATO OBLIGATORIO (NO NULL)*/
ALTER TABLE Interesado ALTER COLUMN nombre SET NOT NULL;


/* QUE LA EDAD ESTÉ EN EL INTERVALO 12 Y 85 */
ALTER TABLE Interesado ADD CONSTRAINT interesado_edad_check CHECK ( edad >= 12 AND edad <= 85 );


/* QUE EL ID SE AUTOGENERE */
ALTER TABLE Programa ALTER Pid ADD GENERATED ALWAYS AS IDENTITY (START WITH 1);


/* INGRESAR DATA */
INSERT INTO Programa (Actividad,Carrera,Lugar,Horario) VALUES
('RoboRally', 'Ciencia Computacion','Piso 5','10:00 a 11:00'),
('RoboRally', 'Ciencia Computacion','Piso 5','13:00 a 14:00'),
('Robots Biomédicos', 'Bioingeniería','Piso 1','12:00 a 14:00'),
('Reality Space', 'Ciencia Computacion','Piso 5','10:40 a 11:25'),
('Pensamiento Computacional', 'Ciencia Computacion','Piso 8','14:40 a 15:25');

INSERT INTO Interesado (DNI,Nombre,Email,Edad,Sexo,Colegio) VALUES
('92436099','Madaline Henson','et.euismod.et@cursus.edu',18,'M','Phasellus In Consulting'),
('52527899','Ignatius Walsh','sem.molestie@Duisatlacus.net',19,'M','Risus Quisque Inc.'),
('120571899','Alyssa Massey','erat@aliquetmolestie.org',18,'F','Euismod Urna Nullam Corporation'),
('152666099','Uriel Callahan','Aliquam.vulputate@Nullam.ca',19,'M','Tincidunt Dui Institute'),
('151856699','Jeanette Prince','ullamcorper.eu.euismod@accumsaninterdum.edu',19,'F','Pede LLC'),
('103092199','Ashton Dudley','in.hendrerit@ullamcorperviverraMaecenas.org',19,'F','Arcu Imperdiet Limited'),
('152075299','Colt Turner','vestibulum@Donec.net',16,'F','Congue Incorporated'),
('121824399','Amanda Stout','Curabitur@nonjustoProin.edu',19,'F','Ac Feugiat Non Associates'),
('181055499','Brian Potter','sed.dui@mauris.ca',17,'M','Mauris LLC'),
('192928799','Dolan Mullen','adipiscing@tellus.net',18,'M','Odio Tristique Pharetra Limited');

INSERT INTO Asistencia (Pid,DNI,Hora) VALUES
(1,'181055499','1/10/2019 0800'),
(2,'152666099','1/10/2019 0800'),
(3,'152666099','1/10/2019 0800'),
(4,'152075299','1/10/2019 0800'),
(1,'192928799','1/10/2019 0800'),
(2,'103092199','1/10/2019 0800'),
(2,'121824399','1/10/2019 0800'),
(3,'181055499','1/10/2019 0800'),
(5,'181055499','1/10/2019 0800'),
(4,'192928799','1/10/2019 0800');

/* PROBANDO LAS RESTRICCIONES */
-- INSERT INTO Interesado (DNI,Nombre,Email,Edad,Sexo,Colegio) VALUES
-- ('92436090','Madaline Henson','et.euismod.et@utec.edu',10,'M','Phasellus In Consulting');


/* CREANDO USUARIOS CON DISTINTOS ACCESOS*/
CREATE ROLE usr_202210514_1 login password 'jeff1';
CREATE ROLE usr_202210514_2 login password 'jeff2';

-- Se asigna roles
GRANT USAGE ON SCHEMA openday202210514 TO usr_202210514_1;
GRANT USAGE ON SCHEMA openday202210514 TO usr_202210514_2;

-- Se le da
GRANT SELECT ON asistencia, programa, interesado TO usr_202210514_1;
GRANT SELECT, INSERT, UPDATE, DELETE ON asistencia TO usr_202210514_2;



-- reto para la casa (MANU)