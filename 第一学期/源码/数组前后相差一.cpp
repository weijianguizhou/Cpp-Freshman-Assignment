#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[110];
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[i]-a[j])==1)
			  sum+=1;
		}
	}
	cout<<sum;
	return 0;
}
