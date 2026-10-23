#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
void print(vector<int>& v) {
	cout << "Total " << v.size() << " elems:" << endl;
	for (auto x : v)
		cout << x << " ";
	cout << endl;
}
int main() {
	vector<int> v1(10); //定义一个vector有10个int元素
	srand((unsigned)time(NULL));
	generate(v1.begin(),v1.end(),[]{return rand()%100+1;}); //产生1-100随机数
	print(v1);
	sort(v1.begin(), v1.end(), [](auto x1, auto x2){return x1 < x2;});//排序
	print(v1);
	const int wanted = 65;
	if (binary_search(v1.begin(), v1.end(), wanted))	//二分查找
		cout << "found " << endl;
	else
		cout << "no found"<<endl;
	v1.erase(v1.begin()+3); //删除第4个元素
	print(v1);
	v1.insert(v1.begin()+3,100); //添加数据 
	print(v1); 
	return 0;
}

