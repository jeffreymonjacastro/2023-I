#include <iostream>

using namespace std;

    //template<typename T>
    //bool check_sum(T n, T m){
    //    if (n + m == 10)
    //        return true;
    //    return false;
    //}

template<typename... Ts>
bool check_sum(Ts... args){
    return ((args + args == 10) || ...);
}

int main(){
    cout << check_sum (1,9) << endl;
    cout << check_sum (1 ,2 ,5 ,6 ,7 ,2 ,1 ,3) << endl ;
    cout << check_sum (1 ,2 ,5 ,6 ,7 ,2 ,1 ,1) << endl ;
    cout << check_sum (1 ,2 ,3 ,6 ,6 ,2 ,5 ,5) << endl ;

    return 0;
}