#include <iostream>
using namespace std;
template<class T,int N1,int N2>
void print(const T(a)[N1][N2]){
	for(auto x:a){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}
int main(void){
	int a[][4]={{1,2,3,4},
	            {3,4,5,6},
				{5,6,7,8}};
	int b[4][3];
	print(a);
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			b[i][j]=a[j][i];
		}
	}
	print(b);
	return 0;
}
