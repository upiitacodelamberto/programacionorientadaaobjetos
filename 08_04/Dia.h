//Dia.h
#ifndef DIA_H
#define DIA_H
#include <iostream>
#include <ostream>
using std::string;
using std::ostream;
using std::endl;
/*Donde se incluya este archivo 
  debera incluirse la biblioteca <ostream>,
  debera estar un int numdanio como variable global, 
  debera declararse e inicializarse los arreglos 
  ARREGLO y MONTH*/
/*Definicion de la macro EXTERN, MAIN_MODULE solo debe 
definirse en el modulo principal, asi EXTERN int anio; 
sera 
       int anio; en el modulo principal y sera
extern int anio; en los demas modulos.
*/
#ifdef MAIN_MODULE
#define EXTERN 
#else
#define EXTERN extern
#endif /*MAIN_MODULE*/

EXTERN int anio;
#ifndef MAIN_MODULE
EXTERN string ARREGLO[12][7];
EXTERN string MONTH[];
#endif /*MAIN_MODULE*/
#include "fecha.h"
class Dia{
public:
  Fecha *f;
  /*sobrescritura del operador <<, segun parece este 
  operador solo lo podre sobrescribir para una clase. Asi que 
  creare una clase en la que la sobrescritura del operador 
  de incersion de flujo sera una funcion friend. La pregunta es:
  cual sera esta clase?*/
  friend ostream& operator<<(ostream& out,Dia& D){
    out<<ARREGLO[D.f->m][(D.f->d)%7]<<" "<<D.f->d<<" de "
	   <<MONTH[D.f->m]<<" de "<<anio<<endl;
	return out;
  }
};
#endif /*DIA_H*/
