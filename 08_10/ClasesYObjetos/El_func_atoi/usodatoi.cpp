#include <stdio.h>
#include <stdlib.h> /*int atoi(const char *str)*/
#include <iostream>

int main(){
  char nda[]="2016";
  char ndm[]="4";
  char ndd[]="18";
  printf("FECHA: %d/%d/%d\n",atoi(ndd),atoi(ndm)+1,atoi(nda));
  return 0;
}
