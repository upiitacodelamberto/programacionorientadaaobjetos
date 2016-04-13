#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int m,M;
	int n,N;
	int q,r;
	/*Para numeros mas grandes, por ejemplo m=64,n=12,
	  el numero de iteraciones es mayor que para 24 y 16*/
	M=m=1024;
	N=n=96;
	q=m/n; 
	r=m-q*n;
	printf("q=%i, r=%i\n",q,r);
	if(r==0){
		printf("mcd(%i,%i)=%i\n",M,N,n);
	}else{
		m=n;
		n=r;
	}
	q=m/n; 
	r=m-q*n;
	printf("q=%i, r=%i\n",q,r);
	if(r==0){
		printf("mcd(%i,%i)=%i\n",M,N,n);
	}else{
		m=q;
		n=r;
	}
	q=m/n; 
	r=m-q*n;
	printf("q=%i, r=%i\n",q,r);
	if(r==0){
		printf("mcd(%i,%i)=%i\n",M,N,n);
	}else{
		m=q;
		n=r;
	}
	q=m/n; 
	r=m-q*n;/*para los valores 1024 y 96,aqui r debe ser 0*/
	printf("q=%i, r=%i\n",q,r);
	if(r==0){
		printf("mcd(%i,%i)=%i\n",M,N,n);
	}else{
		m=q;
		n=r;
	}
	system("pause");	
	return 0;
}
