#include<bits/stdc++.h>
using namespace std;
char *findChar(char *s,char c){
	for(int i=0;s[i]!='\0';i++){
		if(s[i]==c){
			return &s[i];
		}
	}return NULL;
}
int main(void){
	char s[100],c,*p;
	cin.getline(s,99);
	cin.get(c);
	p=findChar(s,c);
	if(p==NULL){
		cout<<"No found"<<endl;
	}else{
		cout<<p;
	}
	return 0;
}
