#include<bits/stdc++.h>
using namespace std;
int main(void){
	string a;
	cin>>a;
	int ni=0;
	for(int i=0;i<a.length();i++){
		for(int j=0;j<i;j++){
			if(a[i]<a[j]){
				ni+=1;
			}
		}
	}
	cout<<ni<<endl;
	return 0;
}
