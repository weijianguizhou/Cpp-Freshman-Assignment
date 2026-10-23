#include<iostream>
using namespace std;
size_t strLength(const char *s){
	if(s==nullptr)
	return 0;
	const char *s1=s;
	while(*s++!=0);
	return s-s1-1;
}
size_t strCopy(char *to,const char *from,size_t n){
	if(to ==nullptr||from==nullptr||n==0)
	return 0;
	size_t i=0;
	while(i<n-1 && *from !=0){
		*to++=*from++;
		i++;
	}
	*to=0;
	return i;
}
int main(){
	char *s1="Java Programming";
	char s2[]="C++ Programming";
	s1=s2;
	s1="C/C++ Programming";
	cout<<strLength(s1)<<":"<<s1<<endl;
	s1+=6;
	cout<<strLength(s1)<<":"<<s1<<endl;
	cout<<strLength(s2+4)<<endl;
	cout<<strLength("")<<endl;
	char *s3=nullptr;
	cout<<strLength(s3)<<endl;
	char s4[8]="No Use";
	cout<<strCopy(s4,s1,8)<<endl;
	cout<<s4<<endl;
	return 0;
}
