//Dia.h
#ifndef DIA_H
#define DIA_H
#include <iostream>
#include <ostream>
#include <vector>
using std::string;
using std::vector;
using std::ostream;
using std::endl;

struct Fecha;
class Asignacion;
class Dia{
public:
  Fecha *f;
  float TDT;        /*Tiempo Disponible Total*/
  float TD;         /*Tiempo Disponible*/
  static int diasacumulados[];
  vector<Asignacion*> A;
  Dia(){ }
  Dia(Fecha* fPt):f(fPt){ }
  void set_TDT(float tdt);
  friend ostream& operator<<(ostream& out,Dia& D);
  void calc_consecutivo();
};//end class Dia
#endif /*DIA_H*/
