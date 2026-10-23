#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double x1,x2,a,b,c,delta;
	cout<<"以下程序用于计算ax^2+bx+c=0型一元二次方程的根"<<endl;
	cout<<"请输入二次项系数"<<endl;
	cin>>a;
	cout<<"请输入一次项系数"<<endl;
	cin>>b;
	cout<<"请输入常数项"<<endl;
	cin>>c;
	delta=b*b-4*a*c;
	if(a==0){
		cout<<"It's not a univariate quadratic equation"<<endl;
	}else if(delta<0){
		cout<<"no answer"<<endl;
	}else{
		x1=(-b+sqrt(delta))/2*a;
		x2=(-b-sqrt(delta))/2*a;
		cout<<"一个根为"<<x1<<endl;
		cout<<"另一个根为"<<x2<<endl;
	}
	return 0;
}
