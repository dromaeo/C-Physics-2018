#include "Vettore.h"

#include <iostream>
#include <cmath>

using namespace std;


Vettore Vettore::operator+(const Vettore& other)
{
   Vettore v;
   v.SetX(m_x + other.GetX());
   v.SetY(m_y + other.GetY());
   v.SetZ(m_z + other.GetZ());
   return v;
}


Vettore Vettore::operator-()
{
   /*
    * sfrutta operator-(double scalar): quindi non funziona finche'
    * quell'operatore non sara' implementato
    */
   return this->operator*(-1);
}


void Vettore::Print()
{
   cout << "(" << m_x << ", " << m_y << ", " << m_z << ")" << endl;
}



/* * * METODI DA IMPLEMENTARE * * */



Vettore Vettore::operator-(const Vettore& other)
{
   /*
    * sottrazione di un altro vettore
    */
  Vettore w;
  w.SetX(m_x - other.GetX());
  w.SetY(m_y - other.GetY());
  w.SetZ(m_z - other.GetZ());
  return w;	 
}


double Vettore::operator*(const Vettore& other)
{
   /*
    * prodotto scalare con un altro vettore
    */
  double w;
  w= m_x*other.GetX() + m_y*other.GetY() + m_z*other.GetZ();
  return w;
}


Vettore Vettore::operator*(double scalar)
{
   /*
    * prodotto per uno scalare
    */
  Vettore v;
  v.SetX(m_x*scalar);
  v.SetY(m_y*scalar);
  v.SetZ(m_z*scalar);
  return v;
}
  
  
/* Metodo Modulo() da implementare e da definire nel file Vettore.h */
double Vettore::Modulo()
{
  double modulo;
  double n= pow(m_x,2)+pow(m_y,2)+pow(m_z,2);
  modulo= sqrt(n);
  return modulo;
}
  



/* * * Le due funzioni qui sotto sono gia' implementate * * */


Vettore operator*(double scalar, Vettore& v)
{
   // sfrutta l'implementazione di vettore*numero
   return v*scalar;
}


ostream& operator<<(ostream& o, const Vettore& v)
{
   o << "(" << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ")"
     << flush;
   return o;
}
