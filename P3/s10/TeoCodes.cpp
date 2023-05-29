#include <iostream>
#include <vector>

using namespace std;


// PATRONES DE DISEÑO
/*
Los Patrones de Diseño proporcionan soluciones flexibles y modulares que facilitan la incorporación de cambios y la evolución del software.

- Ejemplo de Patrones de Creación:
    * Singleton, Abstract factory, Builder, Factory Method
    *
- Ejemplo de Patrones de Estructura:
    * Adapter, Bridge, Composite, Decorator, Facade, Flyweight, Proxy
    *
- Ejemplo de Patrones de Comportamiento:
    * Strategy, Template Method, Chain of Responsibility, Command, Iterator, Mediator, Memento, Observer, State, Visitor
    *
*/

/* MODIFICADOR STATIC EN C++ */
// Es una palabra reservada para asignar una variable o función a un ámbito global.
// Si declaramos un método estático, se debe trabajar con atributos estáticos

class Foo {
public:
    static int x;
};

int Foo::x = 3; // Inicialización de la variable estática global

void ejemplo001(){
    Foo obj1;
    cout << obj1.x << endl;

    Foo obj2;
    cout << obj2.x << endl;
}

/*
SINGLETON
 - El patrón singleton garantiza que solo exista una única instancia de una clase en todo el programa
 - Resuelve el problema de tener múltiples instancias de una clase que deben compartir un estado común
 - Implementación
    1. Privatizar el constructor de la clase
    2. Definir una variable estática privada que contenga la única instancia de la clase
    3. Proporcionar un método público estático que permita obtener la instancia única

 */

class Singleton {
private:
    static Singleton* instance;

    // Constructor privado
    Singleton(){}

public:
    // Método público estático que permite obtener la instancia única
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

void ejemplo002(){
    // Uso del singleton
    Singleton* instance = Singleton::getInstance();
}

int main(){
    Singleton* instance = Singleton::getInstance();

    return 0;
}