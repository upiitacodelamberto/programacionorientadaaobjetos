/*Calendario.h*/
#ifndef CALENDARIO_H
#define CALENDARIO_H
#include <iostream>
using std::string;

struct Fecha;
class Dia;
class Calendario{
//public:
  int year;
public:
  Fecha *fecha;
  void set_year(int y);
  Fecha* get_fecha();
  static Fecha* get_fecha(int d,int m);/*sobrecarga de metodos*/
  Dia *get_dia();
  /*constructor por defecto*/
  Calendario():year(2016){ }/*este constructor se resuelve inline*/
  Calendario(int);/*constructor que recibe un int*/
};//end class Calendario
#endif /*CALENDARIO_H*/
