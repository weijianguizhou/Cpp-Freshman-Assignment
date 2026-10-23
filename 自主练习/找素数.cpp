#include <iostream>
#include <cmath>
using namespace std;

// 判断一个数是否为素数
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int A, B;
    cin >> A >> B;
    int count = 0;
    for (int i = A; i <= B; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}


