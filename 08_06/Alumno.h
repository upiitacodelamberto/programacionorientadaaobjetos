/*Alumno.h*/
#ifndef ALUMNO_H
#define ALUMNO_H
#define hazcad(s)  #s



#define CLASSAL(fn,ln)  class fn##_##ln : public Alumno{\
public:\
  fn##_##ln (string firstn,string lastn):Alumno(firstn,lastn){ }\
}

class Alumno{
public:
static int NDL;     /*variable de clase*/
  int ndl;          /*numero de lista, variable de objeto*/
  string firstname;
  string lastname;
  Alumno(string firstn,string lastn):firstname(firstn),lastname(lastn){
    NDL++;ndl=NDL;
  }
friend ostream& operator<<(ostream& out,Alumno& a);
};//end class Alumno

CLASSAL(Antonio_de_Jesus,Alcantar_Rocha);
#endif /*ALUMNO_H*/
