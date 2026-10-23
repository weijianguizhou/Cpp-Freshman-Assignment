#include <iostream>
#include<vector>
using namespace std;

// 行、列数在运行时才确定的二维数组，用 vector 实现
int main(void){
   int rows, cols;
   cout<<"请输入矩阵的行数和列数：";
   cin>>rows>>cols;

   vector<vector<double> > a(rows, vector<double>(cols));

   cout<<"请输入 "<<rows*cols<<" 个实数："<<endl;
   for(int i=0;i<rows;i++){
           for(int j=0;j<cols;j++){
                   cin>>a[i][j];
           }
   }

   cout<<"你输入的矩阵是："<<endl;
   for(int i=0;i<rows;i++){
           for(int j=0;j<cols;j++){
                   cout<<a[i][j]<<" ";
           }
           cout<<endl;
   }

   return 0;
}
