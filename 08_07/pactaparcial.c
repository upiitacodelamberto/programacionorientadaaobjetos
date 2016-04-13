#include <stdio.h>  /*printf()*/
#include <math.h>
#include <stdlib.h> /*malloc()*/
#include <vector>
#define NUMDALUM  8
using std::vector;
typedef struct Moda{
  int n;          //cant de modas
  float *fpt;      //las modas
}Moda;
Moda *moda(int Cali[],int size);
vector<int> califsdif(int Calif[],int size);
bool estaincluida(int cal,vector<int> vdf);
vector<int> frecdcalifsdif(vector<int> calsdif,int C[],int size);
//el apuntaodr devuelto apuntara a NUMDALUM ints
int* truncaraunadecima(float CPF[],int size);

typedef struct {
  int ndv;      /*numero de veces*/
  int max;
}Max;
Max *elMax(vector<int>);

float PARTNCLASE[NUMDALUM];  /*participacion en clase*/
float PRACTRABET[NUMDALUM];  /*practicas, trabajos, etc.*/
float EXAMEN[NUMDALUM]={     /*calificacion en examen parcial 1*/
7.9,
9.4,
9.9,
8.1,
8.2,
8.3,
9.6,
7.9
};
float EXAMENPOND[NUMDALUM];     /*calificacion de examen ponderado (\times 0.7)*/
float CALPARCIALFIN[NUMDALUM];  /*calificacion parcial final*/
extern char disc_01[];
extern char disc_02[];
extern char disc_03[];
extern char disc_04[];
extern char disc_05[];
extern char disc_06[];
extern char disc_07[];
extern char disc_08[];
char *DISC[NUMDALUM];

void
partinit(float P[])
{
  int i;
  for(i=0;i<NUMDALUM;i++)
  {
    P[i]=1.5;
  }
}

void
pracinit(float P[])
{
  partinit(P);
}

void
ponderarex(float EX[],float EXPOND[])
{
  int i;
  for(i=0;i<NUMDALUM;i++)
  {
    EXPOND[i]=0.7*EX[i];
  }
}

//calcular calificacion parcial final
void
calcularcalparfin(float PART[],float PRAC[],float EXPOND[],float CPF[])
{
  int i=0;
  for(i=0;i<NUMDALUM;i++)
  {
    CPF[i]=PART[i]+PRAC[i]+EXPOND[i];
  }
}

void
discinit(char *D[])
{
  D[0]=disc_01;
  D[1]=disc_02;
  D[2]=disc_03;
  D[3]=disc_04;
  D[4]=disc_05;
  D[5]=disc_06;
  D[6]=disc_07;
  D[7]=disc_08;
}
void
printarrstr(char *D[],int size)
{
  int i;
  for(i=0;i<size;i++)
  {
    printf("%s\n",D[i]);
  }
  printf("\n");
}

void
printdatospacta
(char *D[],float PART[],float PRAC[], float EXPOND[],float CPF[])
{
  int i;
  printf("Nombre\t\t\t\tPart.  Prac. Ex.  CalFinal\n");
  for(i=0;i<NUMDALUM;i++)
  {
    printf("%s\t%0.1f    %0.1f   %0.1f  %0.2f\n",D[i],PART[i],PRAC[i],
	EXPOND[i],CPF[i]);
  }
}

