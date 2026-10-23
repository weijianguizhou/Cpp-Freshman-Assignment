#include<bits/stdc++.h>
using namespace std;
string convert(int n){
	string t[]={"¼×","ÒÒ","±û","¶¡","Îì","¼º","¸ı","ĞÁ","ÈÉ","¹ï"};
	string d[]={"×Ó","³ó","Òú","Ã®","³½","ËÈ","Îç","Î´","Éê","ÓÏ","Ğç","º¥"};
	string ans;
	int m,k;
	m=abs(n%10);
	k=abs(n%12);
	if(n<0){
		if(m<8){
			ans=t[7-m];
		}else{
			ans=t[17-m];
		}
		if(k<10){
			ans+=d[9-k];
		}else{
			ans+=d[21-k];
		}
	}else{
		if(m>3){
			ans=t[m-4];
		}else{
			ans=t[m+6];
		}
		if(k>3){
			ans+=d[k-4];
		}else{
			ans+=d[k-8];
		}
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<convert(n);
	return 0;
}


