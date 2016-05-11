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
  cout<<source_file<<"\n";
//	proccess_commands();

	return 0;
}//end main()

void load_data_CAS(string& source_name){
  source_file=source_name; //recordar nombre de archivo de datos.
  //crear una cadena de entrada para ese archivo
  vector<string> arr;
  arr.push_back("");arr.push_back("");arr.push_back("");
  arr.push_back("");arr.push_back("");arr.push_back("");arr.push_back("");
  ifstream in(source_name.c_str());
  if(in){//el stream existe
    string linea;
//    string arr[5];
    int line_num=0, tokcount=0;
    while(getline(in, linea)){
      line_num++;
      String_Tokenizer tokenizer(linea, ",");
      while(tokenizer.has_more_tokens()){
        arr[tokcount]=tokenizer.next_token();
        tokcount++;
        if(tokcount==7){
          add(arr);
          tokcount=0;
          break;
        }
      }
      cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "
          <<arr[4]<<"#"<<arr[5]<<"#"<<arr[6]<<"\n";
    }
    in.close();  //cerrar el archivo
  } 
}
    
void add(vector<string>& A){
  CAS.push_back(new Casilla(A[0], A[1], A[2], A[3], A[4]));
}    
