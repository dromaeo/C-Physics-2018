#include "PuntoMateriale.h"
#include "Vettore.h"
#include <cmath>

void PuntoMateriale::Set(double massa, double x, double y, double z)
{
  m_massa = massa;
  m_posizione.Set(x, y, z);
}



Vettore PuntoMateriale::CalcolaCampo(Vettore p)
{
  const double G=6.67*(pow(10,-11));

  Vettore r;
  double rx = p.GetX() - m_posizione.GetX();
  double ry = p.GetY() - m_posizione.GetY();
  double rz = p.GetZ() - m_posizione.GetZ();
  double m = m_massa;
  r.Set(rx, ry, rz);
  double mod= r.Modulo();
  
  Vettore g;
  double gx= (-G*m*r.GetX())/ pow(mod,3);
  double gy= (-G*m*r.GetY())/ pow(mod,3);
  double gz= (-G*m*r.GetZ())/ pow(mod,3);
  g.Set(gx, gy, gz);
  
  return g;
  
}

