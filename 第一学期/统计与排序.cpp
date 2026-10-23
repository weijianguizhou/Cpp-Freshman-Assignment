#include<bits/stdc++.h>
using namespace std;
struct node{
	string s;
	int x;
};
int T,n,f;
string st;
node a[101];
void lyn(node a[],int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i-1;j++){
			if(a[j].x<a[j+1].x){
				node temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main(){
	cin>>T;
	n=0;
	while(T--){
		cin>>st;
		f=0;
		for(int i=1;i<=n;i++){
			if(a[i].s==st){
				a[i].x++;
				f=1;
				break;
			}
		}//检索输入是否为已有字符 
		if(f==0){
			n++;
			a[n].s=st;
			a[n].x=1;
		}//存储第一次出现的字符 
	}
	lyn(a,n);
	for(int i=1;i<=n;i++){
		cout<<a[i].s<<":"<<a[i].x<<endl;//依次输出字符和对应次数 
	}
	return 0;
}
