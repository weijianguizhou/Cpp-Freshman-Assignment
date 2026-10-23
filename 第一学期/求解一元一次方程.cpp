#include<iostream>
using namespace std;
int main(){
	cout<<"本程序用于求解ax+b=0型一元一次方程"<<endl;
    float a,b,x;
    x=0;
    cout<<"请输入一次项系数"<<endl;
    cin>>a;
    cout<<"请输入常数项"<< endl;
    cin>>b;
    x=(-1)*b/a;
    if(a==0){
    	cout<<"error"<<endl;
    }else{
    	cout<<"结果为x="<<x<<endl;
    }
    return 0;
	
}

