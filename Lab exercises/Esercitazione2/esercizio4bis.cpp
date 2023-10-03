#include <iostream>
#include <stdlib.h>
using namespace std;
int main(int argc, char** argv){
  int a;
  int b;

  //scrivendo ./es4bis a b
  a= atoi(argv[1]);
  b= atoi(argv[2]); 
    //Inserisce i due numeri

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
