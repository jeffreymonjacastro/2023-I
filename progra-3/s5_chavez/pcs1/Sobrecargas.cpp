#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}


class Racional{
private:
    int nuM;
    int denO;
public:

    explicit Racional(int n, int d){
        nuM = (n/gcd(n,d));
        denO = (d/gcd(n,d));
    }

    friend ostream& operator<<(ostream& os, Racional& r);
/*
    Racional(const Racional& other){
        this->nuM = other.nuM/gcd(other.nuM,other.denO);
        this->denO = other.denO/gcd(other.nuM,other.denO) ;
    }
*/

//
// x <- 3/2;
// x = 5/4;
// numR : int numerador , denominador
    Racional& operator=(const Racional& other){
        if( this == &other) {
            return *this;
        }

        this->nuM = other.nuM/gcd(other.nuM,other.denO);
        this->denO = other.denO/gcd(other.nuM,other.denO) ;
        return *this;
    }

    Racional operator+(const Racional& other) const{
        int n = this->nuM*other.denO + other.nuM*this->denO;
        int d = this->denO*other.denO;
        Racional temp(   n/gcd(n,d)   ,  d/gcd(n,d) );
        return temp;
    }

    Racional operator-(const Racional& other ) const{
        int n = this->nuM*other.denO - other.nuM*this->denO;
        int d = this->denO*other.denO;
        Racional temp(   n/gcd(n,d)   ,  d/gcd(n,d) );
        return temp;
    }

    Racional operator*(const Racional& other) const{
        int n = this->nuM*other.nuM;
        int d = this->denO*other.denO;

        Racional temp(   n/gcd(n,d)   ,  d/gcd(n,d) );
        return temp;
    }

    Racional operator/(const Racional& other ) const{
        int n = this->nuM*other.denO;
        int d = other.nuM*this->denO;

        Racional temp(   n/gcd(n,d)   ,  d/gcd(n,d) );
        return temp;
    }

    Racional  operator++(int) { //post-incremento
        Racional temp(*this);
        int n = this->nuM + this->denO;
        int d = this->denO;
        this->nuM = n/gcd(n,d);
        this->denO = d/ gcd(n,d);

        return temp;
    }

    Racional operator--(int){ //post - decremento
        Racional temp(*this);

        int n = this->nuM - this->denO;
        int d = this->denO;
        this->nuM = n/gcd(n,d);
        this->denO = d/ gcd(n,d);

        return temp;
    }

    Racional& operator++() { //pre-incremento
        int n = this->nuM + this->denO;
        int d = this->denO;
        this->nuM  = n/gcd(n,d);
        this->denO = d/gcd(n,d);
        return *this;
    }

    bool operator==(Racional& other) {
        this->nuM /= gcd(this->nuM,this->denO);
        this->denO /= gcd(this->nuM,this->denO);

        other.nuM /= gcd(other.nuM,other.denO);
        other.denO /= gcd(other.nuM,other.denO);


        if(this->nuM == other.nuM && this->denO == other.denO){
            return true;
        }

        else{
            return false;
        }
    }
//*this es equivalente a la clase actual.
    bool operator!=(Racional& other){
        return !(*this == other);
    }


    friend  Racional operator+=(Racional& r1, Racional& r2);

    friend Racional operator+=(Racional& r1, int x);

};

ostream &operator<<(ostream &os, Racional &r) {
    if( r.nuM < 0 || r.denO <0){
        if(r.denO != 1)
            os<<"-"<<abs(r.nuM)<<"/"<<abs(r.denO);
        else
            os<<"-"<<abs(r.nuM);
    }


    else{
        if(r.denO != 1)
            os<<r.nuM<<"/"<<r.denO;
        else
            os<<r.nuM;
    }
    return os;
}

Racional operator+=(Racional &r1, Racional &r2) {
    r1 = r1 + r2;
    return r1;
}

Racional operator+=(Racional &r1, int x) {
    Racional temp(x,1);
    r1 = r1 + temp;
    return r1;
}


int main(){
    Racional r1(3,2);
    Racional r2(2,4);

    auto r3 = r1 + r2;
    auto r4 = r1 - r2;
    auto r5 = r1*r2;
    auto r6 = r1/r2;

    r1++;
    r2--;
    cout<<"Suma: "<<r3<<endl;
    cout<<"Resta: "<<r4<<endl;
    cout<<"Multiplicacion: "<<r5<<endl;
    cout<<"Division: "<<r6<<endl;
    cout<<"Incremento: "<<r1<<endl;
    cout<<"Decremento: "<<r2<<endl;

    Racional R1(6,4);
    Racional R2(3,2);
    if(R1 == R2){
        cout<<"XD"<<endl;
    }

    R1 += R2;
    R2+=1;

    cout<<"SUMA: "<<R1<<endl;
    cout<<R2<<endl;

    auto R3 = R2;

    cout<<R3;



    return 0;
}