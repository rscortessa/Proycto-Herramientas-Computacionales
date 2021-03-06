#include<iostream>
#include<cmath>
double seno(double x, double n);
double factorial(double result, double n);
int main ()
{
  std::cout.precision(8);
  int n=100;
  for(double x=0;x<2*M_PI;x+=0.1)
    {
    std::scientific;
    std::cout<<"Aprox "<<seno(x,n)<<" Built function "<<sin(x)<<std::endl;
    }
return 0;
}
double seno(double x, double n)//n va a indicar la precisión
{
  double sum=0;
  for(int i=1;i<n+1;i++)
    { 
     sum+=std::pow(-1,i-1)*std::pow(x,2*i-1)/(factorial(1,2*i-1));
    }
  return sum;
}

double factorial(double result, double n)
{
  if(n==1)
    {
      return result;
    }
  else
    {
    return  factorial(result*n,n-1);
    }
}
