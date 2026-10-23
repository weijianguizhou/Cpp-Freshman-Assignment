#include <bits/stdc++.h>
using namespace std;
int StrToInt(char *str,int *b){
	int num=0;
	int t=0;
	for (int i = 0; i <100; i++) {
	if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
        } 
    else if((str[i]<'0'||str[i]>'9')&&(str[i-1] >= '0' && str[i-1] <= '9')){
    	t+=1;
    	b[t]=num;
    	num=0;
	}
    }
    return t;
}
int main(void){
	char str[100];
	int a[500],num,i;
	cin.getline(str,100);
	num=StrToInt(str,a);
	for(i=0;i<num;i++){
		cout<<a[i+1]<<endl;
	}
	cout<<num<<endl;
	return 0;
}
