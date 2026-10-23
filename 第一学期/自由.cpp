#include<bits/stdc++.h>
using namespace std;
void upp_to_low(char a[]){
	for(int i=0;a[i];i++){
		if(a[i]>='A'&&a[i]<='Z'){
			a[i]+='a'-'A';
		}
	}
}
void sort_substr(char a[]){
	char t;
	int i,j;
	int upp=0,low=0;
	while(1){for(upp=low;a[upp]!='\0'&&a[upp]!=' ';upp+=1){
			for(i=low;i<upp-1;i++){
				for(j=i+1;j<upp-1;j++){
					if(a[j]<a[i]){
						t=a[i];
						a[i]=a[j];
						a[j]=t;
					}
				}
			}if(a[upp]==' ')break;
		}low=upp+1;
		if(a[upp]=='\0')break;
	}
		
			
}
int main(){
	int n;
	cin>>n;
	cin.get();
	char a[20][100];
	for(int i=0;i<n;i++){
		cin.getline(a[i],100);
		upp_to_low(a[i]);
		sort_substr(a[i]);
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
