#include<bits/stdc++.h>
using namespace std;
//由百分制成绩计算返回绩点 
float getJD1(float f){
	if (f >= 90) return 4.0f;
	else if (f >= 85)	return 3.7f;
	else if (f >= 82)	return 3.3f;
	else if (f >= 78)	return 3.0f;
	else if (f >= 75)	return 2.7f;
	else if (f >= 72)	return 2.3f;
	else if (f >= 68)	return 2.0f;
	else if (f >= 64)	return 1.5f;
	else if (f >= 60)	return 1.0f;
	else return 0.0f;		
}
//由等级成绩计算，{优秀 ，良好，中等，及格，不及格} 
float getJD2(const string f){
	if (f =="优秀") return 4.0f;
	else if (f =="良好") return 3.0f;
	else if (f =="中等") return 2.0f;	
	else if (f =="及格") return 1.0f;	
	else if (f =="不及格") return 0.0f;
	else return 0.0f;
}
int main(){
	int n;
	cin>>n;
	float s = 0;
	for (int i = 0; i<n;i++){
		string str;
		cin>>str;
		float f ;
		if (str =="优秀" || str =="良好" ||str =="中等" 
                       ||str=="及格" || str =="不及格" )
			f = getJD2(str);
		else
			f = getJD1(stof(str));
		s += f;
	}
	cout<<s/n<<endl;
}


