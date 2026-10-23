#include<bits/stdc++.h>
using namespace std;
int main(){
	double s,t;
	double bmi;
	char c;
	while(1){
		cin>>s>>t;
		bmi=t/(s*s);
		cout<<bmi<<endl;
		if(bmi<18.5){
			cout<<"体重过低"<<endl;
		}else if(bmi>=18.5&&bmi<=23.9){
			cout<<"体重正常"<<endl;
		}else if(bmi>=24&&bmi<=27.9){
			cout<<"超重"<<endl; 
		}else{
			cout<<"肥胖"<<endl;
		}
		cout<<"是否要计算下一次(y/n)"<<endl;
		cin>>c;
		if(c!='Y'&&c!='y')break;
	}
	return 0;
}
