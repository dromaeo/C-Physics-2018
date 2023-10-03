#include <iostream>
using namespace std;
int main(){
  int a;
  int b;
  
  cout << "Inserire i due numeri: " << endl;
  cin >> a >> b;
  
    if (b==0){
      cout << "Il massimo comun divisore è= " << a << endl;}

  else {
      
    while(b != 0) {
      int r = a % b; //resto
	 
         a = b; 
         b = r;

    }
	   cout << "Il massimo comun divisore è= " << a << endl;
 
  }

    return 0;
}
