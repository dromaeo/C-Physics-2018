#include "PuntoMateriale.h"
#include "Vettore.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
   if(argc != 2)
   {
      cerr << "Uso: " << argv[0] << " NomeInputFile" << endl;
      return 1;
   }
   ifstream file(argv[1]);
   if(!file.good())
   {
      cerr << "Impossibile leggere il file: " << argv[1] << endl;
      return 2;
   }

   Vettore p(100, 0, 0); // posizione in cui calcolare il campo, in m
   Vettore campoTotale(0, 0, 0);  // vettore campo totale, in N/kg
   vector<PuntoMateriale> puntiMateriali;
   
   
   while(file.good()){
     vector<double> row(4);
     for(int i = 0; i < 4; i++){
       file >> row[i];
     }  
     if(!file.good()) break;
     
     PuntoMateriale punto;
     punto.Set(row[0],row[1],row[2],row[3]);
     puntiMateriali.push_back(punto);
   }
   file.close();

   double massatot=0;
   for(int i = 0; i < puntiMateriali.size(); i++){
     Vettore campo = puntiMateriali[i].CalcolaCampo(p);
     campoTotale = campoTotale + campo;
     massatot= puntiMateriali[i].GetMassa()+massatot;
   }
   cout << "Il campo in P e' g= " << campoTotale << endl;
   cout << "I punti materiali letti da file sono: " << endl;

   bool vicine= true;
   
   for(int i = 0; i < puntiMateriali.size(); i++){
     Vettore temp= puntiMateriali[i].GetPosizione();
     temp.Print();
     
     if (temp.Modulo()/p.Modulo()>0.1){
       vicine= false;
     }
   }
   if (vicine){
     cout << "Ha senso usare l'approssimazione perche' tutti i punti sono vicini all'origine" << endl;

   PuntoMateriale approx(massatot, 0, 0, 0);
   Vettore approx2= approx.CalcolaCampo(p);
   cout << "Il campo approssimato vale " << endl;
   approx2.Print();   
     }


   double M= 5.97e24;
   PuntoMateriale Terra(M, 6370000, 0, 0);
   Vettore gravT= Terra.CalcolaCampo(p);
   cout << "Considerando un punto materiale sulla Terra si verifica che la gravita' vale " << endl;
   gravT.Print();

   return 0;
}
