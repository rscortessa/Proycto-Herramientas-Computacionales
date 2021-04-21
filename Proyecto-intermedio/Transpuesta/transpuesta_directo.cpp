void transpuesta(double * A, const int N)
{
   for(int ii=0; ii<N; ++ii){
   for(int jj=0; jj<N; ++jj){
     A[ii*N+jj]=1.0*(A[jj*N+ii]);
   }
}
}
