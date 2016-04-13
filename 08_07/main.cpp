#include <iostream>
#include <stdio.h>
#define TAM  5
int buscar_numero(float,float []);
int buscar_numero(float,float[],int);
float peso[TAM];

using namespace std; /*cout,endl*/
int main(int argc, char** argv) {
  peso[0]=82.0;
  peso[1]=peso[2]=70.0;
  peso[3]=92.0;
  peso[4]=98.5;
  float p=80.0;
  if(buscar_numero(p,peso)==1){
    printf("El numero %f si esta en el arreglo peso.\n",p);
  }else{
  	
    printf("El numero %f no esta en el arreglo peso.\n",p);
  }
  int a=buscar_numero(80,peso,sizeof(peso)/sizeof(float));
  cout<<"a="<<a<<endl;
  return 0;
}//end main()

int buscar_numero(float num,float p[]){
/*
  int i;
  for(i=0;i<TAM;i++){
  	if(num==p[i]){
      return 1;
    }
  }
  return -1;
*/
  return ((num==p[0])||(num==p[1])||(num==p[2])||(num==p[3])\
  ||(num==p[4]))? 1:-1;
}
int buscar_numero(float num,float p[],int tam)
{
  for(int i=0;i<tam;i++){
  	if(num==p[i]){
      return 1;
    }
  }
  return -1;
}
