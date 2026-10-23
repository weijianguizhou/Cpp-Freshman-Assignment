#include <iostream>
using namespace std;

// 数组的维度由模板参数推导，形参写成数组引用才不会退化为指针
template<class T,int N1,int N2>
void print(const T (&a)[N1][N2]){
   for(int i=0;i<N1;i++){
           for(int j=0;j<N2;j++){
                   cout<<a[i][j]<<" ";
           }
           cout<<endl;
   }
}

int main(void){
   int a[][4]={{1,2,3,4},
               {3,4,5,6},
                           {5,6,7,8}};
   int b[4][3];
   cout<<"原矩阵："<<endl;
   print(a);
   for(int i=0;i<4;i++){
           for(int j=0;j<3;j++){
                   b[i][j]=a[j][i];
           }
   }
   cout<<"转置后的矩阵："<<endl;
   print(b);
   return 0;
}
