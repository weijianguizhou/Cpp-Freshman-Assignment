#include<iostream>
using namespace std;
unsigned long fac(unsigned long n){
	if(n==1){
		return 1;
	}else{
	 return n*fac(n-1); 
	}
}
int main(void){
	int n;
	cin>>n;
	cout<<fac(n)<<endl;
	return 0;
	
}
