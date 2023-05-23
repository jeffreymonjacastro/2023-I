/* TAREA LAB 6.2 */

/* INSERTANDO DATA */

/* Gist de Profe Teofilo:
    https://gist.github.com/tchambil/22e08c5d12ff575d76676b3fc188b5db
*/

-- 1. El número de proyectos que tiene cada departamento

SELECT codigod , count(*) FROM (
    SELECT codigod , codigop FROM (
        (SELECT dnip , codigop FROM  proyecto)  R1
            JOIN
        (SELECT dnip, codigod FROM trabajad )  R2
            ON R1.dnip = R2.dnip
    )
) as T group by codigod;


--2. Listar los profesores que son asesores y a la vez dirigen otros proyectos
SELECT dnip, nombrep
FROM profesor
WHERE dnip IN(
    SELECT dnip
    FROM profesor
    WHERE dnip IN( SELECT dnip FROM asesora)
    AND dnip IN (SELECT  dnip FROM proyecto)
);

-- 3. Profesores que nunca dirigieron proyectos
SELECT dnip , nombrep
FROM profesor
WHERE dnip NOT IN(
    SELECT dnip
    FROM proyecto
);

-- 4. Estudiantes que trabajaron en proyectos asesorados o dirigidos por el director de carrera.
SELECT DISTINCT E.nombrees
FROM estudiante E
JOIN trabajap T ON E.codigoes = T.codigoes
JOIN proyecto P ON T.codigop = P.codigop
JOIN profesor PF ON P.dnip = PF.dnip
WHERE PF.dnip IN (
    SELECT D.dnip
    FROM diriged D
);

-- 5. Los estudiantes que están en pregrado y postgrado que trabajaron en algún proyecto
SELECT * FROM estudiante
WHERE codigoes IN(
    SELECT codigoes FROM epregrado
)
AND codigoes IN(
    SELECT codigoes FROM epostgrado
)
AND codigoes IN(
    SELECT codigoes FROM trabajap
);

--6. Los profesores que asesoraron mas proyectos

SELECT dnip,nombrep
FROM profesor
WHERE dnip IN(
    SELECT dnip
    FROM asesora GROUP BY dnip
    HAVING count(*) = (
        SELECT max(cant_pry) FROM (
            SELECT dnip , count(*) as cant_pry
            FROM asesora GROUP BY dnip
        ) as T
    )
);

--7. Listar cantidad de proyectos por cada a~nos que se relazaron en UTEC.
SELECT EXTRACT(YEAR FROM PR.ffin) AS Año, COUNT(PR.codigop) AS CantidadProyectos
FROM proyecto PR
GROUP BY Año
ORDER BY Año;

-- 8.Listar todos los integrantes de "Ciencia de la Computacion" que hayan participado en un poryecto
SELECT nombrep AS name FROM profesor
WHERE dnip IN (
    SELECT dnip FROM trabajad
    WHERE codigod = 'CS' AND (
        dnip IN (select dnip from proyecto) OR
        dnip IN (select dnip from asesora)
    )
)

UNION

SELECT nombrees as name from estudiante WHERE codigoes IN(
    SELECT codigoes from pertenece
    WHERE codigod = 'CS' and codigoes IN(
        SELECT codigoes from trabajap
    )
);

-- 9. Muestre el primero y segundo proyecto que tiene la mayor cantidad de participantes
SELECT codigop ,count(*) as cont FROM (
    (SELECT dnip as participante , codigop FROM asesora
    UNION
    SELECT codigoes as participante , codigop FROM trabajap)
    UNION
    SELECT dnip as participante , codigop FROM proyecto

) as P group by codigop order by cont DESC, codigop limit 2;


-- 10. Proyecto con mayor duracion
--todos duran lo mismo
select codigop from proyecto WHERE (ffin - finicio ) = (
    SELECT  max(ffin - finicio) FROM proyecto
);


--11. Muestre el cumpleaños (día, mes) y la edad del profesor/a con mayor cantidad de proyectos asesorados
SELECT nombrep,  extract( year  from age( now() , fnacimiento)) as edad   , extract(day from fnacimiento) as dia , extract( month from fnacimiento) as mes from profesor
where dnip in(
    select dnip  from asesora group by dnip HAVING count(*) = (
        select max(cont) from (
        select dnip , count(*) as cont
        from asesora
        group by dnip
        ) as p
    )
);

-- 12. Carreras que tienen las misma cantidad de proyectos
SELECT R1.codigod , R2.codigod from (
    SELECT codigod, count(*) as cont from (
    SELECT P.codigop , P.dnip , t.codigod  FROM proyecto P
    JOIN trabajad t on P.dnip = t.dnip
    ) as U group by codigod
) as R1  CROSS JOIN (
    SELECT codigod, count(*) as cont from (
    SELECT P.codigop , P.dnip , t.codigod  FROM proyecto P
    JOIN trabajad t on P.dnip = t.dnip
    ) as U group by codigod
) as R2 WHERE R1.cont = R2.cont and R1.codigod <> R2.codigod;

-- 13. Muestre el departamento con la menor cantidad de proyectos en los que han trabajado
    -- por lo menos un alumno de postgrado
SELECT codigod , count(*) as cont FROM (
    SELECT codigod , R1.codigop FROM (
    SELECT * FROM trabajap WHERE codigoes IN(
    SELECT codigoes FROM epostgrado
    )
    ) R1 JOIN asesora R2 ON R1.codigop = R2.codigop
    Join trabajad t on R2.dnip = t.dnip

) AS P group by codigod order by cont ,  codigod  limit 1;

-- 14. Cuantos profesores entre el rango de edad de 30 a 34 años dirigen proyectos trabajados
    -- por al menos un alumno de pregrado de Ciencia de la Computación
