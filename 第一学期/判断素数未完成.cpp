#include <iostream>
using namespace std;
bool isPrime(unsigned n){
	if (n<2)
	return false;
	if (n==2||n==3||n==5||n==7)
	return true;
	for (unsigned i=2;i*i<=n;i++)
	if (n%i==0)
	}
