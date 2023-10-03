#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//******** funzioni ***********
bool ReadFile(string& fileName, vector< vector<double> >& data, int nColumns)
{
   ifstream file(fileName.c_str());
   if(!file.good()) { // if open fails, print message and return false
      cerr << "Failed to open file: " << fileName << endl;
      return false;
   }

   // Clear content of data and make its size match nColumns. This latter step
   // ensures that we can use data[i] without risking to access invalid memory
   data.clear();
   data.resize(nColumns);
   
   while(file.good()) { // loop over the rows of the file
      vector<double> row(nColumns); // temp vector used to read the file
      
      for(int i = 0; i < nColumns; i++) // read one row from file
     file >> row[i];

      if(!file.good()) // break if the file is not good (we are at end of file)
     break;

      // fill data with the values read from the file
      for(int i = 0; i < nColumns; i++)
     data[i].push_back(row[i]);
   }
   file.close();
   return true;
}

double S0(vector<double>& sigma){
  double sum=0;
  for (int i=0; i<sigma.size(); i++){
    sum= sum + 1/(pow(sigma[i],2));
  }
  return sum;
}

double S1(vector<double>& V1, vector<double>& sigma){
  double sum1=0;
  for (int i=0; i<sigma.size(); i++){
    sum1= sum1 + V1[i]/(pow(sigma[i],2));
  }
  return sum1;
}

double S2(vector<double>& V1, vector<double>& V2, vector<double>& sigma){
  double sum2=0;
  for (int i=0; i<sigma.size(); i++){
    sum2= sum2 + (V1[i]*V2[i])/(pow(sigma[i],2));
  }
  return sum2;
}




//********** main **********
int main(){
  string fileName("pendolo.dat");
  vector<vector <double> > data;
  int nColumns= 4;
  bool ret_fn= ReadFile( fileName, data, nColumns);
  if (ret_fn!=true){
    return 1;
  }
  
  double s0= S0 (data[3]);
  double sx= S1 (data[0], data[3]);
  double sy= S1 (data[1], data[3]);
  double sxx= S2 (data[0], data[0], data[3]);
  double sxy= S2 (data[0], data[1], data[3]);

  double den= (sxx*s0 - sx*sx);
  double m= (sxy*s0 - sx*sy)/den;
  double q= (sy*sxx - sx*sxy)/den;
  double sigma2m= s0/den;
  double sigma2q= sxx/den;

  cout << "Il valore di m e' " << m << " ± " << sqrt(sigma2m) << endl;
  cout << "Il valore di q e' " << q << " ± " << sqrt(sigma2q) << endl;

  cout << "Si nota che il valore di 4pi^2/m e' " << (4*pow(M_PI,2))/m << ", quindi compatibile con g" << endl << endl;


  
//****** estensione ******
  //chi2
  double chi_temp=0;
  double chi2=0;
  for (int i=0; i< data[0].size(); i++){
    double y = data[1][i];
    double eq = (m*(data[0][i]) +q);
    chi_temp= pow((y-eq),2) / pow(data[3][i],2);
    chi2= chi_temp + chi2;
  }

  cout << "Il valore di X^2 e' di " << chi2 << endl;
  
  //chi ridotto
  double chi_r;
  double num_liber= (data[0].size())-2;
  chi_r= chi2/ num_liber;
  
  cout << "Il valore del X^2 ridotto e' di " << chi_r << endl;
   
  return 0;
}
