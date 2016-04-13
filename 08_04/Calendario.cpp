/*Calendario.cpp*/

#include <iostream> /*cout, cin, endl*/
#include <stdlib.h> /*malloc()*/
using std::cout;
using std::cin;
using std::endl;
#include "Calendario.h"
#include "Fecha.h"
#include "Dia.h"
extern int dia;

void Calendario::set_year(int y){
  year=y;
}

Fecha* Calendario::get_fecha(){
  Fecha* ret=(Fecha*)malloc(sizeof(Fecha));
  return ret;
}

Fecha* Calendario::get_fecha(int d,int m){
  Fecha* ret=(Fecha*)malloc(sizeof(Fecha));
  ret->d=d;
  ret->m=m;
  return ret;	
}

Calendario::Calendario(int y){
  int day, month;
  cout<<"Teclea los datos de la fecha como se indica."<<endl;
  cout<<"Numero del dia del mes: ";
  cin>>day;
  cout<<"Numero del mes (0 enero, 1 febrero, 2 marzo, etc): ";
  cin>>month;
  fecha=(Fecha*)malloc(sizeof(Fecha));
  fecha->d=day;
  fecha->m=month;
}

/*antes de usar este metodo, se debe haber inicializado
el apuntador fecha del objeto Calendario*/
Dia *Calendario::get_dia(){
  Dia *ret=new Dia();
  ret->f=fecha;
  return ret;
}

void funcion(){
  static int dialocal=0;
  dia=10;
  cout<<"funcion():dia="<<dia<<endl;
  cout<<"dialocal="<<dialocal<<endl;
  dialocal++; /*dialocal=dialocal+1*/
}
void funcion1(){
  int dialocal;
  dialocal=20;
}
