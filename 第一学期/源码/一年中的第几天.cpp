#include<iostream>
using namespace std;
int main(){
	int year,month,day;
	cin>>year;
	cin>>month;
	cin>>day;
	int a[12]={0,31,59,90,120,151,181,212,243,173,303,334}; 
	if(year%4!=0){
		cout<<a[month-1]+day;
	}
	else if(month>3){
		cout<<a[month-1]+day+1;
	}
	else{
		cout<<a[month-1]+day;
	}
	return 0;
}
