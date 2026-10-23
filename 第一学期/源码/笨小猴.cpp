#include<bits/stdc++.h>
using namespace std;
int luck(string s){
	int a[26];
	for(int i=0;i<s.length();i++){
		a[s[i]-'a']++;
	}
	int minn=1000;
	int maxn=0;
	for(int i=0;i<26;i++){
		if(maxn<=a[i]){
			maxn=a[i];
		}
		if(minn>=a[i]){
			minn=a[i];
		}
	}
	int c;
	c=maxn-minn;
	return c;
}
bool prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(void){
	string s;
	cin>>s;
	int a=luck(s);
	if(prime(a)){
		cout<<"Lucky Word"<<endl;
		cout<<a<<endl;
	}else{
		cout<<"No Answer"<<endl;
		cout<<0<<endl;
	}
	return 0;
}
