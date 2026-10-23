//编辑一个程序，输出6-10000中的亲和数。 a的所有因数之和等于b,b的所有因数之和为a，且a不等于b。 
#include <iostream>
using namespace std;
int yzh(int n){
	int sum=0;
	for(int i=1;i<=n/2;i++){
		if(n%i==0){
			sum+=i;
		}
	}
	return sum;
}
int main(){
	for(int i=6;i<=10000;i++){
		int c;
		c=yzh(i);
		if(yzh(c)==i&&c!=i){
			cout<<i<<","<<c<<endl;
			continue;
		}
		
	}
	
	return 0;
}
