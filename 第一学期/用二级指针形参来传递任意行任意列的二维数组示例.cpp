#include <iostream>
using namespace std;
void print2D(int **a,int row,int col){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<a[i][j]<<'\t';
			cout<<endl;
		}
	}
}
int main(void){
	int a[][4]={{1,2,3,4},
	            {3,4,5,6},
				{5,6,7,8}};
	int b[4][3],i,j;
	int *p1[]={a[0],a[1],a[2]};
	print2D(p1,3,4);
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			b[i][j]=a[j][i];
		}
	}
	int *p2[]={b[0],b[1],b[2],b[3]};
	print2D(p2,4,3);
	return 0;
}
