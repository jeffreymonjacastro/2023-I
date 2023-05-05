[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/TwNTHSBd)
# :wave: PROGRAMACIÓN III: TAREA 1C

- Apellidos: *Completar*
- Nombres: *Completar*
- Sección: *Completar*

En la presente tarea usted debe **modificar/completar** los archivos dentro de la carpeta <tt>tarea</tt>.

## Requerimientos

1. Implementar una clase para contabilizar las repeticiones de cada palabra en un sitio web.
2. No contabilizar los conectores: *the*, *for*, *a*, *to*, *was*, etc.
3. Utilizar *mapas*, *conjuntos*, *vectores*, y la librería *algorithm*.
4. Utilizar únicamente *iteradores* para acceder a los elementos de un contenedor (-3 pts).
5. El test se realizará con el sitio web: [https://norvig.com/y10k.html](https://norvig.com/y10k.html).

### 1. Palabras al azar

```
Counter C("https://norvig.com/y10k.html"); 

cout << C("think"); // Resultado: 5
cout << C("bug"); // Resultado: 7
cout << C("bugs"); // Resultado: 1
```

### 2. Ranking

```
vector<string> rank = C.ranking();

cout << rank[0];    // ilsa     (con 30 repeticiones)
cout << rank[1];    // time     (con 20 repeticiones)
cout << rank[2];    // said     (con 18 repeticiones)
cout << rank[3];    // russell  (con 16 repeticiones)
cout << rank[4];    // still    (con 10 repeticiones)
```

### 3. Stop Words

Los *tags* y *urls* no deberían ser contabilizados, unicamente el texto.

```
cout << C("<p>"); // Resultado: 0
cout << C("<html>"); // Resultado: 0
cout << C("http"); // Resultado: 0
cout << C("/"); // Resultado: 0
```

## Importante
No modificar, por ningún motivo, los archivos dentro de la carpeta <tt>test</tt>. A la hora de subir una actualización a su repositorio, **solo tendrá tres intentos**.