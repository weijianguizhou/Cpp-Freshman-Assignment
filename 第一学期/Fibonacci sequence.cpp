#include <iostream>
#include <iomanip>
using namespace std;
int Fib(int n){
	if(n==1||n==2){
		return 1;
	}else{
		return Fib(n-1)+Fib(n-2);
	}
}
int main(void){
	cout<<"This program is used to output the first n terms of the Fibonacci sequence"<<endl;
	int i,n;
	cout<<"Please input a Positive integer:";
	cin>>n;
	for(i=1;i<=n;i++){
		cout<<setw(10)<<Fib(i);
		if(i%5==0){
			cout<<"\n";
		}
	}
	cout<<"\n";
	return 0;
}
