#include <iostream>
using namespace std;
int main(){
int n;
cout << "inserisci n" << endl;
cin >> n;
double sum=0;
for (int i=1;i<=n;i++){
sum = sum + i;
}
cout << "La somma vale " << sum << endl;
}
