#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Range {
private:
    T min;
    T max;
    T step;
public:
    Range(T _min, T _max, T _step): min(_min), max(_max), step(_step){};

    void print(){
        for(T i = min; i <= max; i += step){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(){
    Range<int> obj(1,10,1);



    return 0;
}