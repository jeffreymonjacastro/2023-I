SET search_path TO cs2041;

SELECT * FROM alumno;

UPDATE alumno SET nombres = 'juasjuas' WHERE codigo = '202120604';

SELECT column_name
FROM information_schema.columns
WHERE table_schema = "current_schema"();

INSERT INTO alumno (codigo, nombres, pc1, pc2, pc3, promedio) VALUES
('202120604', 'Juan Tipula', 20.0, 20.0, 20.0, 15.5),
('202120604', 'Juan Tipula', 20.0, 20.0, 20.0, 15.5),
('202120604', 'Juan Tipula', 20.0, 20.0, 20.0, 15.5),
('202120604', 'Juan Tipula', 20.0, 20.0, 20.0, 15.5),
('202120604', 'Juan Tipula', 20.0, 20.0, 20.0, 15.5),
('202120604', 'Juan Tipula', 20.0, 20.0, 20.0, 15.5);


SELECT * FROM alumno;


CREATE TABLE ojito(
    id VARCHAR(50),
    nombre VARCHAR(50),
    apellido VARCHAR(50),
    edad INTEGER
);


GRANT USAGE ON SCHEMA cs2041 TO usr_practica;

GRANT SELECT, INSERT, UPDATE, DELETE ON ALL TABLES IN SCHEMA cs2041 TO usr_practica;