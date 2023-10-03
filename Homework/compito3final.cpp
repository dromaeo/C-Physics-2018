#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){

//lettura del file
 ifstream ifile;
 ifile.open("temperature.dat");

 if (!ifile.good() ){
   cerr << "Errore nell'apertura del file (temperature.dat)" << endl;
   return 1;
 }

 cout << "Dati i valori inseriti nel file 'temperature.dat' si ha che: " << endl; 

 //inserimento dati nel vettore
 int n;
 ifile >> n;

 int alldaynumb=n; //numero totale dei giorni
 int temp_numb=5;  //numero delle misurazioni al giorno

 int daynumb=0;
 int temperatura=0;

 vector < vector<double> > matrix;
 for (int daynumb=0; daynumb<alldaynumb; daynumb++){
   vector<double> tmpRow;
    for (int temperatura=0; temperatura<temp_numb; temperatura++){
      double element;
      ifile >> element;
      tmpRow.push_back(element);
    }
    matrix.push_back(tmpRow);
 }
 ifile.close();

 /*
 //stampa delle temperature
 for (int daynumb=0; daynumb<alldaynumb; daynumb++){
     cout << "Le temperature del giorno " << daynumb+1 << " sono:" <<endl;
   for (int temperatura=0; temperatura<temp_numb; temperatura++){
     cout <<  matrix[daynumb][temperatura] << endl;
   }
 }
 */


 //Per ricavare la temperatura massima:
 //prima si calcola la media delle misurazioni per ogni giorno

 int cicle=0; //giorno
 double tempsum[n]; //somma temporanea
 tempsum[0]=0;
 double sum[n];
 double media[n];

 for (int cicle=0; cicle<n; cicle++) {
   for (int i=0; i<5; i++){
     tempsum[cicle] = tempsum[cicle] + matrix[cicle][i];
   }
   sum[cicle]= tempsum[cicle];
   media[cicle] = (sum[cicle] / 5);
 }


 //poi si controlla il valore più alto
 
 double hottest=0; // valore della temperatura massima
 int theday; //giorno cercato 
 int otherdays;
 cout <<"Il giorno più caldo è stato il ";
 for (int k=0; k<n; k++){
   if (media[k] > hottest){
     hottest= media[k];
     theday=k;
   }
 }
 cout << theday+1 <<  "^ "<< endl; //occorre aumentare di uno il valore perché 
                                   //a k=0 corrisponde il primo giorno
 cout <<"In tal giorno la media delle temperature era di " << hottest << "°C"<< endl; //qui si può modificare l'unità di misura considerata
   
 for (int k=0; k<n; k++){ 
   if (media[k]== hottest) {
     otherdays=k;
     if (otherdays!=theday)
     cout << "La stessa temperatura è stata trovata nel " <<  otherdays+1 << "^ giorno " << endl;
   }
 } 
 
 return 0;
}
