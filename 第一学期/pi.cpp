#include <iostream>
using namespace std;
int main(void){
	int n=1;
	double t=1,pi=0;
	const double eps=1e-10;
	while(1.0/n>=eps){
		pi+=t/n;
		n+=2;
		t=-t;
	}
	cout<<"pi="<<4*pi<<";n="<<n<<endl;
	return 0; 
}
