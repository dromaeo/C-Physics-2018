#include <iostream>
using namespace std;
int main()
{
   /* esempi di base di allocazione dinamica di memoria */

   
   // creo un puntatore e gli assegno il valore NULL
   double* ptr = NULL;
   cout << "ptr = " << ptr << endl;

   // faccio un'allocazione dinamica di un double, e scrivo un valore nella
   // zona di memoria allocata
   cout << endl;
   ptr = new double;
   cout << "ptr = " << ptr << endl;
   *ptr = 100;
   cout << *ptr << endl;
   delete ptr;


   // allocazione dinamica di un array di float
   cout << endl;
   float* startPtr = new float[1000];
   float* floatVec = startPtr;
   for(int i = 0; i < 1000; i++)
      floatVec[i] = i;
   cout << floatVec[3] << endl;
   delete [] startPtr;


   return 0;
}
