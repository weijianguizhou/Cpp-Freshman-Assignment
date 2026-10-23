#include <iostream>
using namespace std;
bool prime(int x){
	if(x<2)
	   return false;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
		  return false;
		else return true;	
} 
int main(){
	int N;
	cout<<"Please input a Positive Integer:";
	cin>>N;
	for(int i=2;i<=N;i++){
		if(prime(i)){
		
		while(N%i==0){
				cout<<i<<"  ";
				N/=i; 
			}}
		else
		continue;
	
		
	}
	return 0;
}
