#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

mutex mtx;

// PREGUNTA 1:

struct Cipher {
    int a, b;
    Cipher(int _a, int _b) : a(_a), b(_b) {}

    char operator()(char c){
        int new_c = (a * (c - 'A') + b) % 26;
        return new_c + 'A';
    }

    void operator()(string& s){
        for_each(s.begin(), s.end(), [&](char c){
            int new_c = (a * (c - 'A') + b) % 26;
            cout << char(new_c + 'A');
        });
    }
};

struct antiCipher{
    int a,b;
    string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    antiCipher(int _a, int _b) : a(_a), b(_b) {}

    void operator()(string& s){
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j < alf.length(); ++j) {
                char temp = (a * (alf[j] - 'A') + b) % 26 + 'A';
                if (temp == s[i]){
                    cout << alf[j];
                }
            }
        }
    }
};

void pregunta1(){
    Cipher F(5, 6);
    cout << F('Y') << endl;

    Cipher H(21, 4);
    cout << H(F('Y')) << endl;

    string s = "PROGRAMACION";
    F(s);

    cout << endl;

    string p = "DNYKNGOGQUYT";
    F(p);

    cout << endl;



    string u = "PYJGOCTVYATQOGSOGS";
    H(u);

    cout << endl;

    cout << H('P') << endl;

    string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i=0; i<u.length()  ; i++){
        for(int j=0; j<alf.length(); j++){
            if (u[i] == H(alf[j])){
                cout << alf[j];
            }
        }
    }
    cout << endl;

//    string p = "DNYKNGOGQUYT";

    antiCipher G(5, 6);

    G(p);
}


// PREGUNTA 2:
template <typename T>
void foo (vector<T>& V) {
    int n = V.size ();
    int i = (n - 1) / 2;
    int j = n / 2;
    T tmp;
    while (i >= 0 && j <= (n-1)) {
        tmp = V [i];
        V [i] = V[j];
        V [j] = tmp ;
        i--;
        j++;
    }
}

void pregunta2(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    cout << endl;

    foo(v);

    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    cout << endl;
}

/*
    * ¿Que proceso realiza la función foo en el vector V?, mencione su hipótesis a modo de comentario.
        La función foo invierte los elementos del vector V que se le pase como parámetro. La hipótesis es que, en primer lugar, selecciona los dos elementos del medio del vector (si v tiene una cantidad par de elementos) para posteriormente cambiarlos de posición y así sucesivamente hasta que se llegue a los extremos del vector.


    * Encuentre un Invariante de Bucle que lo ayude a demostrar su hipótesis. Imprima en cada iteración
      el Invariante de Bucle para su validación.
        El invariante de bucle es: en cada iteración, el vector V tiene los elementos invertidos desde la posición i hasta la posición j.

        En la primera iteración, i es el elemento del medio del vector y j es el elemento siguiente al elemento del medio.
        En la segunda iteración, i es el elemento anterior al elemento del medio y j es el elemento siguiente al elemento que se encuentra en la posición j de la iteración anterior.

        Así sucesivamente hasta que i sea menor que 0 y j sea mayor que el tamaño del vector menos 1.

    * ¿Qué sucede al terminar el bucle?, demuestre su hipótesis utilizando el Invariante de Bucle.
        Al terminar el bucle, el vector V tiene los elementos invertidos desde la posición 0 hasta la posición n-1, donde n es el tamaño del vector V. Esto se puede demostrar utilizando el invariante de bucle, ya que al terminar el bucle, el elemento que estaba anteriormente en la posición 0 ahora está en la última posición del vector y viceversa.

    * Encuentre la complejidad algorítmica de foo.
        La complejidad algorítmica de foo es O(n), donde n es el tamaño del vector V. Esto se debe a que el bucle while se ejecuta n/2 veces, donde n es el tamaño del vector V. Además, las operaciones que se realizan dentro del bucle son de complejidad constante.
 */

// PREGUNTA 4

void random_ints (vector<int>& v, int N) {
    srand(time(nullptr));

    for (int i = 0; i < N; i ++)
        v.push_back(rand() % 200 - 100);

}

template <typename T>
void info_sec(vector<T> V, double& mean , double& std) {
    for (const T& item: V)
        mean += item;

    mean = mean / V.size();

    for (const T& item: V)
        std += pow (item - mean, 2);

    std = std / V.size();
    std = sqrt (std) ;
}

template <typename T>
void info_threads(vector<T> V, double& mean , double& std, int chunk, int chunks) {
    int inicio = (chunk) * (V.size() / chunks);
    int fin = (chunk+1) * (V.size() / chunks);

    int temp_mean = 0;
    for (int i = inicio; i < fin; i++) {
        temp_mean += V[i];
    }

    mtx.lock();
    mean += temp_mean;
    mean = mean / double(fin - inicio);
    mtx.unlock();

    double temp_std = 0;
    for (int i = inicio; i < fin; ++i) {
        temp_std += pow(V[i] - mean, 2);
    }

    mtx.lock();
    std += temp_std;
    std = std / double(fin - inicio);
    std = sqrt(std);
    mtx.unlock();
}


void pregunta4(){
    high_resolution_clock::time_point t_inicio, t_final;

    vector <int> vec;
    random_ints (vec , 10000000);

    double mean = 0.;
    double std = 0.;

    size_t n_threads = thread::hardware_concurrency();
//    size_t n_threads = 3;

    vector<thread> vthreads;

    t_inicio = high_resolution_clock::now();

    for (int i = 0; i < n_threads; ++i) {
        vthreads.emplace_back(thread(info_threads<int>, vec, ref(mean), ref(std), i, n_threads));
    }

    for (int i = 0; i < n_threads; ++i) {
        vthreads[i].join();
    }

//    info (vec , mean , std);

    t_final = high_resolution_clock::now();

    cout << "Media: " << mean << endl;
    cout << "Desviacion Estandar: " << std << endl;

    cout << "Threads: " << n_threads << endl;
    cout << "Tiempo de ejecucion: " << duration<double, milli>(t_final - t_inicio).count() << " ms" << endl;
}

int main(){
    pregunta4();

    return 0;
}