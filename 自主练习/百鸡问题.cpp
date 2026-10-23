#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z,n,m,ans;
	cin>>x>>y>>z>>n>>m;
	ans=0;
	for(int i=0;i<=n;i++){
		for(int j=0;i+j*x<=n;j++){
			if(i+j*x+(m-i*z-j)*y==n)
			++ans;
		}
	}
	cout<<ans;
	return 0;
}


