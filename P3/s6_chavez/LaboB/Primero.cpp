#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime>
#include <forward_list>
#include <unordered_set>
#include <set>

using namespace std;

// ALGORITMO PARA CONTAR PALABRAS
void ejercicio001() {
        map<string, int> word_count;
        string word;

        while(getline(cin,word)){
            if (word.begin() == word.end())
                break;

            for (auto it = word.begin(); it != word.end(); ++it)
                *it = tolower(*it);

            word_count[word]++;
        }

        for (const auto &w : word_count){
            cout << w.first << ": ";
            cout << w.second;
            cout << (w.second > 1 ? " veces" : " vez") << endl;
        }
};


// ALGORITMO PARA HALLAR LA MODA
void ejercicio002(){
    vector<int> nums(100);

    map<int, int> hist;

    generate(nums.begin(), nums.end(), [](){return rand()%21;});
    for_each(nums.begin(), nums.end(), [](int x){cout << x << " ";});
    cout << endl;

    for (auto it = nums.begin(); it != nums.end(); it++)
        hist[*it]++;

    map<int,int>::iterator it = hist.begin();
    pair<int,int> max_pair = {(*it).first, (*it).second};

    for (auto it = hist.begin(); it != hist.end(); it++){
        if ((*it).second > max_pair.second){
            max_pair.second = (*it).second;
            max_pair.first = (*it).first;
        }
    }

    cout << "Moda: " << max_pair.first << ", con " << max_pair.second << " rep." << endl;

}


// ALGORITMO PARA MOSTRAR LOS PRIMOS NO REPETIDOS
bool es_compuesto(int x){
    if (x == 1)
        return true;

    for (int i = 2; i < x; ++i) {
        if (x % i == 0)
            return true;
    }

    return false;
}

void imprimir(int x){
    cout << x << " ";
}

void ejercicio003() {
    forward_list<int> collection;

    generate_n(front_inserter(collection), 100, []() { return rand() % 20 + 1; });

    cout << "Numeros: " << endl;
    for_each(collection.begin(), collection.end(), [](int x) { cout << x << " "; });
    cout << endl;

    collection.remove_if(es_compuesto);
    cout << "\nPrimos repetidos: " << endl;
    for_each(collection.begin(), collection.end(), [](int x) { cout << x << " "; });
    cout << endl;

    cout << "\nPrimos: " << endl;

    unordered_set<int> s(collection.begin(), collection.end());
    for_each(s.begin(), s.end(), [](int x) { cout << x << " "; });
    cout << endl;
}


// Bubblesort
void bubbleSort(vector<int>& A){
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A.size() - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A[j],A[j+1]);
}

// Ordenar una lista
void ejercicio004(){

}

int main(){
    srand(time(nullptr));
    // ejercicio001();
//     ejercicio002();
     ejercicio003();


    return 0;
}
