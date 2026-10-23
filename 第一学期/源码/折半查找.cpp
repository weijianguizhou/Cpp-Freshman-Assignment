#include <iostream>
using namespace std;
int main(){
	int n =10;
    int s[n]={ -56, -23, 0, 8, 10, 12, 26, 38, 65, 98 }; 
	int low, high, binary, x;
	cout<<"input x=";
	cin>>x;							
	low=0; 
	high=n-1;				
	binary=(low+high)/2;			//确定折半位置
	while ( x!=s[binary] && low<=high ){
		if (x<s[binary]) high=binary-1;		//在前半区间查找
		else low=binary+1;			//在后半区间查找
		binary=(low+high)/2;
	}
	if (low<=high)
	    	cout<<"查找成功! 是数组中的第"<<binary+1<<"个元素。"<<endl;
	else 
		cout<<"查找失败!"<<endl;
}

