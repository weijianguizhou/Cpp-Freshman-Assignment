#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	srand(time(NULL));
	int x;
	int z=rand()%10;
	cout<<"猜数字，请输入一个整数（0-9），你有一次机会：";
	cin>>x;
	if(x>z){
		cout<<"你猜大了，正确的数是"<<z<<endl;
	}else if(x<z){
		cout<<"你猜小了，正确的数是"<<z<<endl;
	}else {
		cout<<"你猜对了"<<endl;
	}
	return 0;
}
