//Asignacion.cpp
#include <ostream>
#include <vector>
using std::endl;
using std::ostream;
using std::string;
using std::vector;
#include "Asignacion.h"
#include "Actividad.h"
#include "Alumno.h"
int Asignacion::NDA=0;
ostream& operator<<(ostream& out,Asignacion& a){
  out<<"\t"<<a.TA<<"h\t[Tema "<<a.Act->nombre<<"]"<<endl;
  for(int i=0;i<a.AR.size();i++)
    out<<"\t\t"<<*(a.AR[i])<<endl;
  return out;
}
