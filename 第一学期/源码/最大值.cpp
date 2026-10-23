#include<iostream>
using namespace std;
int findmax(int a[],int n){
	int ans=a[0];
	for(int i=1;i<n;i++){
	if(a[i]>ans){
		ans=a[i];
	}	
	}
	return ans;
}
int main(void){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max=findmax(a,n);
	cout<<max;
	for(int i=0;i<n;i++){
		if(a[i]==findmax(a,n)){
			cout<<" "<<i;
		}
	}
	return 0;
}
