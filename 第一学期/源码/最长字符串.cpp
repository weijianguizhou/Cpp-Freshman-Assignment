#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s,ans;
	ans=" ";
	for(int i=0;i<n;i++){
		cin>>s;
		if(s.length()>ans.length()){
			ans=s;
		}
	}
	cout<<ans;
	return 0;
}
