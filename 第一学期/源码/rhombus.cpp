#include <iostream>
using namespace std;
int main(){
	int n,j,k;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			cout<<" ";
		}
		for(int k=1;k<=2*i-1;k++){
			cout<<"*";
		}
		for(int j=1;j<=n-i;j++){
			cout<<" "; 
		}
		cout<<"\n";
	}
	for(int t=1;t<=n;t++){
		for(int x=1;x<=t;x++){
			cout<<" ";
		} 
		for(int y=1;y<=2*(n-t)-1;y++){
			cout<<"*";
		}
		for(int x=1;x<=t;x++){
			cout<<" ";
		}
		cout<<"\n";
	}
	return 0;
} 
