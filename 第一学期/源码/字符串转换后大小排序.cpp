#include <iostream>;
using namespace std;
void upp_to_low(char a[]){
	for(int i=0;a[i];i++)
		if(a[i]>'A'&&a[i]<'Z') a[i]=a[i]+'a'-'A';
}
void sort_substr(char a[]){
	int i,j;
	int upp=0,low=0;
	char t;
	while(1){
	    for(upp=low;a[upp]&&a[upp]!=' ';upp++);
	    for(i=low;i<upp-1;i++)
	    	for(j=i+1;j<=upp-1;j++)
		        if(a[j]<a[i]){
			        t=a[i];
                    a[i]=a[j];
                    a[j]=t;
			}
	    if(a[upp]==0)break;
	    low=upp+1;		
	}
}
int main(){
	char s[20][100];
	int n,i;
	cin>>n;
	cin.get();
	for(i=0;i<n;i++){
		cin.getline(s[i],99);
		upp_to_low(s[i]);
		sort_substr(s[i]);
	}
	for(i=0;i<n;i++)cout<<s[i]<<endl;
}


