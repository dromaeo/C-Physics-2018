#include <iostream>
using namespace std;
int main(){
  int n;
  cout << "Inserire un numero naturale: " << endl;
  cin >> n;
  
  bool primo;
  int r;
  
  for (int i=2; i<n; i++){
    r = n % i;
    if(r==0) {
      primo = false;
      break;
    }
    
    if(r!=0) {
      primo = true;
      continue;
    }
  }
  
  if (primo)
    cout << "Il numero  e` primo" << endl;
  
  else
    cout << "Il numero non e` primo" << endl;
  
  return 0;
}
