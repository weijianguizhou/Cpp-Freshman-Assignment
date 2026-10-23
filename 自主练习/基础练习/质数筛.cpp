#include<bits/stdc++.h>
using namespace std;

// 埃氏筛：输出 2 ~ n 之间的所有素数
int main(){
   int n;
   cout<<"请输入上限 n：";
   cin>>n;
   if(n<2){
           cout<<"2 以内没有素数"<<endl;
           return 0;
   }

   vector<bool> isPrime(n+1,true);
   isPrime[0]=isPrime[1]=false;
   for(int i=2;i*i<=n;i++){
           if(isPrime[i]){
                   for(int j=i*i;j<=n;j+=i){
                           isPrime[j]=false;
                   }
           }
   }

   cout<<"2 ~ "<<n<<" 之间的素数："<<endl;
   for(int i=2;i<=n;i++){
           if(isPrime[i]){
                   cout<<i<<" ";
           }
   }
   cout<<endl;
   return 0;
}
