#include<iostream>
#include<algorithm>		
using namespace std;
int main() {
	int a[10];		//定义10个int元素的数组
	generate(a, a + 10, rand);	//调用generate生成伪随机数
	for (int x : a)		//输出显示
		cout << x << " ";
	cout << endl;
	sort(a, a + 10);		//调用sort升序排序
	for (auto x : a)			//输出显示
		cout << x << " ";
	cout << endl;
	if (binary_search(a, a + 10, 15724)) //调用二分查找
		cout << "15724 found" << endl;
	else
		cout << "15724 no found" << endl;
	auto it = find(a, a + 10, 15724);	//调用find做线性查找
	if (it == a + 10)
		cout << "15724 no found" << endl;
	else
		cout << *it << " found by find" << endl;
	return 0;
}

