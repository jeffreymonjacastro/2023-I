<div align="center">
  <h1>Proyecto_Maze</h1>

  <p> ✨ En este proyecto se creará un laberinto para experimentar con los algoritmos DFS, BFS y Djisktra ✨ </p>
</div>

<details open>
  <summary>Índice:</summary>
  <ol>
    <li><a href="#acerca-del-proyecto">
      Acerca del proyecto
      <ul>
        <li><a href="#descripción">Descripción</a></li>
        <li><a href="#características">Características</a></li>
        <li><a href="#tecnologías">Tecnologías</a></li>
        <li><a href="#temas-de-interés">Temas de interés</a></li>
        <li><a href="#algoritmos-y-contenedores-utilizados">Algoritmos y contenedores utilizados</a></li>
      </ul>
    </a></li>
    <li><a href="#instalación">
      Instalación
      <ul>
        <li><a href="#requisitos">Requisitos</a></li>
        <li><a href="#pasos-de-instalación">Pasos de instalación</a></li>
      </ul>
    </a></li>
    <li><a href="#instrucciones-de-uso">
      Instrucciones de uso
    </a></li>
    <li><a href="#autores">
      Autores
    </a></li>
    <li><a href="#referencias-y-links">
      Referencias y links
    </a></li>
  </ol>
</details>

---

## Acerca del proyecto

### Descripción

Este proyecto es parte del curso de Programación III. Consiste en la creación de un laberinto aleatorio y la implementación de los algoritmos de búsqueda en profundidad (DFS), búsqueda en anchura (BFS) y Dijkstra en el lenguaje `C++` para encontrar el camino más corto en el laberinto.

### Características

+ Genera un laberinto aleatorio con un algoritmo de Backtraking. Este laberinto tiene un punto de inicio y un punto de llegada aleatorio en cada ejecución.
+ El laberinto se puede resolver utilizando los algoritmos de búsqueda en profundidad (DFS), búsqueda en anchura (BFS) o Dijkstra.

### Tecnologías

- Lenguaje de programación C++20 o posterior
- IDE: Clion 2023.1, Visual Studio Code 1.56.2, entre otros.
- Versionamiento de código: Git


### Temas de interés

- Algoritmo de Backtraking para generar laberintos aleatorios
- Búsqueda en profundidad (DFS) para encontrar el camino en el laberinto
- Búsqueda en anchura (BFS) para encontrar el camino más corto en el laberinto
- Algoritmo de Dijkstra para encontrar el camino más corto en el laberinto

### Algoritmos y contenedores utilizados

- **BFS (Breadth First Search):**

  El algoritmo de búsqueda en anchura (BFS) es una técnica utilizada para explorar y recorrer los nodos de un grafo o árbol. Comienza en el nodo raíz y explora primero los nodos vecinos en el mismo nivel antes de avanzar hacia los nodos del siguiente nivel. Para llevar a cabo este proceso, se utiliza una cola para almacenar los nodos que se van explorando en cada nivel. El BFS es particularmente útil para encontrar el camino más corto entre dos nodos, ya que examina los nodos en orden de proximidad desde el nodo de inicio.

<div align="center">
<img src= img/bfs.jpg format=jpg&name=small" width="500px">
</div>

- **DFS (Deep First Search):**

  El algoritmo de búsqueda en profundidad (DFS) es una técnica que se utiliza para recorrer y buscar nodos en un grafo o árbol. Comienza en el nodo raíz y explora un camino específico hasta llegar a un nodo que no tiene hijos. Luego, regresa al último nodo explorado y continúa explorando otros caminos posibles. El DFS se caracteriza por explorar a profundidad antes de retroceder y explorar otras ramas. Puede implementarse utilizando recursión, donde se llama a la función DFS de forma recursiva para explorar cada nodo hijo, o utilizando una pila para almacenar los nodos que se van explorando.

<div align="center">
<img src= img/dfs.jpg format=jpg&name=small" width="500px">
</div>

- **Backtracking:**

  El algoritmo de backtracking, también conocido como "vuelta atrás", es una técnica utilizada para resolver problemas de decisión en los que es necesario explorar todas las posibles soluciones. Comienza con una solución parcial y, de manera iterativa, intenta agregar elementos adicionales para avanzar hacia una solución completa. Durante este proceso, si se encuentra un callejón sin salida, se retrocede a la solución anterior y se prueba otra opción. El backtracking puede implementarse mediante recursión, donde se llama a la función de backtracking de forma recursiva para explorar las diferentes opciones, o utilizando una pila para almacenar las soluciones parciales a medida que se avanza.

<div align="center">
<img src= img/bct.png format=jpg&name=small" width="500px">
</div>

- **Stack:**

  Un stack o pila es una estructura de datos utilizada en programación donde los elementos se almacenan y acceden siguiendo el principio LIFO (último en entrar, primero en salir). Los elementos se agregan a la pila mediante la operación "push" y se eliminan mediante la operación "pop". Las pilas se utilizan en diversas aplicaciones, como el manejo de llamadas en funciones recursivas y el historial de navegadores web.

<div align="center">
<img src= img/stack.png format=jpg&name=small" width="500px">
</div>

- **Queue:**

  Una queue o cola es una estructura de datos que sigue el principio FIFO. Los elementos se añaden al final y se eliminan desde el frente. Se utilizan en aplicaciones como la impresión de documentos y el manejo de mensajes en redes de comunicación. Los elementos se procesan en el mismo orden en que se añaden, lo que garantiza un comportamiento justo y ordenado. Las colas son útiles cuando se necesita un procesamiento secuencial y justo de elementos en una secuencia determinada.

<div align="center">
<img src= img/queue.png format=jpg&name=small" width="500px">
</div>

## Instalación

### Requisitos

- **Sistema operativo:** Windows 10 o posterior
- **Procesador:** Intel Core i5-7400 o equivalente
- **Memoria RAM:** 8 GB
- **Tarjeta gráfica:** NVIDIA GeForce GTX 1050 o equivalente
- **Espacio en disco:** 1 GB

### Pasos de instalación

Para descargar el juego, se debe clonar el repositorio de GitHub en la carpeta deseada utilizando el siguiente comando:

```bash
git clone https://github.com/cs2013-2023-1/proyecto-grupo5_maze.git
git checkout main
```

## Instrucciones de uso

Para ejecutar el código, se debe abrir el archivo `main.cpp` en el IDE de preferencia y compilarlo. Luego, se debe ejecutar el archivo compilado.

## Autores

* Angel Aaron Reyes Caceres
* Brigitte Dayane Rojas Leon
* Flavio Jose Tipula Meza
* Jeffrey Antonio Monja Castro
* Valeria Celeste Valdez Campoverde

## Referencias y links

- [C++ Reference](https://en.cppreference.com/w/)
- [C++ Tutorial](https://www.cplusplus.com/doc/tutorial/)
- [C++ Documentation](https://devdocs.io/cpp/)
