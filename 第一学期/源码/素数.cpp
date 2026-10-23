#include<iostream>
using namespace std;
int main(void){
	int count=1;
	cout<<2<<" ";
	for(int i=3;i<=100;i+=2){
		int j=3;
	    for(j=3;j*j<=i;j+=2){
	    	if(i*j==0)
	    	break;
	    if(j*j>i){
	    		count++;
	    		cout<<i<<" ";
	    if(count%10==0)
	    	cout<<endl;
			}
		}
}
	cout<<"\ntotal"<<count<<"primes"<<endl;
	return 0;
}
