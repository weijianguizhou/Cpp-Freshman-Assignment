#include<iostream>
using namespace std;
void move(char a,char b){
	cout<<a<<"to"<<b<<endl;
}
void hanoi(int n,char x,char y,char z){
	if(n==1){
		move(x,z);
	}else{
		hanoi(n-1,x,z,y);
		move(x,z);
		hanoi(n-1,y,x,z);
	}
	}
	unsigned hanoiCount(int n){
		if(n==1){
			return 1;
		}else{
			return hanoiCount(n-1)*2+1;
		}
	}
	int main(void){
		int n;
		while(1){
			cout<<"Input number of plates(0 to exit):";
			cin>>n;
			if(n==0)
			  break;
			if(n<0){
				cout<<"Input errror,retry"<<endl;
				continue;
			}
			hanoi(n,'A','B','C');
			cout<<hanoiCount(n)<<"steps\n";
		}
		return 0;
	}

