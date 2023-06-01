#include <bits/stdc++.h>
#include <thread>
#include <numeric>
#include <chrono>
using namespace std::chrono;
using namespace std;

struct Cipher
{   int a_;
    int b_;
    Cipher(int a , int b):a_(a),b_(b){

    }

   char  operator () (char car)
   {
        int n;
        if(car >='a' and car <= 'z')
        {
            n=(car-'a');
            int letra= n*a_+b_;
            int letra2=letra%26;
            return 'a'+letra2;
        }else if(car >='A' and car <= 'Z')
        {  n=(car-'A');
            int letra= n*a_+b_;
            int letra2=letra%26;
            return 'A'+letra2;

        }

   }
   string operator()(const string cad)
   {    string ncad="";
       int  n;
        for(auto car=begin(cad);car!=end(cad); advance(car,1))
        {
            if(*car >='a' and *car <= 'z')
            {
                n=(*car-'a');
                int letra= n*a_+b_;
                int letra2=letra%26;
                ncad+='a'+letra2;

            }else if(*car >='A' and *car <= 'Z')
            {  n=(*car-'A');
                int letra= n*a_+b_;
                int letra2=letra%26;
                ncad+='A'+letra2;
            }
        }

       return ncad;
   }





};
int main() {


   Cipher F(5, 6); // Functor para cifrar , a =5 y b =6
    cout << F('Y') << endl; // Resultado : W
    Cipher H(21, 4); // Functor para descifrar , a =21 y b =4
    cout << H(F('Y')) << endl; // Resultado : Y

 //Imprima el cifrado de ‘s ’
    string s = " PROGRAMACION ";
    cout << " Cifrando ... PROGRAMACION " << endl;
    cout<<F(s);
cout<<endl;
 //Imprima el descifrado de ‘u ’
    string u = " PYJGOCTVYATQOGSOGS " ;
    cout << " Descifrando ... PYJGOCTVYATQOGSOGS " << endl ;
    cout<<H(u);


    return 0;
}