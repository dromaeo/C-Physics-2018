#include <iostream>
#include <cmath>
using namespace std;
int main (){
  double h, v, alfa;
  cout << "Inserire il valore della velocita` iniziale" << endl;
  cin >> v;
  cout << "Inserire il valore dell`altezza" << endl;
  cin >> h;
  cout << "Inserire il valore dell`angolo" << endl;
  cin >> alfa;

 
  #define g 9.81
 
  double a= ((-1/2)*g)/(pow(v,2)*pow(cos(alfa),2));
  double b= tan(alfa);
  double c= h;

  double delta= (pow(b,2))-(4*a*c);
  
  double x=((-(b)+sqrt(delta))/(2*a));

 
  if (v==0 || cos(alfa)==0) {
    cout << "Errore! La soluzione non esiste" << endl;
    }
 
  if (a==0) {double x2=-c/b;
    if (b==0) {
      cout << "Errore! La soluzione non esiste" << endl;
    }
    else { cout << "La distanza percorsa é d= " << x2 << endl;
        }
    }
 
  if (a!=0){
if (delta<0){
      cout << "La soluzione è un numero complesso" << endl;
  }
else {
  cout << "La distanza percorsa è d= " << x << endl;
 }
   }
 
  return 0;}
