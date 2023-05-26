#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

using namespace std;
using namespace std::chrono;

int suma(vector<int>& v){
    int s = 0;
    for (int i=0; i<v.size(); i++)
        s += v[i];
    return s;
}

int prod(vector<int> v){
    int p = 1;
    for (int i=0; i<v.size(); i++)
        p *= v[i];
    return p;
}

int main(){
    time_point<system_clock> t_start, t_end;

    vector<int> vec(100000000, 1);

    t_start = high_resolution_clock::now();

    future<int> res = async(prod, vec);

    cout << "Resultado = " << suma(vec) << endl;
    cout << "Resultado = " << res.get() << endl;

    t_end = high_resolution_clock::now();

    duration<double, milli> t = t_end - t_start;

    cout << "Tiempo = " << t.count() << " ms" << endl;

    return 0;
}