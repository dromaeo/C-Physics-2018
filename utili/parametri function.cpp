#include <iostream>
using namespace std;


/* 
   Questa funzione dimostra che il valore fornito ad una funzione dall'esterno
   viene copiato in una nuova variabile prima di essere passato alla funzione.
   In altre parole la variabile usata all'interno della funzione e' una copia
   di quella passata dall'esterno.
   Le due variabili corrispondono a due indirizzi di memoria diversi.
 */ 
void arg_by_value(int var) {
   cout << "In arg_by_value() &var = " << &var
	<< " e var = " << var << endl;
   var++;
   cout << "In arg_by_value(), dopo l'incremento, var = " << var << endl;
}


/* 
   Questa funzione dimostra che il valore fornito ad una funzione per referenza
   puo' essere modificato dalla funzione, e comporta una modifica del valore
   anche al di fuori della funzione.
   Le due variabili corrispondono allo stesso indirizzo di memoria.
 */ 
void arg_by_reference(int& var) {
   cout << "In arg_by_reference() &var = " << &var
	<< " e var = " << var << endl;
   var++;
   cout << "In arg_by_reference(), dopo l'incremento, var = " << var << endl;
}


int main() {
   
   // Esempio di passaggio "by value"
   cout << endl;
   int var1 = 19;
   cout << "L'indirizzo di valore nel main e' "
	<< &var1 << " e il suo valore e' " << var1 << endl;
   arg_by_value(var1);
   cout << "Nel main, dopo l'esecuzione di arg_by_value(), var1 = "
	<< var1 << endl;



   // Esempio di passaggio "by reference"
   cout << endl;
   int var2 = 100;
   cout << "L'indirizzo di var2 nel main e' "
	<< &var2 << " e il suo valore e' " << var2 << endl;
   arg_by_reference(var2);
   cout << "Nel main, dopo l'esecuzione di arg_by_reference(), var2 = "
	<< var2 << endl;

   return 0;
}
