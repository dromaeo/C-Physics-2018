#include "Vettore.h"

#include <iostream>

using namespace std;

// compilare con: g++ -o test_vettore test_vettore.cpp Vettore.cpp


int main() {
   Vettore v1(1,1,1);
   Vettore v2(0,2,0);
   
   v1.Print(); // (1, 1, 1)
   v2.Print(); // (0, 2, 0)
   cout << "v1 + v2 = " << v1 + v2 << endl; // (1, 3, 1)
   cout << "v1 - v2 = " << v1 - v2 << endl; // (1, -1, 1)
   cout << "vettore negato: -v1 = " << -v1 << endl; // (-1, -1, -1)
   cout << "numero*vettore: 3 * v1 = " << 3 * v1 << endl; // (3, 3, 3)

   cout << "vettore*numero: v2*2 = " << v2*2 << endl; // (0, 4, 0)
   cout << "modulo: v1 = " << v1.Modulo() << endl; // sqrt(3)
   cout << "prodotto scalare: v1*v2 = " << v1*v2 << endl; // 2

   return 0;
}
