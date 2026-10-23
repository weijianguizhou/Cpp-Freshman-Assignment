#include<iostream>
using namespace std;
int main() {
	
	int i;
	int arr[11] = {13,16,17,18,16,14,15,12,25,21,26};//初始化数组
	for (int i = 0; i < 10;i++) {//一共循环10次

		for (int j = 0; j < 10-i; j++) {//执行的次数依次递减
			if (arr[j]>arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;//交换值
			}
		}
	}
		
		
	
	for (int j = 0; j < 10; j++)//打印数组
	{
		cout << arr[j] << endl;
	}
	system("pause");
	return 0;
}

