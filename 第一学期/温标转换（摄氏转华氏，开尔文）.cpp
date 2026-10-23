#include <iostream>
using namespace std;
int main(void){
    float C,F,K;
    cout<<"输入摄氏温度";
    cin>>C;
	F=C*1.8+32.0;
	K=C+273.15;
	cout<<"对应华氏温度为："<<F<<endl;
	cout<<"对应绝对温度为："<<K<<endl;
	return 0;

}
