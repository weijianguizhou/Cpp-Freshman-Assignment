#include<iostream>
using namespace std;
int main(){
	char a[101];
	int j=0;
	int n;
	for(int i=0;i<n;i++){
		cin.get(a[i]);
		j++;
		if(a[i]=='\n')
		break;
	}
	n=sizeof(a)/sizeof(a[0]);
	
	
	int sum=0;
	for(int i=0;i<j;i++){
		for(int k=0;k<i;k++){
			if(a[k]>a[i]){
				sum+=1;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
