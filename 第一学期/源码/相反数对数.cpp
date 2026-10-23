#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,sum;
	sum=0;
	cin>>n;
	float a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(abs(a[i])==abs(a[j]))
			  sum+=1;
		}
	}
	cout<<sum;
	return 0;
}
