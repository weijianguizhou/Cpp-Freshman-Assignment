#include <iostream>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;
    int p[1000];
    for(i=0;i<=n;i++)
    	p[i]=1;
    for(i=2;i<=n;i++)
	if(p[i]==1)
		for(j=2;i*j<=n;j++) p[i*j]=0;
    for(i=2;i<=n;i++)
              if(p[i]) cout<<i<<' ';
    return 0;
}

