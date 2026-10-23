#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	int b[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=0;j<i-1;j++){
			if(a[j]<a[i]){
				sum++;
				b[i]=sum++;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
