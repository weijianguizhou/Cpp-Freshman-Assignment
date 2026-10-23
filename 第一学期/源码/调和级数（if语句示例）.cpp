#include <iostream>
using namespace std;
int main(void){
	int n=1;
	double sum=0;
	while (sum<2){
		sum+=1.0/n;
		n++;
	}
	cout<<"n="<<n-1<<"sum="<<sum<<endl;
	return 0;
}
