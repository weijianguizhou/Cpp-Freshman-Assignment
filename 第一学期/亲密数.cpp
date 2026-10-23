#include<bits/stdc++.h>
using namespace std;
int f(int n){
	int ans=0;
	for(int i=1;i<n/2+1;i++){
		if(n%i==0){
			ans+=i;
		}
	}
	return ans;
}
int main(){
	for(int i=1;i<=3000;i++){
		for(int j=i;j<3000;j++){
			if(f(i)==j&&f(j)==i&&j!=i){
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	return 0;
}


