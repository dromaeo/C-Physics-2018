#include <iostream>
using namespace std;
int main()
{
   /* esempio di utilizzo delle variabili booleane */
   
   bool var1 = true;
   bool var2 = false;
   cout << "var1 = " << var1 << endl;
   //cout << "var2 = " << boolalpha << var2 << endl;
   cout << "var2 = " << var2 << endl;

   // operatori logici
   cout << endl;
   bool test = (true && false);
   cout << "test = " << test << endl;
   cout << "(false || true) = " << (false || true) << endl;
   int i = 9;
   cout << "(" << i << "> 0 && " << i << "< 10) = "
	<< (i > 0 && i < 10) << endl;
   cout << "(" << i << "> 0 && " << i << "< 8) = "
	<< (i > 0 && i < 8) << endl;

   // negazione
   cout << endl;
   test = !true;
   cout << test << endl;
   cout << !test << endl;

   // uso con if/else
   cout << endl;
   if(true)
      cout << "condition 1 verified" << endl;
   else
      cout << "condition 1 not verified" << endl;

   if(false)
      cout << "condition 2 verified" << endl;
   else
      cout << "condition 2 not verified" << endl;

   bool condition = true;
   if(condition)
      cout << "condition 3 verified" << endl;
   if(condition == true)
      cout << "condition 4 verified" << endl;
   if(condition == false)
      cout << "condition 5 verified" << endl;
   if( !(condition == false) )
      cout << "condition 6 verified" << endl;


   // uso con while
   cout << endl;
   bool keepCycling = true;
   int ctr = 4;
   cout << endl;
   while(keepCycling) {
      cout << "loop 1: ctr = " << ctr << endl;
      ctr--;
      if(ctr == 0)
	 keepCycling = false;
   }
   // altro modo, stesso risultato
   ctr = 4;
   cout << endl;
   while(true) {
      cout << "loop 2: ctr = " << ctr << endl;
      ctr--;
      if(ctr == 0)
	  break;
   }
   // altro modo, stesso risultato
   ctr = 4;
   cout << endl;
   while(ctr)
      cout << "loop 3: ctr = " << ctr-- << endl;
   
   // in questo caso il risultato e' diverso
   ctr = 4;
   cout << endl;
   while(ctr)
      cout << "loop 4: ctr = " << --ctr << endl;
   
   return 0;
}
