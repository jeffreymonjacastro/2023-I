#include <iostream>
#include <queue>
#include <deque>

using namespace std;

class Tarea {
private:
    string nombre;
    int prioridad;
public:
    Tarea(string s, int p): nombre(s), prioridad(p){}

    bool operator<(const Tarea& otherTarea) const{
        return prioridad < otherTarea.prioridad;
    }

    friend class GestorTareas;
};

/* CON PRIORITY_QUEUE */
class GestorTareas {
private:
    priority_queue<Tarea> tareas;
public:
    GestorTareas() = default;

    void agregarTarea(const Tarea& tarea){
        tareas.push(tarea);
        cout << "Tarea agregada: " << tarea.nombre << ", Prioridad: " << tarea.prioridad << endl;
    }

    void ejecutarTareas(){
        cout << "Ejecutando tareas..." << endl;

        while(!tareas.empty()){
            cout << "Ejecutando tarea:" << tareas.top().nombre << ", Prioridad: " << tareas.top().prioridad << endl;
            tareas.pop();
        }
    }
};

/* CON DEQUE */
//class GestorTareas {
//private:
//    deque<Tarea> tareas;
//public:
//    GestorTareas() = default;
//
//    void agregarTarea(Tarea& tarea){
//        if (tarea.prioridad > tareas.front().prioridad){
//            tareas.push_front(tarea);
//        } else {
//            tareas.push_back(tarea);
//        }
//    }
//
//    void ejecutarTareas(){
//        while(!tareas.empty()){
//            cout << tareas.front().nombre << endl;
//            tareas.pop_front();
//        }
//    }
//};

int main(){
    GestorTareas gestor;

    Tarea tarea1("Tarea A", 2);
    Tarea tarea2("Tarea B", 1);
    Tarea tarea3("Tarea C", 3);
    Tarea tarea4("Tarea D", 5);
    Tarea tarea5("Tarea E", 4);

    gestor.agregarTarea(tarea1);
    gestor.agregarTarea(tarea2);
    gestor.agregarTarea(tarea3);
    gestor.agregarTarea(tarea4);
    gestor.agregarTarea(tarea5);

    gestor.ejecutarTareas(); // Salida: Tarea C, Tarea A, Tarea B


    return 0;
}