#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std; 

void swap(float* p, float* q) {
	float temp = *p;
	*p = *q;
	*q = temp;
}

void standardize(float* p, float min, float max) {
	*p = (*p - min) / (max - min);
}

int main(){

	ifstream ifs;
	ifs.open("E:\\下载文件\\浏览器\\TN2006-ILS-results.csv");
	if(ifs.fail()){
		cout<<"打开文件出错了"<<endl;
		return 0; 
	}
	
	vector<string>item;//向量容器item 
	float Su [44];
	float Sy [44];
	string temp;//中间字符串temp 
	while(getline(ifs,temp)){
		item.push_back(temp);
	}//把ifs读入item 

	vector<string>::iterator it; 
	int a=0;//a用来给数组赋值 
	for(it=item.begin();it!=item.end();it++){		//it初始化为item中第一个元素，遍历item 
		string str;
		istringstream istr(*it);
		if(it==item.begin()){
			continue;
		}
		for(int i=0;i<10;i++){
			getline(istr,str,',');
			if(i==3){
				float temp1=std::stof(str);
				Su[a]=temp1; 
			}
			else if(i==4){
				float temp2=std::stof(str);
				Sy[a]=temp2;
				a++;     
			}
			else
				continue;
		}
	}
	
	for (int i = 43; i >= 0; i--) {         //按Su大小排序
		for (int j = 0; j < i; j++) {
			if (Su[j] > Su[j + 1]) {
				swap(&Su[j], &Su[j + 1]);
				swap(&Sy[j], &Sy[j + 1]);
			}
		}
	}

	float minSu = Su[0], maxSu = Su[43], minSy = Sy[0], maxSy = Sy[42];    //min-max标准化
	for (int i = 0; i <= 43; i++) {        
		standardize(&Su[i], minSu, maxSu);
		standardize(&Sy[i], minSy, maxSy);
	}
	
	for(int b=0;b<44;b++){
		cout<< fixed << setprecision(3) << Su[b] << ' ' << fixed << setprecision(3) << Sy[b] << endl;
	}
	system("pause");
	return 0;
}

