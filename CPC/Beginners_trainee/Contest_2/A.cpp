// Simple Equations

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int n; cin>>n;

    vector<int> sol;

    for (int i = 0; i < n; i++){
        int y,z,a,b,c; cin>>a>>b>>c;

        for (int x = 1; x < c; ++x) {
            if ((pow(a - x, 2)-(c - pow(x, 2)))/2 == b/x){
                sol.push_back(x);
            }
        }
    }




    return 0;
}