#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int contarPares(vector<int> &v, int k){
    set<int> s1;
    set<int> ans;

    for(int i = 0; i < v.size(); i++){
        s1.insert(v[i]);
    }

    for_each(s1.begin(), s1.end(), [](int x){cout << x << " ";});

    for(int i = 0; i < v.size(); i++){
        if (s1.find(v[i] + k) != s1.end()){
            ans.insert(v[i]);
        }
    }
    return int(ans.size());
}

int main(){
    vector<int> vec = {1 ,5 ,3 ,2 ,4};
    int k = 2;
    int resultado = contarPares(vec, k);
    cout << "El resultado es: " << resultado << endl;

    return 0;
}