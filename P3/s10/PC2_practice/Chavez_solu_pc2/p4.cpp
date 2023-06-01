#include <bits/stdc++.h>
#include <thread>
#include <numeric>
#include <chrono>
using namespace std::chrono;
using namespace std;
mutex Block;
void random_ints ( vector < int >& v , int N ) {
    for ( int i =0; i < N ; i ++)
        v . push_back ( rand () % 200 - 100) ;
}
template < typename T >
void info ( vector <T > V , double & mean , double & std ) {
    for ( const T & item : V )
        mean += item ;
    mean = mean / V . size () ;
    for ( const T & item : V )
        std += pow ( item - mean , 2) ;
    std = std / V. size () ;
    std = sqrt ( std ) ;
}

template < typename T >
void info_hilos ( vector <T > V ,int inicio, int fin , double & mean , double & std ) {
    double s=0;
    for(int i=inicio; i<fin;i++) {
        s += V[i];
    }
    Block.lock();
    mean+= s / V . size () ;
    Block.unlock();
    double s2=0;
    for(int i=inicio; i<fin;i++) {
        s2 += pow(V[i] - mean, 2);
    }
    Block.lock();
    std += s2 / V. size () ;
    std = sqrt ( std ) ;
    Block.unlock();

}
int main () {
    vector < int > vec ;
    random_ints ( vec , 10000000) ;
    double mean = 0.;
    double std = 0.;
    auto t1 = high_resolution_clock::now();
    info ( vec , mean , std ) ;
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;
    cout<<"La funcion info sin hilos toma "<< ms_double.count()<<"ms"<<endl;
    cout << " Media : " << mean << endl ;
    cout << " Desviacion Estandar : " << std << endl ;
    double mean2 = 0.;
    double std2 = 0.;

    auto t3 = high_resolution_clock::now();
   thread H1(info_hilos<int>, vec, 0,vec.size()/2,ref(mean2), ref(std2)) ;
    thread H2(info_hilos<int>, vec, vec.size()/2,vec.size(),ref(mean2), ref(std2)) ;
    H1.join();
    H2.join();
    auto t4 = high_resolution_clock::now();

    duration<double, std::milli> ms_double_2 = t4 - t3;
    cout<<"La funcion info CON hilos toma "<< ms_double_2.count()<<"ms"<<endl;
    cout << " Media : " << mean2 << endl ;
    cout << " Desviacion Estandar : " << std2 << endl ;
}