void
printarr(float arr[],int size)
{
  int i;
  for(i=0;i<size;i++)
  {
    printf("%f ",arr[i]);
  }
  printf("\n");
}
void
printarr(int arr[],int size)
{
  int i;
  for(i=0;i<size;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
}

/**
pre: size debe ser > 0.
*/
float
desvstd(float Cali[],int size,float med)
{
  int i;
  float sumd2=0;
  for(i=0;i<size;i++)
  {
    sumd2+=pow(Cali[i]-med,2);
  }
  return sumd2/size;
}

int
main(int argc,char *argv[])
{
  partinit(PARTNCLASE);
  //printarr(PARTNCLASE,NUMDALUM);
  pracinit(PRACTRABET);
  //printarr(PRACTRABET,NUMDALUM);
  discinit(DISC);
  //printarrstr(DISC,NUMDALUM);
  ponderarex(EXAMEN,EXAMENPOND);
  calcularcalparfin(PARTNCLASE,PRACTRABET,EXAMENPOND,CALPARCIALFIN);
  printdatospacta(DISC,PARTNCLASE,PRACTRABET,EXAMENPOND,CALPARCIALFIN);

  int *CALPARFIN=truncaraunadecima(CALPARCIALFIN,NUMDALUM);
  printf("\n");
  
  //printf("Desviacion standar=%.2f\n",desvstd(CALPARCIALFIN,NUMDALUM,9.0)); 
  Moda *mod=moda(CALPARFIN,NUMDALUM);
  printf("Moda: hay %d moda(s)\n",mod->n);
  for(int i=0;i<mod->n;i++)
  {
    printf("%d\t%.1f\n",i+1,*(mod->fpt+i)/10.0);
  }
  
  //Ahora para poner a prueba la funcion moda
  printf("PRUEBA DE LA FUNCION moda()\n");
  int NA[]={23,45,45,89,89,34,80,75,23,24}; 
  printf("En el arreglo\n");
  printarr(NA,sizeof(NA)/sizeof(int));
  printf("\n");
  Moda *nuemamoda=moda(NA,sizeof(NA)/sizeof(int));
  printf("Moda: hay %d moda(s)\n",nuemamoda->n);
  for(int i=0;i<nuemamoda->n;i++)
  {
    printf("%d\t%.1f\n",i+1,*(nuemamoda->fpt+i)/10.0);
  }
  
  
  return 0;
}

Moda*
moda(int Cali[],int size)
{
  Moda *result=(Moda*)malloc(sizeof(Moda));
  //bool todosigual=false;
  int cnt=0,i;
  for(i=1;i<size;i++)
  {
    if(Cali[0]==Cali[i])
      cnt++;
  }
  if(cnt==size-1)/*todos los valores son iguales?*/
  {
    result->n=1;
    result->fpt=(float*)malloc(sizeof(float));
    *(result->fpt)=Cali[0];
    return result;
  }
  //vector<float> calsdif=califsdif(Cali,sizeof(Cali)/sizeof(float));
  vector<int> calsdif=califsdif(Cali,size);
  vector<int> frecdcalsdif=frecdcalifsdif(calsdif,
                           Cali,size);
  Max *M=elMax(frecdcalsdif);
  result->n=M->ndv;
  result->fpt=(float*)malloc(result->n*sizeof(float));
  int z=0;
  for(int k=0;k<frecdcalsdif.size();k++)
  {
    if(frecdcalsdif[k]==M->max)
    {
      *(result->fpt+z)=calsdif[k];
      z++;
    }
  }
  return result;
}

vector<int>
califsdif(int Calif[],int size)
{
  vector<int> ret;
  for(int i=0;i<size;i++)
  {
    if(!estaincluida(Calif[i],ret))
      ret.push_back(Calif[i]);
  }
  return ret;
}

bool
estaincluida(int cal,vector<int> vdf)
{
  for(int i=0;i<vdf.size();i++)
  {
    if(vdf[i]==cal)
      return true;
  }
  return false;
}

vector<int>
frecdcalifsdif(vector<int> calsdif,int C[],int size)
{
  vector<int> r;
  int count=0;
  for(int i=0;i<calsdif.size();i++)
  {
    for(int j=0;j<size;j++)
    {
      if(calsdif[i]==C[j])
        count++;
    }
    r.push_back(count);
    count=0;
  }
  return r;
}

Max*
elMax(vector<int> fdcals)
{
  Max *M=(Max*)malloc(sizeof(Max));
  int m=fdcals[0];
  for(int i=1;i<fdcals.size();i++)
  {
    if(m<fdcals[i])
      m=fdcals[i];
  }
  M->max=m;m=0;
  for(int i=0;i<fdcals.size();i++)
  {
    if(M->max==fdcals[i])
      m++;
  }
  M->ndv=m;
  return M;
}

int*
truncaraunadecima(float CPF[],int size)
{
  int DIEZVCSCALPARFIN[NUMDALUM];
  int *cpf=(int *)malloc(NUMDALUM*sizeof(int));
  for(int i=0;i<size;i++)
  {
    DIEZVCSCALPARFIN[i]=floor((CPF[i]*10.0));
    cpf[i]=DIEZVCSCALPARFIN[i];
  }
  return cpf;
}


















