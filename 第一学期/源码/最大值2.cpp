using namespace std;
#include <iostream>
int main(void){
	const int n = 5;
	float a[n+1] = {5, 0, -3.2, 2, 6.2, -8}, y = a[0], x;
	cout<<"input x=";
	cin>>x;
	for(int i = 0; i < n; i++)	
		y = y * x + a[i+1];	
	cout<<"y="<<y<<endl;
    return 0;
}

