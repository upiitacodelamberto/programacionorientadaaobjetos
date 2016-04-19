#include <stdio.h>


void mostrarbits(int);
void mostrarbits(long);
class clasefloat{
public:
  float fnum;
  clasefloat(float f):fnum(f){ }
};//end class clasefloat
long
operator>>(clasefloat cf,int i)
{
  long rl=(long)*(void**)&cf.fnum;
  return rl>>i;
}
void
mostrarbits(float fn)
{
  clasefloat f(fn);
  for(int i=31;i>=0;i--)
  {
    switch(i){
      case 30:
        printf(" %d",(f>>i)&0x1);break;
      case 22:
        printf(" %d",(f>>i)&0x1);break;
      default:
        printf("%d",(f>>i)&0x1);break;
    }
  }
  printf("\n");
}

int
main()
{
  printf("Un int se guarda en %d bytes\n",sizeof(int));
  mostrarbits(20);
  float fnum=20.0;
  //int *intPt=*(void**)&fnum; /**/
  //mostrarbits(*intPt);
  printf("\n\n");
  printf("Estandar IEEE 754 (1985)\n");
  printf("Un float se guarda en %d bytes: ",sizeof(float));
  printf("1 bit de signo, 8 bits de exponente + excess (excess=127), 23 bits de mantisa.\n");
  printf("%f es %p\n",fnum,*(void**)&fnum);
  printf("El bit de signo es 0, exponente+excess=0b100 0001 1=0b10000011=0x83=0x04+0x7F, \
el exponente es 4,\n mantisa=0b010 0000 0000 0000 0000 0000, el numero es 0b1.01*2^{4}=\
0b10100=1*2^{4}+1*2^{2}=16+4=20.0\n");
  printf("\n");
  fnum=-fnum;
  printf("%f es %p\n",fnum,*(void**)&fnum);
  printf("El bit de signo es 1, exponente+excess=0b100 0001 1=0b10000011=0x83=0x04+0x7F, \
el exponente es 4,\n mantisa=0b010 0000 0000 0000 0000 0000, el numero es -0b1.01*2^{4}=\
-0b10100=-(1*2^{4}+1*2^{2))=-(16+4)=-20.0\n");

  fnum=20.125;
  printf("size of int:%d\n",sizeof(int));
  printf("size of float:%d\n",sizeof(float));
  printf("size of void*:%d\n",sizeof(void*));
  printf("size of void**:%d\n",sizeof(void**));
  printf("size of int*:%d\n",sizeof(int*));
  printf("size of float*:%d\n",sizeof(float*));
  printf("*(void**)&fnum:%p\n",*(void**)&fnum);
  printf("size of long:%d\n",sizeof(long));
  long feni=(long)*(void**)&fnum;
  int i;
  //for(i=8*sizeof(long)-1;i>=0;i--)
  printf("Se muestra el patron de bits correspondiente al float %f\n",fnum);
  printf("%f es  ",fnum);
  for(i=31;i>=0;i--)
  {
    switch(i){
      case 30:
        printf(" %d",(feni>>i)&0x1);break;
      case 22:
        printf(" %d",(feni>>i)&0x1);break;
      default:
        printf("%d",(feni>>i)&0x1);break;
    }
  }
  printf("\n");
  fnum=-fnum;
  feni=(long)*(void**)&fnum;
  printf("Se muestra el patron de bits correspondiente al float %f\n",fnum);
  printf("%f es ",fnum);
  for(i=31;i>=0;i--)
  {
    switch(i){
      case 30:
        printf(" %d",(feni>>i)&0x1);break;
      case 22:
        printf(" %d",(feni>>i)&0x1);break;
      default:
        printf("%d",(feni>>i)&0x1);break;
    }
  }
  printf("\n");
  fnum=3.1416;
  long Num=(long)*(void**)&fnum;
  printf("Se muestra el patron de bits correspondiente al float %f\n",fnum);
  printf("%f es  ",fnum);
  mostrarbits(Num);
  fnum=-fnum;
  Num=(long)*(void**)&fnum;
  printf("Se muestra el patron de bits correspondiente al float %f\n",fnum);
  printf("%f es ",fnum);
  mostrarbits(Num);
  
  printf("\n\n%f es ",fnum);
  mostrarbits(fnum);

  printf("\n\n%f es ",5.675f);
  mostrarbits(5.675f);

  return 0;
}//end main()

/*
Mostrar los bits que usa el compilador para
para representar el literal int que se 
recibe como argumento.
*/
void
mostrarbits(int num)
{
  int i;
  int numdbits=8*sizeof(int);
  for(i=numdbits-1;i>=0;i--)
  {
    printf("%d",(num>>i)&0x00000001);
  }
}

/*
Se debe pasar como argumento un long obtenido asi:
  long num=(long)*(void**)&fnum;
donde fnum es un float.
*/
void
mostrarbits(long num)
{
  int i;
  //int numdbits=8*sizeof(float);
  int numdbits=32;
  for(i=numdbits-1;i>=0;i--)
  {
    switch(i){
      case 30:
        printf(" %d",(num>>i)&0x1);break;
      case 22:
        printf(" %d",(num>>i)&0x1);break;
      default:
        printf("%d",(num>>i)&0x1);break;
    }
  }
  printf("\n");
}








