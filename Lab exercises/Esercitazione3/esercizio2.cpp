#include <iostream>
using namespace std;

int main(){

  int n;
  cout << "Inserisci la dimensione del vettore " << endl;
  cin >> n;

  double *p = new double[n];

  cout << "Inserisci le " << n << " componenti del vettore "<< endl;
  for (int i=0; i < n;i++){
    cin >> p[i];
  }
  cout << "Puntatore alla prima componente " << p << endl;
  cout << "Componenti del vettore ";

  for (int i=0;i < n;i++){
    cout << " " << p[i];
  }
  cout  << endl;

  delete[] p;
  return 0;
}
