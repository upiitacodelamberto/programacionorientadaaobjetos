/*https://github.com/upiitacodelamberto/programacionorientadaaobjetos*/
#include <stdio.h>
#include <stdlib.h> /*int atoi(const char *str)*/
#include <iostream>

int main(){
  char date[]="FECHA";
  char nda[]="2016";
  char ndm[]="4";
  char ndd[]="18";
  std::string numdsala="1";
  std::string frase1="Los amigos son los que te dicen las cosas \
de frente y de defienden a tus espaldas";
  std::string frase2="Un amigo es alguien que sabe lo peor de ti \
y sigue siendo tu amigo";
  std::string frase3="Si van a hablar mal de mi, esperen a que \
regrese, se algunas cosas horribles de mi que podrian interesarles";
  std::cout<<frase1<<"\n";
  for(int i=0;i<frase2.size();i++){
    printf("%c",frase2[i]);
  }
  printf("\n");
  printf("%d frase3.size()/2=%c\n",frase3.size(),frase3[frase3.size()/2]);
  std::cout<<frase3<<"\n";
  printf("%c\n",numdsala[0]);
  printf("%c\n",numdsala[0]);
  printf("%s: Sala %d, %d/%d/%d\n",date,atoi(&numdsala[0]),atoi(ndd),atoi(ndm)+1,atoi(nda));
#ifdef _WIN32
  system("pause");
#endif
  return 0;
}
