#include<iostream>
using namespace std;

double Transpuesta(double * A, const int N);

int main()
{
    const int N=5;
    double A[N*N], AT[N*N];

    //Se define las componentes de la matriz

    for(int ii=0; ii<N; ii++){
    for(int jj=0; jj<N; jj++){
            A[ii*N+jj] = ii*jj+ii;
            cout<< A[ii*N+jj] << "\t";}cout<<endl;}

    cout<<endl<<endl;


    //Se realiza la transpuesta de la matriz

    for(int ii=0; ii<N; ++ii){
        for(int jj=0; jj<N; ++jj){
            AT[ii*N+jj]=1.0*A[jj*N+ii];
            cout<< AT[ii*N+jj] << "\t";}cout<<endl;}

    cout<<Transpuesta(A,N);


    return 0;
}

//double Transpuesta(double * A, const int N)
//{
  //  double AT[N*N];

  //  for(int ii; ii<N; ++ii){
  //      for(int jj; jj<N; ++jj){
  //          AT[ii*N+jj]=1.0*A[jj*N+ii];
   //         cout<< AT[ii*N+jj] << "\t";}cout<<endl;}

   // return 0;
//}
