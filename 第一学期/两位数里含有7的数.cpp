#include<iostream>
using namespace std;
int main(void){
	int i=1;
	for(i=1;i<=100;i++){
		if(i%10==7|i/10==7){
			cout<<i<<endl;
		}
	}
}
