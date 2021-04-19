#include<iostream>
void multiplicacion_directa(const int * A, const int * B, int* C, const int N)
{
  for(int i=0;i<N*N;i++)
    {
      for(int j=0;j<N;j++)
	{
	  C[i]+=A[N*int(i/N)+j]*B[j*N+(i%N)];
	  
	}
    }
  
};

