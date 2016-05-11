#ifndef MODELO_H
#define MODELO_H
/**
 * La adecuada operacion de conteos dinamicos requiere del 
 * desarrollo de dos fases: una primera consistente en el 
 * proceso de seleccion de muestras representativas de 
 * casillas electorales; y una segunda fase, consistente 
 * en la generacion de multiples estimaciones de resultados 
 * electorales, sustentadas en procedimientos estadisticos 
 * convencionales.
 *
 * Seleccion de muestras representativas
 * Se clasifican todas las casillas del ambito electoral 
 * en "m" clases o bin's. Estos son conjuntos que se conforman 
 * con una misma cantidad de casillas electorales, las cuales 
 * se presuponen que estan contiguas con base en la clave que 
 * se les asigna consecutivamente, segun el numero de distrito 
 * y de la seccion electoral correspondiente. 
 * (VER Cuadro I.1 en la pagina 22):
\begin{tabular}{|c|c|c|c|}
\hline\\
Numero de&Distrito&Seccion&Casilla\\\hline
casilla&electoral local&&\\\hline
1&XXXIV&3119&B\\\hline
2&XXXIV&3119&C1\\\hline
3&XXXIV&3120&B\\\hline
$\vdots$&$\vdots$&$\vdots$&$\vdots$\\\hline
118&XXXIV&3160&C4\\\hline
119&XXXIV&3161&B\\\hline
120&XXXIV&3161&C1\\\hline
\end{tabular}
 * En la pagina 22 se parte del supuesto de un ejercicio 
 * simplificado de un ambito electoral de solo 120 casillas, 
 * las cuales se organizan en 15 grupos de ocho casillas cada 
 * uno, conforme a la grafica 2. (VER grafica I.2 en la pagina 
 * 22) (El numero en la celda superior derecha de cada grupo 
 * identifica la clave del bin).
 * Esa grafica se denomina: Conformacion de 15 clases o bin's 
 * con ocho casillas electorales instaladas cada una (N = 120)
 */
#include <iostream>
#include <string>
using namespace std;
#define TAMMAX	20;		//Ya no se usa (2015.05.19.21:07)

typedef struct CasiCasilla{
  string distrito;
  string seccion;
  string casilla;
  string delegacion;
  string tipo;
  string PartCandCoal;  /* Partido, Candidato o Coalicion */
  int indexPrimSinVotos;
  CasiCasilla():distrito(""),seccion(""),casilla(""),delegacion(""),
                tipo(""),PartCandCoal("") {}
  bool operator==(CasiCasilla& CCas)const{
    //return (distrito==CCas.distrito&&casilla==CCas.casilla&&);
    return (indexPrimSinVotos==CCas.indexPrimSinVotos);
  }
}CasiCasilla;

/**
 Las columnas del documento ``1 Resulatdos secciones.csv'' i
 indican lo siguiente: (O usando sintaxis \LaTeX el codigo seria:)
 \begin{tabular}{ccccc}
 ``La primera esta vacia''&SECCION&CASILLA&DELEGACION&TIPO&PAN&PRI&PRD&
 PVEM&PT&MC&NA&MORENA&PH&ES&ALEJANDRO VINAY&NAZARIO NORBERTO&ARNE SIDNEY&
 JORGE RIVERA&JUAN DAVID&OSCAR ANTONIO&ROSARIO ERIKA&JUDITH BARRIOS&
 EFRAIN MORALES&EDGAR MONTERO&PATRICIO DEL VALLE&PRI-PVEM&PRD-PT-NA&PRD-PT&
 PRD-NA&PT-NA&VOTOS NULOS&NO REGISTRADOS\\
 \end{tabular}
 
 */
class Casilla {
	string distrito;	//segun parece siempre es un entero
	string seccion;	        //tambien parece ser siempre un entero
	string casilla;		//Casilla p.ej.:"B", "C1", "B", ..., "C4", "B", "C1".
        string delegacion;      //Delegacion donde se ubica la casilla
        string tipo;            //Tipo p. ej. "JD", "DM".
//	bool reportadaAlPREP;	//Para indicar si la casilla ya ha 
                                //reportado al PREP
  string PartCandCoal;  /* Partido, Candidato o Coalicion */
        
 public:
  string get_PartCandCoal(){return PartCandCoal;}
  static int indexPrimSinVotos;
         string get_distrito();
	 string get_seccion();
         string get_casilla();
         string get_delegacion();
         string get_tipo();
//         void set_numDCasilla(int N);
//         void set_reportadaAlPREP(bool b);
         //Constructores
         Casilla(){             //Por ahora vacio 2015.11.17
         } 
         Casilla(string dis, string sec, string cas, string deleg, string tip);
  Casilla(string dis, string sec, string cas, string deleg, string tip, string PCC);
  static int index_primera_sin_votos();
};//End class Casilla

/**
 * Entonces una primera propuesta para modelar los bin's era usar 
 * un arreglo bidimensional de objetos de clase Casilla. Las 
 * dimensiones del arreglo deberan ser 15 filas por 8 columnas.
 * No estoy seguro de que este sea el mejor lugar para declarar 
 * este arreglo. Pero por ahora aqui lo pondre como extern.
 * 2015.05.21
 * En realidad tuve que usar este apuntador para representar 
 * las 120 casillas y creo que modelare los bins con una 
 * estructura que contendra un entero N que indicara cuantas 
 * casillas contiene el bin y con un apuntador a entero 
 * apuntare a los numeros de las casillas del bin.
 */

/* Usar como arreglo de 15 filas x 8 columnas */
//extern Casilla **CAS;
extern vector <Casilla*>CAS;

#define NUMDFILAS	15
#define NUMDCOLUMNAS	8

/* Para modelar los bins */
struct bin{
  int N;    //cantidad de Casillas contenidas en el bin.
  int cantDCRep;//Cantidad de casillas reportadas al PREP.
  int *p;   //apunta a N enteros correspondientes a los 
            //numeros de casillas contenidas en el bin de que se trate.
};
extern struct bin *B[NUMDFILAS];//Arreglo de NUMDFILAS apuntadores a
                                //struct bin

void inic_bins();

void proccess_commands();
void proccess_salir();

void proccess_show_reported_casillas();
void proccess_show_cantdcasillas_por_bin();
#endif /* MODELO_H */
