#include <stdio.h>
#include <stdlib.h>
#include "papi.h"
//Funciones de transposición
void transpuesta(double * A, const int N);
// Variables
float real_time, proc_time,mflops;
  long long flpops;
  float ireal_time, iproc_time, imflops;
  long long iflpops;
  int retval;
  int N=5;
  double A[25]={0};


