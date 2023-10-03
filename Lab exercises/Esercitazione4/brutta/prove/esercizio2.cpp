#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool​ ReadFile(​ string​ & fileName, vector< vector<​ double​ > >& data, ​ int​ nColumns){
  ifstream file(fileName.c_str());
  if​ (!file.good()) { ​ // if open fails, print message and return false
    cerr << ​ "Failed to open file: "​ << fileName << endl;
    return​ false;
  }
  
  // Clear content of data and make its size match nColumns. This latter step
  // ensures that we can use data[i] without risking to access invalid memory
  data.clear​ ();
  data.resize(nColumns);
  
  while​ (file.good()) { ​ // loop over the rows of the file
    vector<​ double​ > row(nColumns); ​ // temp vector used to read the file
    for​ ( ​ int​ i = ​ 0 ​ ; i < nColumns; i++) ​ // read one row from file
      file >> row[i];
    if​ (!file.good()) ​ // break if the file is not good (we are at end of file)
      break​ ;
    // fill data with the values read from the file
    for​ (int​ i = ​ 0 ​ ; i < nColumns; i++)
      data[i].push_back(row[i]);
 }
  
  file.​close​ ();
  return​ true;
}


int main(int argc, char** argv){
  if(argc < 2) {
    cerr << "Invalid command line. Provide input file name" << endl;
    return 1;
  }
  
  string fileName = argv[1];
  vector <double> data;
  int nColumns = 4;
  
  bool result = ReadFile( fileName, data, nColumns);

  int nRows;
  int sum=0;
  for (int k=0; k< sum; k++) {
    data[k];
    sum= sum+k;
    nRows= sum;
  }


  cout << "Il numero di righe contenute nel file è " << nRows << endl;

  return 0;

}
