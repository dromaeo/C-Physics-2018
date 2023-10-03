#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(){
int n;

//lettura da terminale del nome del file
 string filename;
 cout << "Inserire il nome del file" << endl;
 cin >> filename;
 
 ifstream ifile;
 ifile.open(filename.c_str());
 if (!ifile.good() ){
   cerr << "Errore nell'apertura del file" << endl;
   return 1;
 }


 //inserimento dati nel vettore
 ifile >> n;
 double* dati = new double[n];
 
 for (int i=0; i<n; i++){
   ifile >> dati[i];
 }

 //calcolare:
 //1.media
double sum=0;
for (int i=0; i<n; i++){
  sum = sum + dati[i];
 }
 double media= sum/n;
 
 //2.media dei quadrati
double sum2=0;
for (int i=0; i<n; i++){
  sum2 = sum2 + pow(dati[i],2);
 }
 double media2= sum2/n;
 
 //3.varianza
 double varianza= media2 - pow(media,2);
 
 //4.varianza empirica
 double empvar= ((varianza)*(n))/(n-1);

 //5.deviazione standard
 double devstd= sqrt(varianza);

 //6.deviazione standard adattata
 double devstd_ad= sqrt(empvar);

 //7.errore standard
 double errstd= (devstd_ad)/(sqrt(n));

 ifile.close();


 //output nel file
 ofstream fileout("output.dat");

 fileout  << "Dati i valori inseriti si ha che: " <<endl;
 fileout << "Media: " << media
	 << " - Media dei quadrati: " << media2 <<endl;
 fileout << "Varianza: " << varianza
	 << " - Varianza empirica: " << empvar <<endl;
 fileout << "Deviazione standard: " << devstd
	 << " - Deviazione standard adattata: " << devstd_ad << endl;
 fileout << "Errore standard: " << errstd << endl;
 
 fileout.close();


 //deallocazione memoria
 delete[] dati;

   
 
 return 0;
}
