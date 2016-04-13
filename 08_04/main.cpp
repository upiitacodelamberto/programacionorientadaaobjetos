/*main.cpp*/
#include <iostream>
#include <ostream> /*std::ostream& en ostream& operator<<(ostream& out,Fecha& f)*/
using std::string;
using std::cout;
using std::ostream;

using std::endl;
#define MAIN_MODULE	1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */ 
#include "Fecha.h"
int dia;

/*Tipo de dato compuesto, arreglo de char, ejemplo de variable global*/
/*numero magico: numero de 12 digitos decimales construido tomando las 
fechas del primer lunes de cada mes del anio 2016. Este arreglo se "llenara" en 
la funcion main de este archivo*/
char nmag[12];
/*Declaracion por extension de un arreglo bidimensional de string*/
/*Este es un ejemplo de una variable compuesta global*/
string ARREGLO[12][7]={
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"},/*enero*/
  {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"},/*febrero*/
  {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"},/*marzo*/
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*abril*/
  {"Sabado","Domingo","Lunes","Martes","Miercoles","Jueves","Viernes"}, /*mayo*/
  {"Martes","Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes"}, /*junio*/
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*julio*/
  {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"}, /*agosto*/
  {"Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes","Martes"}, /*septiembre*/
  {"Viernes","Sabado","Domingo","Lunes","Martes","Miercoles","Jueves"}, /*octubre*/
  {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"}, /*noviembre*/
  {"Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes","Martes"}  /*diciembre*/
};
 
/*Este es un ejemplo de una variable global compuesta de tipo string*/
string MONTH[]={
  "enero","febrero","marzo","abril","mayo","junio","julio",
  "agosto","septiembre","octubre","noviembre","diciembre"
};
#include "Dia.h"
#include "Calendario.h"

/*Ejemplo de una funcion*/
char primer_dia(string d,int i){
  char c='\0';
  if(ARREGLO[i][0]==d)c=7;
  if(ARREGLO[i][1]==d)c=1;
  if(ARREGLO[i][2]==d)c=2;
  if(ARREGLO[i][3]==d)c=3;
  if(ARREGLO[i][4]==d)c=4;
  if(ARREGLO[i][5]==d)c=5;
  if(ARREGLO[i][6]==d)c=6;
  return c;
}

/*prototipo de una fucnion*/
void mostrar_nmagico(char NM[],int tam);

int main(int argc, char** argv) {
//  int A;
//  int *p;
//  p=&A;/*el apuntador p ahora apunta a la variable A*/
//  *p=10;
//  cout<<"A="<<A<<endl;
//  int a[3];/*a es un arreglo de 3 int */
//  a[0]=100;
//  a[1]=200;
//  a[2]=300;
//  cout<<a[0]<<"\t"<<a[1]<<"\t"<<a[2]<<endl;
//  int b[2][3];/*declaracion de un arreglo de dos dimensiones*/
//  b[0][0]=0;b[0][1]=1;b[0][2]=2;/*se inicializa la primera fila*/
//  b[1][0]=1;b[1][1]=2;b[1][2]=3;/*se iniciaializa la segunda fila*/
//  int c[2];
//  c[0]=b[0][0]+b[0][1]+b[0][2];
//  c[1]=b[1][0]+b[1][1]+b[1][2];
//  cout<<b[0][0]<<"+"<<b[0][1]<<"+"<<b[0][2]<<"="<<c[0]<<endl;
//  cout<<b[1][0]<<"+"<<b[1][1]<<"+"<<b[1][2]<<"="<<c[1]<<endl;
//  /*declaracion por extension*/
//  int d[][3]={
//  	{10,20,30},
//  	{100,300,900}
//  };
  
  Calendario C;/*creacion de un objeto (instanciacion) Calendario*/
  C.set_year(2016);
  Fecha hoy;
  hoy.d=2;
  hoy.m=2;/*marzo*/
//  Fecha* f1=C.get_fecha();
//  f1->d=1;f1->m=0;/* 1 de enero */ 
  Fecha* f2=Calendario::get_fecha(2,2);/* 2 de marzo */
//  if(hoy==*f1){
//  	cout<<"Hoy es el primer dia del Calendario 2016"<<endl;
//  }
  if(hoy==*f2){
  	cout<<"Hoy es "<<ARREGLO[f2->m][f2->d%7]<<" "<<f2->d<<" de "<<MONTH[f2->m]<<" de 2016."<<endl;
  }
  char ch;
  ch=primer_dia("Lunes",0);nmag[0]=ch;/*enero*/
  ch=primer_dia("Lunes",1);nmag[1]=ch;/*febrero*/
  /*Tambien se puede asignar directamente*/
  nmag[2]=primer_dia("Lunes",2);/*marzo*/
  ch=primer_dia("Lunes",3);nmag[3]=ch;/*abril*/
  ch=primer_dia("Lunes",4);nmag[4]=ch;/*mayo*/
  ch=primer_dia("Lunes",5);nmag[5]=ch;/*junio*/
  ch=primer_dia("Lunes",6);nmag[6]=ch;/*julio*/
  ch=primer_dia("Lunes",7);nmag[7]=ch;/*agosto*/
  ch=primer_dia("Lunes",8);nmag[8]=ch;/*septiembre*/
  ch=primer_dia("Lunes",9);nmag[9]=ch;/*octubre*/
  ch=primer_dia("Lunes",10);nmag[10]=ch;/*noviembre*/
  ch=primer_dia("Lunes",11);nmag[11]=ch;/*diciembre*/

  mostrar_nmagico(nmag,sizeof(nmag)/sizeof(char));
  Calendario C1=Calendario(0);/*observar ejecucion de constructor*/

  /*Tambien se puede imprimir la fecha asi:*/
  anio=2016;
  Dia *D=C1.get_dia();
  //D->f=f2;
  cout<<*D;
void funcion();
void funcion1();  
  //dia=4;
  
  funcion();
  cout<<"dia="<<dia<<endl;
  funcion1();
  funcion();
  system("pause");
  return 0;
}//end main()

/**
 muestra como enteros el contenido del arreglo 
 de char NM
*/
void mostrar_nmagico(char NM[],int tam){
  int i=0;
etiqueta:
  cout<<(int)NM[i]<<" ";
  i=i+1;
  if(i<tam)
    goto etiqueta;
  cout<<endl;
}






