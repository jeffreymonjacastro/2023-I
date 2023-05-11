#include <iostream>
#include <vector>

using namespace std;

int repeticiones(vector<char>& v, char c){
    int sum = 0;
    for(auto i:v){
        if (i == c)
            sum++;
    }
    return sum;
}

int main(){
    vector<char> palabras{'a','a','b','b','c'};

    vector<char> no_rep;

    

    return 0;
}
