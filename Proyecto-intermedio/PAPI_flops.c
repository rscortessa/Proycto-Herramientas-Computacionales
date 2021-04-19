#include <stdio.h>
#include <stdlib.h>
#include "papi.h"
#include "funciones.h"

int main()
{ 
  float real_time, proc_time,mflops;
  long long flpops;
  float ireal_time, iproc_time, imflops;
  long long iflpops;
  int retval;
  if((retval=PAPI_flops_rate(PAPI_FP_OPS,&ireal_time,&iproc_time,&iflpops,&imflops)) < PAPI_OK)
  { 
    printf("Could not initialise PAPI_flops \n");
    printf("Your platform may not support floating point operation event.\n"); 
    printf("retval: %d\n", retval);
    exit(1);
  }

  double  A[4]={1,0,0,1};
  double  B[4]={1,1,1,1};
  double  C[4]={0};
  multiplicacion_directa(A,B,C,2);

  
  if((retval=PAPI_flops_rate(PAPI_FP_OPS,&real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
  {    
    printf("retval: %d\n", retval);
    exit(1);
  }


  printf("Real_time: %f Proc_time: %f flpops: %lld MFLOPS: %f\n", 
         real_time, proc_time,flpops,mflops);

  exit(0);
}


