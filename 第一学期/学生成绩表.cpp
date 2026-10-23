#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
struct Student{
	string num,name;
	char sex;
	float mathscore;
};
void printTitle(){
	cout<<setw(6)<<""<<setw(10)<<"";
	cout<<setw(5)<<""<<setw(6)<<""<<endl; 
}
void printAStud(const Student*s){
	cout<<setw(6)<<s->num<<setw(10)<<s->name;
	cout<<setw(5)<<s->sex<<setw(6)<<s->mathscore<<endl;
}
void printStuds(Student*s[],int n){
	printTitle();
	for_each(s,s+n,[](auto stu){printAStud(stu);});
}
void printChoice(){
	cout<<"选择0，退出\n";
	cout<<"选择1，按学号升序排序\n";
	cout<<"选择2，按姓名升序排序\n";
	cout<<"选择3，按性别排序\n";
	cout<<"选择4，按数学成绩降序排列\n";
}
int main(void){
	Student st[]={{"002","Wangping",'f',84},{"001","Zhangmin",'m',64},
	              {"004","Wanghong",'m',75},{"003","Lilei",'m',92},
				  {"006","Liuming",'m',75},{"005","Meilin",'m',74},
				  {"008","Yetong",'f',89},{"007","Maomao",'m',78},
				  {"010","Zhangjie",'m',66},{"009","Wangmei",'f',39}};
	const int num=sizeof(st)/sizeof(Student);
	Student *t=st,*stp[num];
	generate(stp,stp+num,[&t]{return t++;});
	printStuds(stp,num);
	while(1){
		printChoice();
		int choice=0;
		cin>>choice;
		if(choice==0){
			break;
		}
		if(choice>=1 && choice <= 4){
			switch(choice){
				case 1:sort(stp,stp+num,[](auto s1,auto s2)
				           {return s1->num<s2->num;});
				           break;
				case 2:sort(stp,stp+num,[](auto s1,auto s2)
				           {return s1->name<s2->name;});
				           break;
				case 3:sort(stp,stp+num,[](auto s1,auto s2)
				           {return s1->sex<s2->sex;});
				           break;
				case 4:sort(stp,stp+num,[](auto s1,auto s2)
				           {return s1->mathscore<s2->mathscore;});
				           break;
			}
			printStuds(stp,num);
		}
	}
	return 0;
}
