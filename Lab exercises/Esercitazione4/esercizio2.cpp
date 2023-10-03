#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

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

int main(){
  string fileName("dati_esp4.dat");
  vector<vector <double>> data;
  int nColumns= 4;
  bool ret_fn= ReadFile( fileName, data, nColumns);
  if (ret_fn!=true){
    return 1;
  }
  
  cout << "Nel file sono contenute " << data[0].size() << " righe" << endl;
  cout << "Nella colonna ey sono contenuti i seguenti valori: " << endl;
  for (int i=0; i<data[0].size(); i++){
  cout << data[3][i] << endl;
  }


  return 0;
}
