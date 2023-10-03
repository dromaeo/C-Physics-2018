#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
   ostringstream oss;
   int giornoDelMese = 12;
   int anno = 2018;

   // un ostringstream si usa come cout e uno dei suoi scopi e' convertire
   // int, double o altro in una stringa
   oss << "oggi e' il " << giornoDelMese << " ottobre " << anno;

   string str = oss.str(); // conversione ostringstream -> stringa

   cout << str << endl;
   
   // oppure direttamente:
   //cout << oss.str() << endl;

   cout << endl << "Inizio parte istringstream" << endl << endl;

   // un istringstream si usa come cin.
   // Se si conosce il formato di una stringa, istringstream permette di
   // interpretarne il contenuto come int, double, altre stringhe, etc.
   istringstream iss("domani sara' il 13 ottobre 2018");
   string word1, word2, word3;
   int tomorrow;
   string month;
   int year;
   
   iss >> word1 >> word2 >> word3 >> tomorrow >> month >> year;

   cout << "Stringa completa: " << iss.str() << endl;
   cout << "word2: " << word2 << endl;
   cout << "Tomorrow: " << tomorrow << endl;
   cout << "Month: " << month << endl;
   cout << "Year: " << year << endl;
   
   
   return 0;
}
