#include <iostream>
#include <vector>
#include <malloc.h> /* malloc() */
#include "modelo.h"
using namespace std;

/* Casillas reportadas al PREP en un momento dado
   (en las primeras horas de su operacion) 
   EN ESTA version del programa no se usara este arreglo, 
   lo dejo unicamente para posible uso posterior de la idea.
   2015.11.17 */
int repdas[NUMDFILAS][NUMDCOLUMNAS] = {
{0, 0, 0, 0, 0, 0, 1, 0}, {1, 1, 1, 1,
0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 1, 1, 1}, {0, 0, 0, 0,
0, 0, 0, 1}, {0, 0, 0, 1, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 1, 1, 1}, {0, 1, 0, 0,
0, 0, 1, 1}, {0, 1, 1, 0, 1, 1, 0, 0},
{0, 0, 0, 0, 1, 0, 1, 0}, {0, 0, 1, 1,
0, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 1},
{1, 1, 0, 0, 0, 1, 1, 0}, {0, 0, 0, 1,
0, 0, 1, 0}, {0, 0, 0, 1, 0, 0, 0, 0}
};

//Casilla **CAS;   /* vease archivo include/modelo.h */
vector <Casilla*>CAS;

/* En esta version no se usa, lo dejo unicamente para 
   posible uso futuro. 2015.11.17 */
struct bin *B[NUMDFILAS];


/**
 * Agrego esta funcion con la idea de poder probar 
 * en esta etapa inicial si funcionan bien algunas funciones 
 * que haran uso de metodos de objetos de la clase Casilla, 
 * que aun no he agregado. Entre ellos tengo pensado una funcion 
 * que nos indique la informacion que se muestra en la columna fx
 * en la tabla de la derecha de la grafica I.3 (Pag. 23 del Docto).
 */
//void proccess_commands(Casilla ** bin)
void proccess_commands()
{
	unsigned int item;
	vector < string > mdoitem;
	mdoitem.push_back("Mostrar casillas reportadas al PREP por cada bin");
	mdoitem.push_back("Mostrar cantidad de casillas reportadas al PREP por cada bin");
	mdoitem.push_back("Salir");

//	cout << "En esta version un bin es uno de 15 grupos de 8 casillas" <<
//	    endl;
	do {
		for (unsigned int i = 0; i < mdoitem.size(); i++) {
			cout << i << " " << mdoitem[i] << endl;
		}
		cout << "Teclea una opcion: ";
		cin >> item;
		switch (item) {
		case 0:{
//				proccess_show_reported_casillas();
				break;
			}
                case 1:{
//                                proccess_show_cantdcasillas_por_bin();
                                break;
                        }
		case 2:{
				proccess_salir();
				break;
			}
		default:
			break;
		}
	} while (item != (mdoitem.size() - 1));
}


void proccess_salir()
{
	/* por ahora esta funcion queda vacia (2015.05.20) */
}

//bool Casilla::yaReportadaAlPREP()
//{
//	return reportadaAlPREP;
//}

//int Casilla::get_numDCasilla(){
//  return numDCasilla;
//}

//void Casilla::set_reportadaAlPREP(bool b){
//  reportadaAlPREP = b;
//}

//void Casilla::set_numDCasilla(int N){
//  numDCasilla = N;
//}

//void proccess_show_cantdcasillas_por_bin(){
//  int m, n, count = 0;
//  for(int i = 0; i < NUMDFILAS; i++){
//    for(int j = 0; j < B[i]->N; j++){
//      m = (*(B[i]->p + j) - 1) / NUMDCOLUMNAS; 
//      n = (*(B[i]->p + j) - 1) % NUMDCOLUMNAS;
//      if(CAS[m][n].yaReportadaAlPREP()){
//         count++;
//      }
//    }
//    B[i]->cantDCRep = count;
//    count = 0;
//  }
//  for(int i = 0; i < NUMDFILAS; i++){
//    cout << "Bin " << i + 1 << ": " << B[i]->cantDCRep;
//    cout << endl;
//  }
//}

string Casilla::get_distrito(){
  return distrito;
}

string Casilla::get_seccion(){
  return seccion;
}

string Casilla::get_casilla(){
  return casilla;
}

string Casilla::get_delegacion(){
  return delegacion;
}

string Casilla::get_tipo(){
  return tipo;
}

Casilla::Casilla(string dis, string sec, string cas, string deleg, string tip):
distrito(dis), seccion(sec), casilla(cas), delegacion(deleg), tipo(tip){ }

Casilla::Casilla(string dis, string sec, string cas, string deleg, string tip, string PCC):
distrito(dis), seccion(sec), casilla(cas), delegacion(deleg), tipo(tip), PartCandCoal(PCC){ }


