#include<iostream>
using namespace std;
int factors(int);       //自定义一个求因子和的函数
int main(){           //函数主体
 int sum;
 for(int a=2;a<10000;a++)
 {
  sum=factors(a);       //引入自定义函数
  if((a==factors(sum))&&a<sum)   // 判断a的因子和求得的因子和是否等于a，且a小于它的因子和
  {
   cout<<a<<" "<<sum<<endl;    //输出a，空格和a的因子
  }
 }
 return 0;
}
int factors(int b)    //自定义求因子和的函数
{
 int s=b/2;
 int sum=0;
 for(int i=1;i<=s;i++)
 {
  if(b%i==0) sum+=i;
 }
 return sum;     //返回sum
}

