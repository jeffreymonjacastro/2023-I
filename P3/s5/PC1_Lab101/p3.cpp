#include <iostream>

using namespace std;

    //template<typename T>
    //bool check_sum(T n, T m){
    //    if (n + m == 10)
    //        return true;
    //    return false;
    //}

template<typename T1>
bool check_sum(T1 first, T1 second){
    if( first + second == 10){
        return true;
    }
    else
        return false;
}


template<typename T, typename ... Args>
bool check_sum(T first, Args ... arg){
    bool vand = false;

    ((first + arg == 10 ? (vand = true) : (arg)), ...);

    if(vand){
        return true;
    }
    else{
        return check_sum(arg...);
    }


}

int main(){
    cout << check_sum (1,9) << endl;
    cout << check_sum (1 ,2 ,5 ,6 ,7 ,2 ,1 ,3) << endl ;
    cout << check_sum (1 ,2 ,5 ,6 ,7 ,2 ,1 ,1) << endl ;
    cout << check_sum (1 ,2 ,3 ,6 ,6 ,2 ,5 ,5) << endl ;

    return 0;
}