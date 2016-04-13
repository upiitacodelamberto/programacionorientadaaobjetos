//Actividad.h
#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
class Dia;
class Actividad{
public:
  string nombre;         /*nombre de la actividad*/
  float TRT;             /*Tiempo Requerido Total:tiempo en hrs que debe durar la actividad*/
  float TR;              /*Tiempo Requerido*/
  void set_TRT(float TRT);
  vector<Dia*> intervalo;/*Dias durante los cuales se realizara la Actividad*/
  Actividad(string name,float trt):nombre(name),TRT(trt),TR(trt){ }
};//end class Actividad
#endif /*ACTIVIDAD_H*/
