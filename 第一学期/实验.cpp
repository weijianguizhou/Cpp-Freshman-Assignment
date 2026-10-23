#include <iostream>
using namespace std;
int main(){
	int x=1,i=1;
	for(;x<50;i++){
		if(x>=10)
		break;
		if(x%2!=0){
			x+=3;
			continue;
			
		}
		x-=-1;
		cout<<x<<' '<<i<<endl;
	}
	cout<<x<<' '<<i<<endl;
	return 0;
}
