#include <iostream>
using namespace std;
int main(){

   double a = 8.0;
   double b = 4.0;

   double* ptr = NULL; // puntatore inizializzato a  zero (nessuna zona di memoria)
   cout << "ptr = " << ptr << endl;

   ptr = &a; // Faccio in modo che p punti alla locazione di memoria di a     
   cout << "Indirizzo di a: " << ptr << endl;
   cout << "Valore di a: " << *ptr << endl;

   b = *ptr;      // Assegno a b il valore puntato da p                          

   *ptr = 5.0;   // Assegno alla casella di memoria                             
                      // con indirizzo p il valore 5.0                               

   cout << "Valore di a: " << a << endl;
   cout << "Valore di b: " << b << endl;

   double v[5]={0.0, 1.0, 2.0, 3.0, 4.0};

   ptr = &v[0];
   cout << "Indirizzo di v[0]: " << ptr << endl;

   ptr = v;
   cout << "Indirizzo di v   : " << ptr << endl;

   return 0;
}
