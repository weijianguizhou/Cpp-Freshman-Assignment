#include<iostream>
using namespace std;
int digitSum(int n){
	int lastnum,sum;
	sum=0;
	while(n!=0){
		lastnum=n%10;
		sum+=lastnum;
		n/=10;
	}
	return sum;
}
int main(){
	int n;
	cout<<"Please input a Positive integer:";
	cin>>n;
	cout<<"The result is:"<<digitSum(n)<<endl;
}
