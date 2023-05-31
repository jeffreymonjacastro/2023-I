#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

/* TEMAS PC2:
    -> Callables y Librería Algorithm
    * Contenedores e Iteradores
    * Complejidad Algoritmica e Invariante de Bucle
    * Programación Concurrente
*/

/*
    PRIMER TEMA: CALLABLES Y LIBRERÍA ALGORITHM
    -> Callable: Es un objeto que puede ser invocado como una función
        - Funciones
        - Punteros a funciones
        - Functores
        - Lambdas
*/

/*
    -> Funciones Callback: Son punteros a funciones
      - Útil para crear varias funciones con los mismos parámetros
*/

int suma(int x1, int x2){
    return x1 + x2;
}

int resta(int x1, int x2){
    return x1 - x2;
}

void calculadora(int (*f)(int, int), int x1, int x2){
    cout << "El resultado es: " << f(x1, x2) << endl;
}

void ejemplo001(){
    // Llamando a la función calculadora y pasando como parámetro el puntero a una función
    calculadora(suma, 5, 3);
    calculadora(resta, 5, 3);

    // Declarando un puntero a función
    int (*pf)(int, int);
    pf = suma;
    cout << pf(5, 3) << endl;
    pf = resta;
    cout << pf(5, 3) << endl;
}

/*
    -> Functores: Son objetos que se comportan como funciones
        - Primero, se declara un objeto a través de su constructor
        - Segundo, se sobrecarga el operador ()
        - Tercero, se llama al objeto como si fuera una función
*/

// Con struct
struct print {
    char c = ' '; // Atributo de clase

    print(char _c): c(_c) {} // Constructor de clase

    void operator()(string s){ // Sobrecarga del operador ()
        cout << s << c;
    }
};

// Con class
class print2 {
private:
    char c = ' '; // Atributo de clase
public:
    print2(char _c): c(_c) {} // Constructor de clase

    void operator()(string s){ // Sobrecarga del operador ()
        cout << s << c;
    }
};

void ejemplo002(){
    print p1('\n');
    p1("Hola mundo");

    print2 p2('?');
    p2("Hola mundo");
}

/*
    -> Lambdas: C++ nos permite crear funciones anónimas (sin nombre)

    SINTAXIS:
    [iniciador](parámetros) mutable noexcept -> tipo {cuerpo}

     * iniciador: Detalla las variables externas que puede acceder el cuerpo de la función
        - []: Ninguna variable externa es capturada
        - [lista]: Solo las variables en lista son capturadas
        - [&]: Todas las variables externas del cuerpo se capturan por referencia
        - [=]: Todas las variables externas del cuerpo se capturan por valor
     * parámetros: (Opcional). Lista de parámetros
     * mutable: (Opcional). Permite al cuerpo modificar las variables capturadas por valor
     * noexcept: (Opcional). Indica que la expresión no producirá ninguna excepción.
     * tipo: (Opcional). Tipo de retorno. Si se omite, se considera como void, a no ser que se utilice el iniciador
     * cuerpo: El cuerpo de la función.
*/

struct C {
    int num = 0; // Atributo de clase

    void metodo(int x){ // Método de clase
        auto f = [=]{this->num = x;}; // Lambda que captura el atributo num y this por valor
        f(); // Llamando a la lambda
    }
};

void ejemplo003(){
    C obj;
    cout << obj.num << endl;
    obj.metodo(5);
    cout << obj.num << endl;
}

/*
    -> Librería Algorithm
    Los objetos callables pueden ser utilizados en funciones predefinidas en la librería algorithm
     * generate: Insertar elementos en una lista
     * for_each: Para cada elemento aplicar una función
     * transform: Realiza una transformación a cada elemento
     * sort: Ordenar los elementos de una lista
     * find: Encontrar el índice de un elemento en una lista
     * random_shuffle: Chocolatear
     * etc...
*/

// Generate
void ejemplo004(){
    vector<int> v(10);

    // Generando números aleatorios dentro del vector v
    generate(v.begin(), v.end(), []{return rand() % 100;});

    // Imprimiendo el vector v
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    cout << endl;

    // Transformando cada valor i del vector v en i*2
    transform(v.begin(), v.end(), v.begin(), [](int x){return x * 2;});
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    cout << endl;

    // Ordenando el vector v en base a la condición que el elemento v[i] sea menor al elemento v[j]
    sort(v.begin(), v.end(), [](int x, int y){return x < y;});
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    cout << endl;

    // Find devuelve un iterador al elemento encontrado, se debe dereferenciar
    auto it = find(v.begin(), v.end(), 124);
    cout << *it << endl;

    // Suffle mezcla los elementos del vector con una función
    shuffle(v.begin(), v.end(), mt19937(random_device()()));
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    cout << endl;
}



int main(){
//    ejemplo001();
//    ejemplo002();
//    ejemplo003();
    ejemplo004();

    return 0;
}
