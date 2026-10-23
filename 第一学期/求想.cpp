using namespace std;
#include <iostream>
#include<cmath>
float power(float x,int n){
//ÇóxµÄn´ÎÃÝ

 float pow=1;
 while(n--) pow*=x;
 return pow; }
int main(){
 int n=3;
 float x=4.6;
 char c='a';
 cout<<"power("<<x<<','<<n<<")="<<power(x,n)<<endl;
 cout<<"power("<<c<<','<<n<<")="<<power(c,n)<<endl;
 cout<<"power("<<n<<','<<x<<")="<<power(n,x)<<endl;
 return 0;
 }
