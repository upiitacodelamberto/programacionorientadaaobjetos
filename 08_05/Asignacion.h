//Asignacion.h
#ifndef ASIGNACION_H
#define ASIGNACION_H
class Actividad;
class Asignacion{
public:
  Actividad *Act;          /*Actividad asignada*/
  float TA;                /*Tiempo Asignado*/
  Asignacion(Actividad* a,float ta):Act(a),TA(ta){ }
  friend ostream& operator<<(ostream& out,Asignacion& a);
};//end class Asignacion
#endif /*ASIGNACION_H*/
