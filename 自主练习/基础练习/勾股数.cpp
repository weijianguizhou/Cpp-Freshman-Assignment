#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ans=0;
	int k;
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			k=sqrt(i*i+j*j);
			if(k>n||k*k!=i*i+j*j){
				continue;
			}else{
				++ans;
			}
		}
	}
	cout<<ans;
	return 0;
}


