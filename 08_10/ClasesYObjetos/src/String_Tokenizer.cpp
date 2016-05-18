#include <iostream>
#include "String_Tokenizer.h"
using std::string;

/** Ubicar start y end de modo que start sea el indice del comienzo 
    del siguiente token y end sea la terminacion.
*/
void String_Tokenizer::find_next(){
  if (end!=std::string::npos) {
    std::string tmp=the_source.substr(end,2);
    std::string::size_type n=tmp.find(",,");
    if (n==0) {
      start=end;
      end++;
    } else {
      //Encuentra el primer caracter que no es un delimitador.
      start=the_source.find_first_not_of(the_delim, end);
      //Encuentra el siguiente delimitador
      end=the_source.find_first_of(the_delim, start);
    }
  } else {
    //Encuentra el primer caracter que no es un delimitador.
    start=the_source.find_first_not_of(the_delim, end);
    //Encuentra el siguiente delimitador
    end=the_source.find_first_of(the_delim, start);
  }
}

/** Determina si existen mas tokens
    @return true si hay mas tokens
*/
bool String_Tokenizer::has_more_tokens(){
  return start!=string::npos;
}
/** Recupera el siguiente token
    @return El siguiente token. Si no hay mas tokens regresa una 
            cadena vacia.
*/
string String_Tokenizer::next_token(){
  //Asegura la existencia de un siguiente token
  if(!has_more_tokens()){
std::cout<<"ESTA REGRESANDO POR AQUI!!\n";
    return "";
  }
  //Guarda el siguiente token
  string token;
  if (end!=std::string::npos) {
    std::string tmp=the_source.substr(start,2);
    std::string::size_type n=tmp.find(",,");
    if (n==0) {
      token="";
    } else {
      token=the_source.substr(start, end-start);
    }
  } else {
      token=the_source.substr(start, end-start);
  }
  //Encuentra el siguiente token
  find_next();
  //Regresa el siguiente token
  return token;
}
