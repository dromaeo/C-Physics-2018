#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double a,b,c;
  double x;
  {
    cout << "inserisci i coefficienti di  ax^2+bx+c" << endl;
  cin >> a >> b >> c;
  if (a==0){
    if (b == 0){
    cout << "non c'è niente da risolvere qui!" << endl;
    } else // (b>0)
      {
      double x = (-c/b);
      cout << "la soluzione è " << x << endl;
    }
  }
 }
  if(a>0){
   if (c>0){
     if (b==0){
       cout << "impossibile! Non posso fare la radice di un numero negativo." << endl;
     } else //b diverso da zero
       {
           if (((pow(b,2)) < ((4)*a*c))){
         cout << "Impossibile! Il delta è minore di zero." << endl;
        } else {
            double x = (-b+(sqrt(pow(b,2)-(4*a*c))))/(2*a);
            cout << "Le soluzioni sono x1 = " << x << endl;
            double y = (-b-(sqrt(pow(b,2)-(4*a*c))))/(2*a);
            cout  << ", x2 = " << y <<  endl;
       }
     }
   } else// se (c<0)
     {
       if (b==0){
     double x = sqrt((-c/a));
       cout << "La soluzione è x = " << x << endl;
       } else //b diverso da zero
     {
       double x = (-b+(sqrt(pow(b,2)-(4*a*c))))/(2*a);
       cout << "Le soluzioni sono x1 = "  << x << endl;
        double y = (-b-(sqrt(pow(b,2)-(4*a*c))))/(2*a);
           cout  << ", x2 = " << y << endl;
     }
     }
  }else  if (a<0){
     if (b==0){
       {if (c<0)
       {cout << "Impossibile! Non posso fare la radice di un numero negativo." << endl;
     } else
       { double x = sqrt((a/-c));
         cout << "La soluzione è x1 = " << x <<endl;
         cout << "La soluzione è x1 = " << -x <<endl;
       }
       }
     }else //b<0 a<0
       {if (c==0){
           double x = -(b/a);
         cout << "Le soluzioni sono x1 = " << 0 << ", x2 = " << x << endl;
         } else if (c>0)
           { double x = (-b+(sqrt(pow(b,2)-(4*a*c))))/(2*a);
             cout << "La soluzione è x1 = " << x << endl;
             double y = (-b-(sqrt(pow(b,2)-(4*a*c))))/(2*a);
             cout  << ", x2 = " << y <<  endl;
           } else //c<o
           {if(pow(b,2)>(-4*a*c)){
           double x = (-b+(sqrt(pow(b,2)-(4*a*c))))/(2*a);
               cout << "Le soluzioni sono x1 = " << x << endl;
               double y = (-b-(sqrt(pow(b,2)-(4*a*c))))/(2*a);
               cout  << ", x2 = " << y <<  endl;
         } else {
           cout << "Impossibile! Il delta è negativo." << endl;
         }
           }
       }
     }    
  if (c==0){
    cout << "Le soluzioni sono x1 = " << 0 << endl;
    double x = (-b/a);
    cout  << ", x2 = " << x << endl;
    }
  return 0;
 }

