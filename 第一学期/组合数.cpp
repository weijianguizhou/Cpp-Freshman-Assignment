#include <iostream>
using namespace std;
int factorial(int a){
	int x=1;
	for(int i=1;i<=a;i++){
		x*=i;
	}
	return x;
}
int Compose(int n,int k){
	int x=0;
	x=factorial(n)/(factorial(k)*factorial(n-k));
	return x;
}
int main(){
	char c;
	int a,b;
	cin>>c;
	while(c=-1){
		int n,k;
        cout<<"请输入a，b："<<endl;
        cin>>a>>b;
        while(a<=0||b<=0||a<b){
        	cout<<"input error"<<endl;
        	cin>>a>>b;
		}
		cout<<"组合数答案为："<<Compose(a,b)<<endl;}
	return 0;
}
		
		
		
        


