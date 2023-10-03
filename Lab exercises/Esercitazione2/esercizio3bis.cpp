#include <iostream>
#include <fstream>
using namespace std;
int main(){
int n=10;
double v[n];

 ifstream file1("vettori.dat");
for (int i=0;i<n;i++){
 file1 >> v[i];
 }

 
//somma 
double sum=0;
for (int i=0; i<n; i++){
  sum = sum + v[i];}
 cout  << "Dati i valori inseriti in vettori.dat si ha che: "
      << endl << "La somma vale " << sum << endl;


//minimo
  double min= v[0];
  for (int i=0; i<n; i++){
    if (v[i]<min){
      min=v[i];
	}
  }
    cout << "Il minimo vale " << min << endl;
  
  


 //massimo
  double max= v[0];
    for (int i=0; i<n; i++) {
	if (v[i]>max){
	  max= v[i];
	}
    }
    cout << "Il massimo vale " << max << endl;
	
  
 return 0;
}
