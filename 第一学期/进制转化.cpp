#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,n;
	cin>>a>>n;
	int s[10000],m=0;
	while(a!=0){
		s[++m]=a%n;
		a=a/n;
	}
	for(int i=m;i>=1;i--)
	cout<<s[i];
	return 0;
}
