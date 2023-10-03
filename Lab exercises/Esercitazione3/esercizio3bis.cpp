#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
using namespace std;
int main(int argc, char** argv){
int n;

//lettura da terminale dei nomi del file
string   ifilename= argv[1];
string   ofilename= argv[2]; 
  
 ifstream ifile;
 ifile.open(ifilename.c_str());
 if (!ifile.good() ){
   cerr << "Errore nell'apertura del file" << endl;
   return 1;
 }


 //inserimento dati nel vettore
 ifile >> n;
 vector<double> dati(n);
 
 for (int i=0; i<n; i++){
   ifile >> dati[i];
 }

 //  calcolare:
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

 //7.errore std
 double errstd= (devstd_ad)/(sqrt(n));

 ifile.close();


 //output
 ofstream ofile;
 ofile.open(ofilename.c_str());

 ofile  << "Dati i valori inseriti si ha che: " <<endl;
 ofile << "Media: " << media
	 << " - Media dei quadrati: " << media2 <<endl;
 ofile << "Varianza: " << varianza
	 << " - Varianza empirica: " << empvar <<endl;
 ofile << "Deviazione standard: " << devstd
	 << " - Deviazione standard adattata: " << devstd_ad << endl;
 ofile << "Errore standard: " << errstd << endl;
 
 ofile.close();
   
 
 return 0;
}
