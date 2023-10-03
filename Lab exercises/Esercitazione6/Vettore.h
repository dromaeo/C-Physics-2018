#ifndef _VETTORE_H_
#define _VETTORE_H_

#include <fstream>


/*
 * La classe vettore implementa un vettore geometrico in tre dimensioni
 */
class Vettore {

 public:
   /*
    * costruttore di default (vettore nullo), implementato inline
    * Nota: usa il metodo Set()
    */
   Vettore() { Set(0, 0, 0); }

   /*
    * costruttore con coordinate: usa il metodo Set(), implementato inline
    */
   Vettore(double x, double y, double z) { Set(x, y, z); }

   /* distruttore: non fa niente, implementato inline */
   virtual ~Vettore() {}

   // metodo per impostare le coordinate in un'unica chiamata, inline
   void Set(double x, double y, double z)
   { m_x =x; m_y = y; m_z = z; }
   
   // metodi per impostare e rileggere le singole coordinate, inline
   void SetX(double x) { m_x = x; }
   void SetY(double y) { m_y = y; }
   void SetZ(double z) { m_z = z; }
   double GetX() const { return m_x; }
   double GetY() const { return m_y; }
   double GetZ() const { return m_z; }

   // operator+(): somma tra due vettori, gia' implementato nel file .cpp
   Vettore operator+(const Vettore& other);

   /*
    * operator-(): moltiplicazione di un vettore per -1
    * gia' implementato nel file .cpp
    */
   Vettore operator-();
   
   /*
    * stampa su terminale del vettore nel formato (x, y, z)
    * gia' implementato nel file .cpp
    */
   void Print();

   
   
   /*
    * operator-(): differenza tra due vettori
    *
    * --> Da implementare nel file .cpp
    */
   Vettore operator-(const Vettore& other);
   
   /*
    * calcolo del prodotto scalare con un altro vettore
    *
    * --> Da implementare nel file .cpp
    */
   double operator*(const Vettore& other);

   /*
    * Calcolo del prodotto per un numero nella forma vettore * numero
    *
    * --> Da implementare nel file .cpp
    *
    *
    * NOTA: diversamente da quanto accade in geometria, dove il prodotto tra
    *       uno scalare ed un vettore gode della proprieta' commutativa, in C++
    *       le due operazioni numero*vettore e vettore*numero non sono
    *       necessariamente equivalenti.
    *       Questo operatore definisce il prodotto vettore*numero.
    *       Il caso inverso di numero*vettore e' invece definito in fondo a
    *       questo file, all'esterno della definizione della classe Vettore,
    *       ed e' implementato in fondo al file Vettore.cpp
    *       Notate la differenza di sintassi tra i due casi.
    */
   Vettore operator*(double scalar);


   /*
    * Definite ed implementate un metodo che calcoli il modulo del vettore.
    *
    * Suggerimento: il modulo di un vettore e' dato dalla radice quadrata del
    * prodotto scalare del vettore per se stesso.
    *
    * --> Da definire qui ed implementare nel file .cpp
    */
   double Modulo();
   
 private:
   // data member privati per le coordinate: iniziano con m_
   double m_x;
   double m_y;
   double m_z;
};

/* prodotto di uno scalare per un vettore */
Vettore operator*(double scalar, Vettore& v);

std::ostream& operator<<(std::ostream& o, const Vettore& v);
#endif
