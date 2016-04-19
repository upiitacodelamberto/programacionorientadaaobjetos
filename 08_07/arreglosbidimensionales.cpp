#include <iostream>

using namespace std;

int EJEM2DIM[6][2];


void initEJEM(){
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<2;j++)
    {
      cout<<"A["<<i<<"]["<<j<<"]=";
      cin>>EJEM2DIM[i][j];
    }
  }
}

void printEJEM(){
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<2;j++)
    {
      cout<<EJEM2DIM[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}

void
multiplicar(int a,int b[],int size)
{
  int i=0;
  while(i<size){
    b[i]=a*b[i];
    i++;
  }
}

void
printarrunidim(int arr[],int size)
{
  int i=0;
  while(i<size){
    cout<<arr[i++]<<" ";
  }
  cout<<endl;
}














