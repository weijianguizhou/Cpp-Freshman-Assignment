#include<iostream>
using namespace std;
int main(){
	int b[][4]={{11,12,13,14},
	            {21,22,23,24},
				{31,32,33,34},};
	int *p[]={b[0],b[1],b[2]};
	int **pp=p;
	for(int i=0;i<3;i++){
		cout<<pp[i][0]<<" ";
		cout<<*(pp[i]+1)<<" ";
		cout<<*(*(pp+i)+2)<<" ";
		cout<<(*(pp+i))[3]<<endl;
	}
	return 0;
}
