#include <iostream>
using std::string;
using std::cout;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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

int main(int argc, char** argv) {
    int dia=15,mes=1;/*0 enero,1 febrero,2 marzo,3 abril,4 mayo, 5 junio etc.*/
    cout<<ARREGLO[mes][dia%7]<<" "<<dia<<" de febrero de 2016.\n";
    system("pause");
	return 0;
}
