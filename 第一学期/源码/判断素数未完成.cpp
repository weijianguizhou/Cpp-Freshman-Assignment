#include <iostream>
using namespace std;

// 判断 n 是否为素数
bool isPrime(unsigned n){
   if (n<2)
   return false;
   if (n==2||n==3||n==5||n==7)
   return true;
   for (unsigned i=2;i*i<=n;i++)
   if (n%i==0)
   return false;
   return true;
}

int main(){
   unsigned n;
   cout<<"请输入一个正整数：";
   cin>>n;
   if (isPrime(n))
   cout<<n<<" 是素数"<<endl;
   else
   cout<<n<<" 不是素数"<<endl;
   return 0;
}
