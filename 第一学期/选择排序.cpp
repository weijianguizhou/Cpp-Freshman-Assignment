#include <iostream>
using namespace std;
void selectSort(int data[],int n){
	int i,j,minValue,minIndex,temp;
	for(i=0;i<n-1;i++){
		minValue=data[i];
		minIndex=i;
		for(j=i+1;j<n;j++){
			if(minValue>data[j]){
				minValue=data[j];
				minIndex=j;
			}
		}
		if(i!=minIndex){
			temp=data[i];
			data[i]=data[minIndex];
			data[minIndex]=temp;
		}
	}
}
int main(void){
	int a[6]={6,4,2,1,3,5};
	selectSort(a,6);
	for(int y:a){
		cout<<y<<"\t";
	}return 0;
}
