#include<bits/stdc++.h>
using namespace std;
int he(int n){
	int ans;
	ans=0;
	for(int i=1;i<=n/2;i++){
		if(n%i==0){
			ans+=i;
		}
	}
	return ans;
} 
int main(){
	int n;
	cin>>n;
	for(int i=n;;i++){
		if(i==he(i)){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}


