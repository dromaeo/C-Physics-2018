#include <iostream>
#include <cmath>
#include <TF1.h>
using namespace std;

int main (){
  cout << "Inserire la funzione di cui si vuole trovare lo zero" << endl;
  string fun;
  cin >> fun;
  TF1 f("f", fun.c_str());
  double a;
  double b;
  cout << "Inserire gli estremi dell'intervallo" << endl;
  cin >> a >> b;
  double prec;
  cout << "Inserire la precisione con cui si vuole calcolare il risultato"
       << endl << "(tanto è minore tanto è più preciso il valore trovato)" << endl;
  cin >> prec;
  double fzero;
  double iter=0;

  //casi particolari
  if (a>b){
    a= b;
    b= a;
  }
  if (f(a)*f(b)>=0){
    cout << "L'intervallo [" << a << "," << b << "] non contiene uno zero!" << endl;

    return 2;
  }

  //main
  do {
    double x_m= 0.5*(a+b);
    if (f(x_m)==0){
      fzero= x_m;
    }
    else {
      if (f(a)*f(x_m)<0) {
	b= x_m;
      }
      else {
	a= x_m;
      }
      fzero= 0.5*(a+b);
      iter++;
    }
  } while ((b-a)>prec);


  cout << "La funzione ha zero in x= " << fzero << endl;
  cout << "Numero di iterazioni: " << iter << endl;
}


