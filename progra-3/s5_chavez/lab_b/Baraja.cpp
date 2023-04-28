#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

struct baraja {
    string figs = "CDET";


    baraja(){

    }
};

int main(){
    string figs = "CDET"; // Corazones, Diamantes, Espadas, Trebol
    vector<string> deck(52);

    int i = -1;
    generate(deck.begin(), deck.end(), [&](){
        i++;
        return to_string(i%13 + 1) + figs[i/13];
    });

    for_each(deck.begin(), deck.end(), [](string s){cout << s << " ";});
    cout<<endl;

    vector<int> vec(5);

    srand(time(nullptr));
    generate(vec.begin(),vec.end(), [](){return rand()%53;}); // El [] está vacío

    cout<<"5 cartas al azar: ";
    for_each(vec.begin(), vec.end(), [&](int x){cout << deck[x] << " ";});

    return 0;
}
