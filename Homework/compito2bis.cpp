#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int M=1000;

  bool primo;
  int r;

  cout << "I numeri primi da 1 a " << M  << " sono:" << endl;

  for (int n=1; n<M; n++){
    for (int i=2; i*i<=n; i++){
      r = n % i;
      if(r==0) break;
      if(r!=0) continue;
    }
    
    if (r==0){
    primo = false;}
    else {
      primo = true;}
    
    if (primo){
      cout << n << endl;
    }    
  }
  
  return 0;
}
