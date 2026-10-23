#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=i;j<n+i;j++){
			cout<<a[j%26]; 
		}
		cout<<endl;
	}
	return 0;
}


