#include "Fecha.h"
#include "Dia.h"

int Dia::diasacumulados[]={31,/*enero*/
                           31+29,/*hasta febrero*/
						   31+29+31,/*marzo*/
						   31+29+31+30,/*abril*/
						   31+29+31+30+31,/*mayo*/
						   31+29+31+30+31+30,/*junio*/
						   31+29+31+30+31+30+31,/*julio*/
						   31+29+31+30+31+30+31+31,/*agosto*/
						   31+29+31+30+31+30+31+31+30,/*septiembre*/
						   31+29+31+30+31+30+31+31+30+31,/*oct*/
						   31+29+31+30+31+30+31+31+30+31+30,/*nov*/};


void Dia::calc_consecutivo(){
  if(f->m)
    f->consecutivo=f->d+diasacumulados[f->m-1]; /*febrero,marzo,...,diciembre*/
  else
    f->consecutivo=f->d;  /*para las dfechas de enero*/
}
