#include <iostream>
#include <thread>
#include <chrono>
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

    return 0;
}