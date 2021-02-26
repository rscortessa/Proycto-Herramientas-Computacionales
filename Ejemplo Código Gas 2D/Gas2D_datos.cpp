//Simulacion de un gas ideal 2D de N=25 partículas
#include <iostream>
#include <cmath>
#include "Random64.h"
using namespace std;

const double Deltat=0.01;
const double chi=0.193183325037836;

const double VEL0=10;
const double K=50;

const double Lx=100,Ly=100;
const int Nx=5,Ny=5,N=Nx*Ny;

class Cuerpo;
class Colisionador;
//--------------------class Cuerpo -----------------------
class Cuerpo{
private:
  double m,R,x,y,Vx,Vy,Fx,Fy;
public:
  void Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0);
  void Mueva_r1(double dt);
  void Mueva_V(double dt);
  void Mueva_r2(double dt);
  void Dibujese(void);

  double Getx(void){return x;};
  double Gety(void){return y;};
  double GetEc(void){return m*(Vx*Vx+Vy*Vy);};
  double GetV(void){return sqrt(Vx*Vx+Vy*Vy);};
  double GetVx(void){return Vx;};
  friend class Colisionador;
};
void Cuerpo::Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0){
  x=x0; y=y0; Vx=Vx0; Vy=Vy0; m=m0; R=R0;
}
void Cuerpo::Mueva_r1(double dt){
  x+=Vx*chi*dt;  y+=Vy*chi*dt;
}
void Cuerpo::Mueva_V(double dt){
  Vx+=Fx*(dt/(2*m));  Vy+=Fy*(dt/(2*m));
}
void Cuerpo::Mueva_r2(double dt){
  x+=Vx*((1-2*chi)*dt);  y+=Vy*((1-2*chi)*dt);
}
void Cuerpo::Dibujese(void){
  cout<<" , "<<x<<"+"<<R<<"*cos(t),"<<y<<"+"<<R<<"*sin(t)"; 
}
//--------------------class Colisionador -----------------------
class Colisionador{
private:
  double Ep;
public:
  void Inicie(void);
  void CalculeFuerzas(Cuerpo *Grano);
  void Choque(Cuerpo &Cuerpo1,Cuerpo &Cuerpo2);
  double GetEp(void){return Ep;};
};
void Colisionador::Inicie(void){
  Ep=0;
}
void Colisionador::CalculeFuerzas(Cuerpo *Grano){
  int i,j;
  Ep=0;
  for(i=0;i<N+4;i++)  
    {Grano[i].Fx=0; Grano[i].Fy=0;}
  for(i=0;i<N;i++)  
    for(j=i+1;j<N+4;j++)
      Choque(Grano[i],Grano[j]);
}
void Colisionador::Choque(Cuerpo &Cuerpo1,Cuerpo &Cuerpo2){
  double h,R1,R2,dx,dy,d,m1,m2,m12,Fn,Fx,Fy;
  dx=Cuerpo1.x-Cuerpo2.x;  dy=Cuerpo1.y-Cuerpo2.y;
  d=sqrt(dx*dx+dy*dy);  h=Cuerpo1.R+Cuerpo2.R-d;

  if(h>0){
    Fn=K*pow(h,1.5);
    Fx=Fn*dx/d;    Fy=Fn*dy/d;
    Cuerpo1.Fx+=Fx;     Cuerpo1.Fy+=Fy;
    Cuerpo2.Fx-=Fx;     Cuerpo2.Fy-=Fy;
    Ep+=K/2.5*pow(h,2.5);
  }
}

//--------------------Funciones de Animacion -----------------------

void InicieAnimacion(void){
  //    cout<<"set terminal gif animate"<<endl; 
  //    cout<<"set output 'Relajacion.gif'"<<endl;
  cout<<"unset key"<<endl;
  cout<<"set xrange [-10:110]"<<endl;
  cout<<"set yrange [-10:110]"<<endl;
  cout<<"set size ratio -1"<<endl;
  cout<<"set parametric"<<endl;
  cout<<"set trange [0:7]"<<endl;
  cout<<"set isosamples 12"<<endl; 
}
void InicieCuadro(void){
    cout<<"plot 0,0 ";
    //    cout<<" , "<<100/7<<"*t,0";
    //    cout<<" , "<<100/7<<"*t,100";
    //    cout<<" , 0,"<<100/7<<"*t";
    //    cout<<" , 100,"<<100/7<<"*t";
}
void TermineCuadro(void){
    cout<<endl;
}

int main(){
  Cuerpo Grano[N+4];
  Colisionador Cundall;
  Crandom Ran2(0);
  double t,tdibujo,dx,dy,R,Alpha,Ec,Ep;  
  int i;

  //  InicieAnimacion();  
  Cundall.Inicie();
  //-------------(x0 ,y0,Vx0,Vy0,m0,R0);
  //PAREDES
  //Pared izquierda
  Grano[N].Inicie(-10000,Ly/2,0,0,0.1,10000); 
  //Pared derecha
  Grano[N+1].Inicie(Lx+10000,Ly/2,0,0,0.1,10000); 
  //Pared abajo
  Grano[N+2].Inicie(Lx/2,-10000,0,0,0.1,10000); 
  //Pared arriba
  Grano[N+3].Inicie(Lx/2,Ly+10000,0,0,0.1,10000); 
  //GRANOS
  dx=Lx/(Nx+1); dy=Ly/(Ny+1); R=dx/3; if(dx/3 > dy/3) R=dy/3;
  for(i=0;i<N;i++){
    Alpha=2*M_PI*Ran2.r();
    Grano[i].Inicie(((i%Nx)+1)*dx,((i/Ny)+1)*dy,VEL0*cos(Alpha),VEL0*sin(Alpha),1,R);
  }

  for(t=tdibujo=0;t<70;t+=Deltat,tdibujo+=Deltat){
    //Dibujar 
    /*
    if(tdibujo>20/120.0){
      InicieCuadro();
      for(i=0;i<N;i++) Grano[i].Dibujese();
      TermineCuadro();
      tdibujo=0;
    }
    */
    //Energias
    for(Ec=0,i=0;i<N;i++)
      Ec+=Grano[i].GetEc();
    Ep=Cundall.GetEp();
    
    if (t>2)
      for(i=0;i<N;i++) cout<<Grano[i].GetVx()<<endl;      //ACTIVAR PARA EL HISTOGRAMA DE Vx
      //      for(i=0;i<N;i++) cout<<Grano[i].GetV()<<endl;      //ACTIVAR PARA EL HISTOGRAMA DE V


    //Velocidad Verlet Optimizado
    for(i=0;i<N;i++) Grano[i].Mueva_r1(Deltat);
    Cundall.CalculeFuerzas(Grano);
    for(i=0;i<N;i++) {Grano[i].Mueva_V(Deltat);Grano[i].Mueva_r2(Deltat);}
    Cundall.CalculeFuerzas(Grano);
    for(i=0;i<N;i++) {Grano[i].Mueva_V(Deltat);Grano[i].Mueva_r1(Deltat);}
  }

  return 0;
}
