#include<iostream>
using namespace std;
int lily(int i){
	i=(i%10)*(i%10)*(i%10)+(i/10%10)*(i/10%10)*(i/10%10)+(i/100)*(i/100)*(i/100);
	return i;
}
int main(void){
	int n;
	cout<<"请输入一个三位数:";
	cin>>n;
	if(n<100||n>999){
		cout<<"Input error."<<endl;
		}else if(lily(n)==n){
			cout<<"water lily number"<<endl;
			
		}else{
			cout<<"No."<<endl;
		}return 0;
	}

