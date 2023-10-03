#include <iostream>
using namespace std;
int main()
{

   // -------------- Puntatori -------------
   int* ptr = NULL;
   cout << "ptr = " << ptr << endl;  // stampa del valore
   cout << "&ptr = " << &ptr << endl;  // stampa dell'indirizzo di memoria

   cout << endl;
   int n = 100;
   cout << "n = " << n << endl; // stampa del valore
   cout << "&n = " << &n << endl; // stampa dell'indirizzo di memoria

   cout << endl;
   ptr = &n;
   cout << "ptr = " << ptr << endl;  // stampa del valore (ora vale &n)
   cout << "&ptr = " << &ptr << endl;  // stampa dell'indirizzo di memoria

   cout << endl;
   *ptr = 19; // modifica del "valore a cui punta" ptr
   cout << "ptr = " << ptr << endl; // sempre lo stesso
   cout << "&ptr = " << &ptr << endl; // sempre &n
   cout << "*ptr = " << *ptr << endl; // vale 19
   cout << "n = " << n << endl; // anche n e' cambiato, perche' ptr punta ad &n



   
   cout << endl << endl << " REFERENZE " << endl << endl;
   // ----------- Referenze --------------------------------
   int& ref = n;
   // int& ref2; // <- Errore: deve essere inizializzata

   cout << "ref = " << ref << endl;
   cout << "&ref = " << &ref << endl;
   cout << "&n = " << &n << endl;
   
   ref = 12;
   cout << "ref = " << ref << endl; // aggiornando ref si aggiorna anche n
   cout << "n = " << n << endl; // aggiornando ref si aggiorna anche n

   cout << endl;
   ptr = &ref;
   *ptr = 9;
   cout << "n = " << n << endl;
   return 0;
}
