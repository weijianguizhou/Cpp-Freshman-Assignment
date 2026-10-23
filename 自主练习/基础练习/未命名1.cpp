#include<bits/stdc++.h>
using namespace std;

// 读入若干整数（以 0 结束，0 本身不参与输出），再倒序输出
int main(){
   vector<int> vec;
   int n=0;
   while(cin>>n&&n!=0){
           vec.push_back(n);
   }

   int size=vec.size();
   cout<<"倒序输出："<<endl;
   for(int i=size-1;i>=0;i--){
           cout<<vec.at(i)<<" ";
   }
   cout<<endl;
   return 0;
}
