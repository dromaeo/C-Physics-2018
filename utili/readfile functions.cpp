#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
  A basic and a slightly more advanced example o function that reads a column
  of values from an input file.
  Try running the program "as it is" and then commenting in the main() the
  part corresponding to the simpler implementation, and uncommenting the part
  corresponding to the more advanced case.


  As a side note also try to look at the address of data inside and outside
  the simplef function GetDataNoErrorCheck(), i.e. print &data on screen in
  both cases.
  The two printed addresses are different, meaning that "returning by value"
  requires making a copy of the vector.

  The advanced version instead, passing the vector by reference, avoids this
  data copy and guarantees a better performance.
*/



// Read data from file without checking for file validity
vector<double> GetDataNoErrorCheck(string& fileName) {

   ifstream file(fileName);

   vector<double> data;
   double value;
   while(file >> value)
      data.push_back(value);

   file.close();
   return data;
}



// Read data from file after checking that file open operation was successful
bool GetDataWithErrorCheck(string& fileName, vector<double>& data) {
   
   ifstream file(fileName);
   if(!file.good())
      return false;
   
   data.clear();
   double value;
   while(file >> value)
      data.push_back(value);

   // 2 lines below would detect a failure in the middle of a file read
   // (i.e. file was open but some of its content could not be read)
   //
   // if(!file.eof())
   //    return false;
   
   file.close();
   return true;
}





int main(int argc, char** argv) {

   if(argc < 2) {
      cerr << "Invalid command line. Provide input file name" << endl;
      return 1;
   }
      
   string fileName = argv[1];
   vector<double> data;

   
   // Use version of the function that does not check file validity
   data = GetDataNoErrorCheck(fileName);


   /*
   // Use version of the function that checks file validity
   bool success = GetDataWithErrorCheck(fileName, data);
   if(!success) {
      cerr << "failed to read file: " << fileName << endl;
      return 2;
   }
   */
   
   for(int i = 0; i < data.size(); i++)
      cout << data[i] << endl;

   return 0;
}
