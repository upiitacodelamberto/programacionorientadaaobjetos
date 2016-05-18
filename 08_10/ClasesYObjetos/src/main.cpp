/**
 * main.c - El programa principal de la aplicacion.
 */
#include <stdio.h>
#include <iostream>
//#include <istream>
#include <fstream>
#include <vector>
#include "modelo.h"
#include "String_Tokenizer.h"
using namespace std;
string archivo="1 Resultados_secciones.csv";
string source_file;
void load_data_CAS(string& source_name);
void add(vector<string>& A);

int main(int argc, char *argv[])
{
  printf("Conteos dinamicos y conteos rapidos\n");
  printf("Leyendo datos del archivo %s\n", &archivo[0]);
//	inic_bins();
  load_data_CAS(archivo);
  //cout<<source_file<<"\n";
//	proccess_commands();
  for(int i=0;i<CAS.size();i++){
    cout<<*CAS[i]<<"\n";
  }

	return 0;
}//end main()

void load_data_CAS(string& source_name){
  source_file=source_name; //recordar nombre de archivo de datos.
  //crear una cadena de entrada para ese archivo
  vector<string> arr;
  ifstream in(source_name.c_str());
  if(in){//el stream existe
    string linea;
    while(getline(in, linea)){
      String_Tokenizer tokenizer(linea, ",");
      while(tokenizer.has_more_tokens()){
        arr.push_back(tokenizer.next_token());
      }
      add(arr);
      //Imprimir la cantidad de tokens encontrados en la linea  
//      cout<<linea<<"\n";
      cout<<"Num. de linea:"<<CAS.size()<<" Tokens:"<<arr.size()<<"\n";
//      for(int i=0;i<arr.size();i++){
//        cout<<"Indice="<<i<<"\""<<arr[i]<<"\" ";
//      }
//      cout<<"\n\n";
      arr.clear();  /*se limpia el vector para empezar con los tokens 
                      de la siguiente linea*/
    }

    in.close();  //cerrar el archivo
  }
}
    
void add(vector<string>& A){
//  CAS.push_back(new Casilla(A[0], A[1], A[2], A[3], A[4]));
  CAS.push_back(new Casilla(A));
}    
