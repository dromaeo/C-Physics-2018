#include <fstream>  // per ifstream
#include <iostream> // per cout
using namespace std;

/*
 * Questo programma dimostra la lettura da file tramite ifstream.
 * In questo esempio si assume che il formato del file di input sia il seguente
 * 
 * N
 * valore1
 * valore2
 * ...
 * valoreN
 */

int main()
{
   ifstream file("dati1.dat");
   int N;
   file >> N;

   for(int i = 0; i < N; i++)
   {
      int valore;
      file >> valore;
      cout << valore << endl;
   }
   file.close();
   return 0;
}
