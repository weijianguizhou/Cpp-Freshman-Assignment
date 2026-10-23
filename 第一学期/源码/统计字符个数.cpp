#include <iostream>
using namespace std;
int main(void){
	int count=0;
	char ch=0;
	do{
		ch=cin.get();
		if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='b')
		count++;}while(ch!='\n');
	cout<<"count="<<count<<endl; 
		
} 
