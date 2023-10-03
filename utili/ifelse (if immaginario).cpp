#include <iostream>
#include <cmath>
using namespace std;

int main() {
   double area;
   cout << "Introdurre L'area del quadrato: ";
   cin >> area;

   if(area < 0)
   {
      double lato = sqrt(-area);
      cout << "Il lato e' immaginario: " << lato << "i" << endl; 
   }
   else if(area = 0) // che succede se scrivo per errore "if(area = 0)"?
   {
      // c'e' una sola riga, potrei togliere le graffe
      cout << "Il lato vale zero" << endl;
   }
   else
   {
      double lato = sqrt(area);
      cout << "Il lato vale " << lato << endl;
   }


   return 0;
}
