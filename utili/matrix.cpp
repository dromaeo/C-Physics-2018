#include <vector>
#include <iostream>
using namespace std;

int main(){
   /* lettura di una matrice da standard input o da file */
   int nRow=3;
   int nCol=3;
   vector < vector <double> > mat;
   for (int row=0;row<nRow;row++) {
      vector<double> tmpRow;
      for (int col=0;col<nCol;col++){
	 double element;
	 cout << "Enter mat[" << row+1 << "][" << col+1 << "]: ";
	 cin >> element;
	 tmpRow.push_back(element);
      }
      mat.push_back(tmpRow);
   }
   
   for (int row=0;row<nRow;row++){
      for (int col=0;col<nCol;col++)
	 cout << mat[row][col] << " ";
      cout << endl;
   }
   // here use mat...
   return 0;
}
