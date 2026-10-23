using namespace std; 
#include <iostream> 
#include <iomanip> 
int main() 
{ 
 int i,j; 
 for( i=1;i<=9;i++) 
 { 
 for(j=1; j<=i; j++) 
 cout<<' '<<j<<'*'<<i<<'='<<setw(2)<<j*i; 
 cout<<endl; 
 } 
 return 0; 
} 

