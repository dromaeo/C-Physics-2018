#include <iostream>
using namespace std;
int main(){
int n=10;
double v[n];
for (int i=0;i<n;i++){
cout << "Inserire v[" << i << "]: ";
cin >> v[i];
}


//somma 
double sum=0;
for (int i=0; i<n; i++){
  sum = sum + v[i];}
cout << "La somma vale " << sum << endl;


//minimo
  double min= v[0];
  for (int i=0; i<n; i++){
    if (v[i]<min){
      min= v[i];
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