SELECT count(*) as cantidad_profesores  FROM (
    SELECT dnip  FROM profesor WHERE
    extract( year from age(now() , fnacimiento)) BETWEEN 30 AND 34
) AS R
WHERE  R.dnip IN(
    SELECT dnip  FROM proyecto WHERE codigop in(
    SELECT codigop FROM trabajap WHERE trabajap.codigoes IN(
            SELECT codigoes FROM pertenece WHERE codigod = 'CS'
        )
    )
);

-- 15. Muestre los nombres de los alumnos de pregrado ordenados seg´un el tiempo dedicado
     -- (Considerar fecha de inicio y fin del proyecto) en el proyecto que trabajaron en el periodo
     -- 2017-2 (fecha). El resultado debe estar en orden descendente
SELECT nombrees ,  extract(day from age(ffin , finicio)) as tiempo FROM (
    SELECT codigoes , codigop FROM trabajap WHERE fecha = '2017-2' and codigoes In(
    SELECT codigoes from epregrado
    )
) R JOIN proyecto ON R.codigop = proyecto.codigop
    JOIN estudiante ON R.codigoes = estudiante.codigoes order by tiempo DESC


-- 16. Listar los nombres de los departamentos ordenados seg´un la cantidad de alumnos (Pregrado y Postgrado)
    -- pertenecientes al departamento que trabajaron en un proyecto en el periodo 2020-1(fecha)

SELECT *
FROM (
    SELECT RANK() OVER (ORDER BY Lista.Num_alumnos DESC ) AS rango , *
    FROM (
        SELECT Po.nombre , TP.Num_alumnos
        FROM (
            SELECT P.codigop , COUNT(P.codigoes) AS Num_alumnos
            FROM trabajap P
            WHERE fecha='2021-1'
            GROUP BY P.codigop
        ) AS TP , proyecto Po
        WHERE Po.codigop = TP.codigop
    ) AS Lista
) AS tabla;

-- 17. Muestre el nombre y código de los tres primeros departamentos cuya cantidad de profesores que dirigen proyectos
    -- es mayor que el promedio. (Ejem: En el Departamento A hay 5 profesores que dirigen proyectos, en el Departamento
    -- B hay 2 y el el Departamento C hay 6 . El promedio de proyectos dirigidos por departamento es es 4. En el
    -- resultado se consideran solo a los departamentos A y C)

SELECT D.nombred , Td.Numero_prof
FROM(
    SELECT T.codigod , COUNT(P.dnip) AS Numero_prof
    FROM trabajad T
    JOIN proyecto p ON P.dnip = T.dnip
    GROUP BY T.codigod
) AS Td , departamento D
WHERE D.codigod=Td.codigod
AND Numero_prof > (
    SELECT AVG(B.Numero_prof)
    FROM (
        SELECT T.codigod , COUNT(P.dnip) AS Numero_prof
        FROM trabajad T
        JOIN proyecto p ON P.dnip = T.dnip
        GROUP BY T.codigod
    ) AS B)
ORDER BY Td.Numero_prof DESC
LIMIT 3;

-- 18. Liste los primeros dos códigos de los departamentos que tengan mayor cantidad de estudiantes (pregrado) que
    -- trabajaron en un proyecto dirigido por un/a director/a de departamento

SELECT D.codigod ,COUNT(codigoes)
FROM pertenece D
WHERE D.codigoes IN (
    SELECT E.codigoes
    FROM epregrado E
    JOIN trabajap t ON E.codigoes = t.codigoes
    JOIN proyecto Pr ON t.codigop = Pr.codigop
    JOIN diriged d2 ON Pr.dnip = d2.dnip)
GROUP BY D.codigod
LIMIT 2;


-- 19. Muestre la cantidad de estudiantes de pregrado por carrera universitaria que trabajaron
    -- en un proyecto en el periodo 2020-1 cuyo presupuesto sea menor al presupuesto promedio.

SELECT E.carrera, E.codigoes
FROM epregrado E
WHERE E.codigoes IN (
    SELECT T.codigoes
    FROM trabajap T
    WHERE T.codigoes=E.codigoes
    AND T.fecha = '2020-1'
    AND T.codigoes IN (
        SELECT T.codigoes
        FROM trabajap T, proyecto
        WHERE T.codigop IN (
            SELECT P.codigop
            FROM proyecto P )
        AND T.codigop = proyecto.codigop
    AND presupuesto < (
        SELECT AVG(presupuesto)
        FROM proyecto)
    )
);

-- 20. Liste el área y nombre de los profesores que trabajen en el departamento con la menor
    -- cantidad de estudiantes que trabajen en proyectos cuyo presupuesto sea mayor a 5000

SELECT PR.area, PR.nombrep
FROM profesor PR
JOIN trabajad T ON PR.dnip = T.dnip
JOIN departamento D ON T.codigod = D.codigod
WHERE D.codigod IN (
    SELECT D.codigod
    FROM departamento D
    JOIN pertenece P ON D.codigod = P.codigod
    JOIN trabajap T ON T.codigoes = P.codigoes
    JOIN proyecto PR ON T.codigop = PR.codigop
    WHERE PR.presupuesto > 5000
    GROUP BY D.codigod
    HAVING COUNT(P.codigoes) = (
        SELECT MIN(CantEstudiantes)
        FROM (
            SELECT COUNT(P.codigoes) AS CantEstudiantes
            FROM departamento D
            JOIN pertenece P ON D.codigod = P.codigod
            JOIN trabajap T ON T.codigoes = P.codigoes
            JOIN proyecto PR ON T.codigop = PR.codigop
            WHERE PR.presupuesto > 5000
            GROUP BY D.codigod
        ) AS conteo
    )
)







