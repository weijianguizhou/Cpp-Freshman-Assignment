#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct Date{
	short year,month,day;
};
struct Employee{
	string num,name;
	char sex;
	Date birthday;
	float salary;
	Employee*manager;
};
void printAnDate(Date*d){
	if(d)
	cout<<d->year<<'.'<<d->month<<'.'<<d->day;
}
void printTitle(){
	cout<<setw(5)<<"编号"<<setw(10)<<"姓名"<<setw(5)<<"性别";
	cout<<setw(13)<<"出生日期"<<setw(8)<<"工资"<<setw(12)<<"经理姓名"<<endl; 
}
void printAnEmp(Employee*emp){
	if(emp==nullptr)
	return;
	cout<<setw(5)<<emp->num<<setw(10)<<emp->name;
	cout<<setw(5)<<(emp->sex=='f'?"女":"男");
	cout<<setw(5)<<' ';
	printAnDate(&emp->birthday);
	cout<<setw(8)<<emp->salary;
	cout<<setw(12)<<(emp->manager==nullptr?"空":emp->manager->name)<<endl;
}
void printEmps(Employee emps[],int n){
	printTitle();
	for(int i=0;i<n;i++){
		printAnEmp(&emps[i]);
	}
}
void setManager(Employee emp[],int n,Employee*mgr){
	for(int i=0;i<n;i++){
		emp[i].manager=mgr;
	}
}
int main(void){
	Employee emps[]={{"021","张三",'m',{1983,3,4},3456},
	                 {"024","李四",'f',{1977,8,3},4567},
					 {"027","王五",'m',{1970,9,2},5432}};
	int n=sizeof(emps)/sizeof(Employee);
	printEmps(emps,n);
	setManager(emps,n,&emps[2]);
	printEmps(emps,n);
	setManager(emps,n,nullptr);
	printEmps(emps,n);
	return 0;
}
