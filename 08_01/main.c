#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**
 obtiene el divisor comun maximo para dos
 enteros 
*/
using std::string;
int mcd(int,int); /*prototipo de la funcion mcd()*/
/*Valido solo para el anio 2016*/
string ARREGLO[][7]={
{"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"},/*enero*/
{"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"},/*febrero*/
{"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"},/*marzo*/
{"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"},/*abril*/
{"Sabado","Domingo","Lunes","Martes","Miercoles","Jueves","Viernes"},/*mayo*/
{"Martes","Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes"},/*junio*/
{"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"},/*julio*/
{"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"},/*agosto*/
{"Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes","Martes"},/*septiembre*/
{"Viernes","Sabado","Domingo","Lunes","Martes","Miercoles","Jueves"},/*octubre*/
{"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"},/*noviembre*/
{"Martes","Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes"}/*diciembre*/
};

int main(int argc, char *argv[]) {
	int m,M;
	int n,N;
	int q,r;
	M=m=24;
	N=n=16;
	//division entera 24/16=1
	q=m/n; 
	r=m-q*n; //r=m%n;
	printf("q=%i, r=%i\n",q,r);
	if(r==0){
		printf("mcd(%i,%i)=%i\n",M,N,n);
	}else{
		m=n;
		n=r;
	}
	q=m/n; 
	r=m-q*n;/*para los valores 24 y 16,aqui r debe ser 0*/
	printf("q=%i, r=%i\n",q,r);
	if(r==0){
		printf("mcd(%i,%i)=%i\n",M,N,n);
	}else{
		m=n;
		n=r;
	}

	printf("mcd(%i,%i)=%i\n",24,16,mcd(24,16));
    int dia=15,mes=1;/*0 enero,1 febrero,2 marzo,3 abril,4 mayo, 5 junio etc.*/
    cout<<ARREGLO[mes][dia%7]<<" "<<dia<<" de febrero de 2016.\n";
	system("pause");	
	return 0;
}//end main()

int mcd(int m,int n){
	int r;
  while((r=m%n)!=0){
  	m=n;
  	n=r;
  }
  return n;
}

