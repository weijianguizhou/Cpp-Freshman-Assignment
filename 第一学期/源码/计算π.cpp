using namespace std; 
#include <iostream> 
#include <cmath> 
int main() 
{ 
 int s; 
 double n,t,pi; 
 t=1;pi=0;n=1.0;s=1; 
 while((fabs(t))>1e-10) 
 { pi=pi+t; 
 n=n+2; 
 s=-s; 
 t=s/n;} 
 pi=pi*4; 
 cout<<"pi="<<pi<<endl; 
} 
