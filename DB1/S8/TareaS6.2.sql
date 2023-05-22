/* TAREA LAB 6.2 */

/* INSERTANDO DATA */

/* Gist de Profe Teofilo:
    https://gist.github.com/tchambil/22e08c5d12ff575d76676b3fc188b5db
*/

-- 1. El número de proyectos que tiene cada departamento
SELECT DP.nombred, COUNT(PR.codigop) AS "Cantidad de Proyectos"
FROM proyecto PR
JOIN profesor PF ON PR.dnip = PF.dnip
JOIN diriged D ON PF.dnip = D.dnip
JOIN departamento DP ON D.codigod = DP.codigod
GROUP BY DP.nombred;

-- 2. Listar los profesores que son asesores y a la vez dirigen otros proyectos
SELECT DISTINCT PF.nombrep
FROM profesor PF
JOIN asesora A ON PF.dnip = A.dnip
JOIN proyecto P ON PF.dnip = P.dnip;

-- 3. Profesores que nunca dirigieron proyectos
SELECT DISTINCT PF.nombrep
FROM profesor PF
JOIN asesora A ON PF.dnip = A.dnip
WHERE PF.dnip NOT IN (
    SELECT PR.dnip
    FROM proyecto PR
    WHERE PR.dnip = PF.dnip
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
SELECT E.nombrees
FROM estudiante E
JOIN epregrado EPRE ON EPRE.codigoes = E.codigoes
JOIN epostgrado EPOS ON EPOS.codigoes = E.codigoes
JOIN trabajap T ON E.codigoes = T.codigoes;

-- 6. Los profesores que asesoraron mas proyectos
SELECT PF.nombrep, COUNT(PR.codigop) AS CantidadProyectos
FROM profesor PF
JOIN asesora A ON PF.dnip = A.dnip
JOIN proyecto PR ON PR.dnip = A.dnip
GROUP BY PF.nombrep
HAVING COUNT(PR.codigop) > 1
ORDER BY CantidadProyectos DESC;

-- 7. Listar cantidad de proyectos por cada años que se relazaron en UTEC.
SELECT EXTRACT(YEAR FROM PR.ffin) AS Año, COUNT(PR.codigop) AS CantidadProyectos
FROM proyecto PR
GROUP BY Año
ORDER BY Año;

-- 8. Listar todos los integrantes de ”Ciencia de la Computación” que hayan participado en algún proyecto
SELECT DISTINCT E.nombrees
FROM estudiante E
JOIN pertenece P ON E.codigoes = P.codigoes
WHERE P.codigod = 'CS'
UNION
SELECT DISTINCT PR.nombrep
FROM profesor PR
JOIN asesora A ON PR.dnip = A.dnip
JOIN trabajad T on PR.dnip = T.dnip
WHERE T.codigod = 'CS';

-- 9. Muestre el primero y segundo proyecto que tiene la mayor cantidad de participantes
SELECT PR.nombre, COUNT(T.codigoes) AS CantidadParticipantes
FROM proyecto PR
JOIN trabajap T ON PR.codigop = T.codigop
GROUP BY PR.nombre
UNION
SELECT PR.nombre, COUNT(PF.dnip) AS CantidadParticipantes
FROM profesor PF
JOIN proyecto PR ON PF.dnip = PR.dnip
GROUP BY PR.nombre


-- 10. Muestre el proyecto que tiene la mayor duración


-- 11. Muestre el cumpleaños (día, mes) y la edad del profesor/a con mayor cantidad de proyectos asesorados


-- 12. Carreras que tienen las misma cantidad de proyectos
-- 13. Muestre el departamento con la menor cantidad de proyectos en los que han trabajado
    -- por lo menos un alumno de postgrado
-- 14. Cuantos profesores entre el rango de edad de 30 a 34 a˜nos dirigen proyectos trabajados
    -- por al menos un alumno de pregrado de Ciencia de la Computaci´on
-- 15. Muestre los nombres de los alumnos de pregrado ordenados seg´un el tiempo dedicado
    -- (Considerar fecha de inicio y fin del proyecto) en el proyecto que trabajaron en el periodo
    -- 2017-2 (fecha). El resultado debe estar en orden descendente
-- 16. Listar los nombres de los departamentos ordenados seg´un la cantidad de alumnos (Pregrado y Postgrado)
    -- pertenecientes al departamento que trabajaron en un proyecto en el periodo 2020-1(fecha)
-- 17. Muestre el nombre y c´odigo de los tres primeros departamentos cuya cantidad de profesores que dirigen proyectos
    -- es mayor que el promedio. (Ejem: En el Departamento A hay 5 profesores que dirigen proyectos, en el Departamento
    -- B hay 2 y el el Departamento C hay 6 . El promedio de proyectos dirigidos por departamento es es 4. En el
    -- resultado se consideran solo a los departamentos A y C)
-- 18. Liste los primeros dos c´odigos de los departamentos con tengan mayor cantidad de estudiantes (pregrado) que
    -- trabajaron en un proyecto dirigido por un/a director/a de departamento
-- 19. Muestre la cantidad de estudiantes de pregrado por carrera universitaria que trabajaron
    -- en un proyecto en el periodo 2020-1 cuyo presupuesto sea menor al presupuesto promedio.
-- 20. Liste el ´area y nombre de los profesores que trabajen en el departamento con la menor
    -- cantidad de estudiantes que trabajen en proyectos cuyo presupuesto sea mayor a 5000

