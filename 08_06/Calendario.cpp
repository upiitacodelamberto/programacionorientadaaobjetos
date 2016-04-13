#include <iostream>
#include <vector>
#include <stdlib.h> /*malloc()*/
using std::string;
using std::cout;
using std::endl;
using std::vector;
#include "Calendario.h"
#include "Fecha.h"
#include "Dia.h"
#include "Actividad.h"
#include "Asignacion.h"
extern int NUMDALUMNOS;

void Calendario::mostrar_fechas(string d,string m){
  SetDIntType* sdi=obtener_nums_ddia(d,m);
  print_SetDIntYFecha(d,m,sdi);
}

void Calendario::print_SetDIntYFecha(string d,string m,SetDIntType* SDI){
  for(int i=0;i<SDI->n;i++){
    cout<<SDI->intPt[i]<<" de "<<m<<" de 2016"<<endl;
  }
}
int Calendario::index_delmes(string month){ 
  if(month=="enero")       return 0;
  if(month=="febrero")     return 1;
  if(month=="marzo")       return 2;
  if(month=="abril")       return 3;    
  if(month=="mayo")        return 4;
  if(month=="junio")       return 5;
  if(month=="julio")       return 6;
  if(month=="agosto")      return 7;
  if(month=="septiembre")  return 8;
  if(month=="octubre")     return 9;
  if(month=="noviembre")   return 10;
  if(month=="diciembre")   return 11;
   
        }

int Calendario::primera_fecha_delmes(string day,int i){
if(ARREGLO[i][0]==day) return 7;
if(ARREGLO[i][1]==day) return 1;
if(ARREGLO[i][2]==day) return 2;
if(ARREGLO[i][3]==day) return 3;
if(ARREGLO[i][4]==day) return 4;
if(ARREGLO[i][5]==day) return 5;
if(ARREGLO[i][6]==day) return 6; 
}                                                 
                      
SetDIntType* Calendario::obtener_nums_ddia(string d, string m){
             SetDIntType* r=(SetDIntType*)malloc(sizeof(SetDIntType));
             int i,j; /* index de l mex es el arreglo*/
             i=index_delmes(m);
             if(i>=0 && i<12){
                     j=primera_fecha_delmes(d,i);
                     }
                     fill_SDIT(i,j,r);
                     return r; }
 void Calendario:: fill_SDIT(int i,int j,SetDIntType* r){
 int diasdmes;
 if (i==0)  diasdmes=31;
 if (i==1)  diasdmes=29;
 if (i==2)  diasdmes=31;
 if (i==3)  diasdmes=30;
 if (i==4)  diasdmes=31;
 if (i==5)  diasdmes=30;
 if (i==6)  diasdmes=31;
 if (i==7)  diasdmes=31;
 if (i==8)  diasdmes=30;
 if (i==9)  diasdmes=31;
 if (i==10) diasdmes=30;
 if (i==11) diasdmes=31;
 int cnt=0;
 for (int k=j; k<=diasdmes; k+=7)
 {
     r->intPt[cnt]=k;
     cnt++;
 }
 r->n=cnt-1;
}                                         

bool Calendario::esta_incluido(string d,vector<string> dias){
  bool ret=false;
  for(int i=0;i<dias.size();i++){
    if(d==dias[i]){
      ret=true;
      break;
    }
  }
  return ret;
}

bool Calendario::esta_incluido(Fecha* fPt,vector<Dia*> dnl){
  bool ret=false;
  for(int i=0;i<dnl.size();i++){
    if(*(dnl[i]->f)==*fPt){
      ret=true;
      break;
    }
  }
  return ret;
}

/**
 devuelve la cantidad de fechas entre fi y ff que corresponden a los 
 dias en el vector dias.
 */                                       
int Calendario::cant_dFechas(Fecha *fi,Fecha *ff,vector<string> dias){
  int im=fi->m,id=fi->d,cnt=0;
  /*cantidades de dias de los meses (2016)*/
  int TamM[]={31,29,31,30,31,30,31,31,30,31,30,31};
inic:
  if((im!=ff->m)||(id!=ff->d)){
    if(esta_incluido(ARREGLO[im][id%7],dias)){
      cnt++;
    }
    if((id+1)<=TamM[im]){
      id++;
    }else{
      id=1;im++;
    }
    goto inic;
  }
  if(esta_incluido(ARREGLO[ff->m][ff->d%7],dias)){
    cnt++;
  }
  return cnt;
}

vector<Fecha*> Calendario::get_Fechas(Fecha *fi,Fecha *ff,vector<string> dias){
  int im=fi->m,id=fi->d,cnt=0;
  vector<Fecha*> vdf;
  /*cantidades de dias de los meses (2016)*/
  int TamM[]={31,29,31,30,31,30,31,31,30,31,30,31};
inic:
  if((im!=ff->m)||(id!=ff->d)){
    if(esta_incluido(ARREGLO[im][id%7],dias)){
      vdf.push_back(new Fecha(id,im));
    }
    if((id+1)<=TamM[im]){
      id++;
    }else{
      id=1;im++;
    }
    goto inic;
  }
  if(esta_incluido(ARREGLO[ff->m][ff->d%7],dias)){
    vdf.push_back(new Fecha(ff->d,ff->m));
  }
  return vdf;
}

vector<Dia*> Calendario::get_Dias_DC(vector<Fecha*> vdf,vector<Dia*> dnl){
  vector<Dia*> vddc;
  for(int i=0;i<vdf.size();i++){
    if(!esta_incluido(vdf[i],dnl)){
      vddc.push_back(new Dia(vdf[i]));
    }
  }
  return vddc;
}

void Calendario::planear(vector<Dia*> DIA,vector<Actividad*> ACT){
  int i=0,j=0;/*i para recorrer los dias y j para recorrer las actividades*/
inicio:
  if(ACT[j]->TR<=DIA[i]->TD){
  	
    DIA[i]->TD-=ACT[j]->TR;
    DIA[i]->A.push_back(new Asignacion(ACT[j],ACT[j]->TR));
    j++;
    if(DIA[i]->TD==0)
      i++;
  }else{
    DIA[i]->A.push_back(new Asignacion(ACT[j],DIA[i]->TD));
    ACT[j]->TR-=DIA[i]->TD;
    i++;
  }
  if( !( (i==DIA.size())||(j==ACT.size()) ) )
    goto inicio;
}

void Calendario::planear(vector<Dia*> DIA,vector<Actividad*> ACT,vector<Alumno*> Alum){
  int i=0,j=0;/*i para recorrer los dias y j para recorrer las actividades*/
  int k=0,nda;/*en nda el constructor de Asignacion colocara cuantas Asignaciones van.*/
inicio:
  if(ACT[j]->TR<=DIA[i]->TD){
  	
    DIA[i]->TD-=ACT[j]->TR;
    DIA[i]->A.push_back(new Asignacion(ACT[j],ACT[j]->TR,Alum[k],&nda));
    j++;
    if(DIA[i]->TD==0)
      i++;
  }else{
    DIA[i]->A.push_back(new Asignacion(ACT[j],DIA[i]->TD,Alum[k],&nda));
    ACT[j]->TR-=DIA[i]->TD;
    i++;
  }
  if(nda>=3){
    k=(k+1)%NUMDALUMNOS;
  }
  if( !( (i==DIA.size())||(j==ACT.size()) ) )
    goto inicio;
}
