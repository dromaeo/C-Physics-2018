#include <iostream>
#include <cmath>
using namespace std;
int main (){
  double h, v, alfa_grad;
  cout << "Inserire il valore della velocita` iniziale" << endl;
  cin >> v;
  cout << "Inserire il valore dell`altezza" << endl;
  cin >> h;
  cout << "Inserire il valore dell`angolo" << endl;
  cin >> alfa_grad;

  if (alfa_grad<0 || alfa_grad>=90){
    cerr << "Errore! Inserire un angolo compreso tra 0 e 90" << endl;
  }
  if (v<=0){
    cerr << "Errore! Inserire una velocità positiva" << endl;
  }
  if (h<=0){
    cerr << "Errore! Inserire un'altezza positiva" << endl;
  }


#define g -9.81

  double alfa= ((alfa_grad)*M_PI)/180;
  
  double a= ((0.5)*g)/(pow(v,2)*pow(cos(alfa),2));
  double b= tan(alfa);
  double c= h;

  double delta= (pow(b,2))-(4*a*c);
   
  double x=((-(b)-sqrt(delta))/(2*a));

  cout << delta << endl;

  //if (alfa==0) ?
  // do while o qualcosa per togliere dist in caso errore
  
  if (a==0) {
    double x2=-c/b;
    if (b==0) {
      cout << "Errore! Controllare l'equazione inserita" << endl;
    }
    else { cout << "La distanza percorsa è d= " << x2 << endl;
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
