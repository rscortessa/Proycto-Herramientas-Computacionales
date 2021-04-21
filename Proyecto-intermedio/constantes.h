//Librerias
 #include <stdio.h>
 #include <stdlib.h>
 #include "papi.h"
//Definición de funciones
void multiplicacion_directa(const double  * A, const double  * B, double* C,const int N);
// Variables
 float real_time, proc_time,mflops;
 long long flpops;
 float ireal_time, iproc_time, imflops;
 long long iflpops;
 int retval;
 double  A[4]={1,0,0,1};
 double  B[4]={1,1,1,1};
 double  C[4]={0};
