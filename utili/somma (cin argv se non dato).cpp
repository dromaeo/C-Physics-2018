#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv){

   int n = 0;

   // se non c'e' nessun parametro nella riga di comando, chiediamo n all'utente
   if(argc < 2)
   {
      cout << "Inserire n: ";
      cin >> n;
   }
   else // altrimenti assumiamo che n sia il primo parametro fornito
      n = atoi(argv[1]);

   int sum = 0;
   for(int i = 1; i <=n; i++)
      sum += i;

   cout << "la somma dei primi " << n << " numeri naturali e' " << sum << endl;
   return 0;
}
