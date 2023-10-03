#include <iostream>
#include <cmath>
using namespace std;
int main (){
  double a, b, c;
  cout << "Inserire il valore dei coefficienti a, b e c per risolvere ax^2+bx+c=0" << endl;
  cin >> a >> b >> c;
  double delta= (pow(b,2))-(4*a*c);
  double x1=((-(b)+sqrt(delta))/(2*a));
  double x2=((-(b)-sqrt(delta))/(2*a));
  if (a==0) {double x=-c/b;
    if (b==0) {
      cout << "Errore! La soluzione non esiste poiché sarebbe data da una divisione per 0 (a=0 e b=0, dunque x=-c/b)" << endl;
    }
    else { cout << "La soluzione é x= " << x << endl;
        }
    }

  if (a!=0){
if (delta<0){
      cout << "La soluzione è un numero complesso (poiché il delta é negativo)" << endl;
  }
else if (delta==0) {
  cout << "La soluzione è x= " << x1 << endl; /*x1=x2*/
 }
 else if (delta>0){
   cout << "Le soluzioni sono x1=" << x1 << " e x2=" << x2 << endl;
 }
  }
 
  return 0;}
