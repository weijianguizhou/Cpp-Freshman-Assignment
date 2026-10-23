#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int i=1,j=1;
	while(i<=9){
		while(j<=i){
			cout<<i<<"*"<<j<<"="<<i*j<<setw(2);
			j++;}j=1;
		cout<<endl;
		i++;
}
}
