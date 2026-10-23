#include<bits/stdc++.h>
using namespace std;
bool pan(long long x,long long y){
	long long a=10,y1=y;
	if(x==y)
	  return true;
	while(a<=y){
		y1=y%a;
		if(y1==x)
		   return true;
		a=a*10;
	}
	return false;
}
int main(){
	long long n,x,y;
	cin>>n;
	for(x=1;x<=n;x++){
		y=x*x;
		if(pan(x,y))
		   cout<<x<<endl;
	}
	return 0;
}
