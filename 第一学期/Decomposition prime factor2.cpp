#include <iostream>
#include <vector>

using namespace std;

void primeFactors(int n) {
vector<int> factors; // 用于存储质因数的数组

// 先处理n中的所有2因子
while (n % 2 == 0) {
factors.push_back(2);
n /= 2;
}

// n现在是奇数，可以遍历奇数因子，从3开始，递增为2
for (int i = 3; i * i <= n; i += 2) {
// 处理i因子
while (n % i == 0) {
factors.push_back(i);
n /= i;
}
}

// 如果n是一个大于2的质数，则将其加入到因数数组中
if (n > 2){
factors.push_back(n);
}

// 打印结果
cout << "质因数为: ";
for (int i : factors) {
cout << i << " ";
}
}

int main() {
int n;
cout << "请输入一个整数：";
cin >> n;

primeFactors(n);

return 0;
}
