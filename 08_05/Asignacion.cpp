//Asignacion.cpp
#include <ostream>
#include <vector>
using std::endl;
using std::ostream;
using std::string;
using std::vector;
#include "Asignacion.h"
#include "Actividad.h"

ostream& operator<<(ostream& out,Asignacion& a){
  out<<"\t"<<a.TA<<"h\t[Tema "<<a.Act->nombre<<"]";
  return out;
}
