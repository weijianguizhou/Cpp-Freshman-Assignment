#include<bits/stdc++.h>
using namespace std;
int main(){
	const char *w="wz zxh lyn";
	char w2[]="wz xh lyn";
	cout<<w<<endl;
	cout<<w2<<endl;//输出完整的字符串（包括空格）
	w=w2;//讲w2赋给w 
	cout<<w<<endl; 
	//strcpy(w,"love");//用指针定义的字符串内容不可更改， 
	strcpy(w2,"wz"); 
	cout<<w2<<endl;
	strcpy(w2+2," love yn");
	cout<<w2<<endl;//字符串的拷贝操作
	strcat(w2," 1314");
	cout<<w2<<endl;//字符串拼接 
    const char *a[]={"lyn","zxh","wz"};
    cout<<a[1]+1<<endl;//此时，a[1]解引用zxh的首地址,等效于*(a+1)得到一个行指针，然后对应列后移一个，并输出后面的。 
    cout<<a+1<<endl;// a对应的是 一个指针，与直接定义的指针输出类似，见下。 
    int *p;
    int l=20060927;
    p=&l;
    cout<<p<<endl;
    cout<<*p<<endl;
    const char *c="lyn";//这个可看作第一个指针的数组中的一个元素 
    cout<<c<<endl;
    cout<<c+1<<endl; 
    cout<<*c<<" "<<*(c+0)<<" "<<c[0]<<endl;//这三个表达式等价，相当于取出第一个字符"l" 
    cout<<*c+1<<endl;//对一个字符作加减运算，输出对应ASCII码 
	return 0;
}
