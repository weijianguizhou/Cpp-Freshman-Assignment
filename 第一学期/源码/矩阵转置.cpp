#include <iostream>
#include <vector>
using namespace std;

// 输入一个 n 阶方阵，输出它的转置
int main(){
   int n;
   cout<<"请输入方阵的阶数：";
   cin>>n;
   cout<<endl;

   vector<vector<int> > a(n, vector<int>(n));
   cout<<"请输入 "<<n<<" 行，每行 "<<n<<" 个整数："<<endl;
   for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                   cin>>a[i][j];
           }
   }

   cout<<"转置后的矩阵："<<endl;
   for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                   cout<<a[j][i]<<" ";
           }
           cout<<endl;
   }
   return 0;
}
