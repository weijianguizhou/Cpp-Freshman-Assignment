#include<bits/stdc++.h>
using namespace std;
int peak(int *a,int *p,int n){
	int ans=0;
	for(int i=1;i<n-1;i++){
		if((*(a+i)>*(a+i-1)&&*(a+i)>*(a+i+1))||(*(a+i)<*(a+i-1)&&*(a+i)<*(a+i+1))){
			ans++;
			*(p+ans)=*(a+i);
		}
	}
	return ans;
}
int main(void){
	int a[600],p[600],n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int m=peak(a,p,n);
	for(int i=0;i<m;i++){
		cout<<p[i+1]<<" ";
	}
	cout<<endl;
	cout<<m<<endl;
	return 0;
}
