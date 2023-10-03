#include <iostream> 
#include <cmath> 
using namespace std; 
int main() {
   double area; 
   cout << "Dammi l'area del quadrato: " << endl; 
   cin >> area; 
   if (area>=0){ 
      double lato = sqrt(area); 
      cout << "Il lato vale: " << lato << endl; 
   } else { 
      cout << "Area negativa ! " << endl; 
   } 
   return 0;
}
