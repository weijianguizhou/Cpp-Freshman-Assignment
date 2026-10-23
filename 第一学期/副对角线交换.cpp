#include<iostream>
using namespace std;
int main(){
	int n=0;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j==0){
				cout<<a[n-1-j][n-1-i];
			}else{
				cout<<" "<<a[n-1-j][n-1-i];
			}
		}
		cout<<endl;
	}
	return 0;
}
