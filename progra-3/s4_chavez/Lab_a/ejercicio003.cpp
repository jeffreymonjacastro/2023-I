#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T max(vector<T> v){
    T max = v[0];
    for(int i = 1; i < v.size(); i++){
        if(v[i] > max){
            max = v[i];
        }
    }
    return max;
}

template<>
string max(vector<string> v){
    string max = v[0];
    for(int i = 1; i < v.size(); i++){
        if(v[i].length() > max.length()){
            max = v[i];
        }
    }
    return max;
}
int main(){
    vector<int> v1 = {1, 12, 33, 41, 5};
    vector<double> v2 = {1.1, 3.2, 7.3, 4.7, 9.5};
    vector<string> v3 = {"hola","mundo","cruel","c++","programacion","III"};

    cout << max(v1) << endl;
    cout << max(v2) << endl;
    cout << max(v3) << endl;


    return 0;
}
