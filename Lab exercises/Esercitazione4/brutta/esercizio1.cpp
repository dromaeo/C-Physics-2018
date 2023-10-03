#include <iostream>
using namespace std;

double PassByValue(int val) {
   cout << "In PassByValue() &val " << &val << endl;
   double result = 0.45*val;
   val = 0;
   return result;
}

double PassByReference(int& val) {
   cout << "In PassByReference() &val " << &val << endl;
   double result = 0.45*val;
   val = 0;
   return result;
}

int main(int argc, char** argv) {
   // Changes to a parameter passed by value have no effect outside the
   // body of the function
   cout << endl;
   int var1 = 9;
   cout << "Before PassByValue() var1 = " << var1
    << ", &var1 = " << &var1 << endl;
   double ret1 = PassByValue(var1);
   cout << "After PassByValue() var1 = " << var1
    << ", &var1 = " << &var1 << ", ret1 = " << ret1 << endl;

   // Changes to a parameter passed by reference also affect the variable
   // outside the body of the function
   cout << endl;
   int var2 = 9;
   cout << "Before PassByReference() var2 = " << var2
    << ", &var2 = " << &var2 << endl;
   double ret2 = PassByReference(var2);
   cout << "After PassByReference() var2 = " << var2
    << ", &var2 = " << &var2 << ", ret2 = " << ret2 << endl;

   return 0;
}
