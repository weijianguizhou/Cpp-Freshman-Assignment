#include <iostream>
using namespace std;
int main(void){
	int a[100];
	for(int i=0;;i++){
		cin>>a[i];
		if(a[i]==0){
			break;
		}
	}
	int n=0;
	n=sizeof(a)/sizeof(a[0]);
	int b[n];
	for(int i=0;i<n-1;i++){
		b[i]=a[n-2-i];
		}
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
