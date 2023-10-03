#ifndef _PUNTO_MATERIALE_H
#define _PUNTO_MATERIALE_H

#include "Vettore.h"

class PuntoMateriale {
 public:
   /* costruttore di default, massa e posizione = 0, implementato inline */
   PuntoMateriale() { Set(0, 0, 0, 0); }
   /* costruttore con inizializzazione di massa e posizione, inline */
   PuntoMateriale(double massa, double x, double y, double z)
   { Set(massa, x, y, z); }

   /*
    * setter globale per massa e posizione 
    */
   void Set(double massa, double x, double y, double z);
   
   /* setter e getter individuali per posizione e massa, inline */
   void SetPosizione(Vettore v) { m_posizione = v; }
   Vettore GetPosizione() const { return m_posizione; }
   void SetMassa(double m) { m_massa = m; }
   double GetMassa() const { return m_massa; }

   
   /*
    * calcolo del campo gravitazionale generato dal punto materiale nel punto p
    * L'unita' di misura del vettore ritornato e' N/kg
    */
   Vettore CalcolaCampo(Vettore p);

   
 private:
   Vettore m_posizione; // coordinate del punto in m
   double m_massa; // massa del punto in kg
};
#endif
