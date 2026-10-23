#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> vec;
	for(int i=0;;i++){
		int n=0;
		cin>>n;
		vec.push_back(n);
		if(n==0){
			break;
		}
	}
	int n=vec.size();
	for(int i=n-2;i>=0;i++){
		cout<<vec.at(i)<<" ";
	}
	return 0;
}


