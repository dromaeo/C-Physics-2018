#include <iostream>
using namespace std;

int main() {
  //I want to connect value
  int value=1;
  int* ptr;
  ptr= &value;
  cout << ptr << endl;
  int new_value= *ptr;
  cout << new_value << endl;
  return 0;
}
