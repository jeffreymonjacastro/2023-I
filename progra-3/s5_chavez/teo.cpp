#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Functor: Sobrecarga del operador de llamada '('

struct printString {
    char _c;
    printString(char c = ' '): _c(c) {}

    void operator() (string s){
        cout << s << _c ;
    }
};


/* Expresiones Lambda

C++ nos permite crear funciones anónimas (sin nombre). Similar a los Functors, estas son objetos de función

SINTAXIS:
[iniciador](parámetros) mutable noexcept -> tipo {cuerpo}

 * iniciador: Detalla las variables externas que puede acceder el cuerpo de la función
    - []: Ninguna variable externa es capturada
    - [lista]: Solo las variables en lista son capturadas
    - [&]: Todas las variables externas del cuerpo se capturan por referencia
    - [=]: Todas las variables externas del cuerpo se capturan por valor
 * parámetros: (Opcional). Lista de parámetros
 * mutable: (Opcional). Permite al cuerpo modificar las variables capturadas por valor
 * noexcept: (Opcional). INdica que la expresión no producirá ninguna excepción.
 * tipo: (Opcional). Tipo de retorno. Si se omite, se considera como void, a no ser que se utilice el iniciador
 * cuerpo: El cuerpo de la función.

*/

/* Librería Algorithm

Los objetos callables pueden ser utilizados en funciones predefinidas en la librería algorithm
 * for_each: Para cada elemento aplicar una función
 * generate: Insertar elementos en una lista
 * sort: Ordenar los elementos de una lista
 * find: Encontrar el índice
 * transform: Realiza una transformación a cada elemento
 * random_shuffle: Chocolatear

*/

struct C {
    int num = 0;

    void metodo(int x){
        auto f = [=]{this->num = x;};
    }
};

int fibonacci(int n){
    if (n <= 2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    printString line('\n');
    line("hola");
    line("chau");

    printString excl('!');
    excl("Ingrese un entero valido");
    cout<<endl;

    string v[4] = {"hola", "Mundo", "en", "C++"};

    // esta función recibe otra función como parámetro
    for_each(v, v+4, printString('\n'));


    // Expresiones Lambda
    C c;
    cout << "this->num = "<<c.num<<endl;
    c.metodo(5);
    cout << "this->num = "<<c.num<<endl;

    cout << "\n---------------------------------\n";

    // Librería Algorithm + Expresiones Lambda
    vector<int> vec(5);

    srand(time(nullptr));
    generate(vec.begin(),vec.end(), [](){return rand()%10;}); // El [] está vacío

    for_each(vec.begin(), vec.end(), [](int x){cout << x << " ";});

    cout << "\n---------------------------------\n";

    int n = 1;
    generate(vec.begin(), vec.end(), [&n](){return n++;}); // El [&n] tiene una variable externa

    for_each(vec.begin(), vec.end(), [](int x){cout << x << " ";});

    cout << "\n---------------------------------\n";

    generate(vec.begin(), vec.end(), [i=1]()mutable{return i*=2;}); // El [i=1] tiene una variable interna

    for_each(vec.begin(), vec.end(), [](int x){cout << x << " ";});

    cout << "\n---------------------------------\n";

    vector<string> words = {"hola", "Mundo", "en", "C++"};
    for_each(words.begin(), words.end(), [](string s){cout << s << ' ';});

    cout << "\n---------------------------------\n";

    sort(words.begin(), words.end(),[](string s1, string s2){return s1.size() < s2.size();});
    for_each(words.begin(), words.end(), [](string s){cout << s << ' ';});

    cout << "\n---------------------------------\n";

    vector<int> fibo = {1,2,3,4,5,6,7,8,9};

    transform(fibo.begin(), fibo.end(), fibo.begin(), fibonacci);

    for_each(fibo.begin(), fibo.end(), [](int x){cout << x << " ";});


    return 0;
}