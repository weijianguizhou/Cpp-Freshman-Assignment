#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    string word;
    cin >> word;

    int char_count[26] = {0};
    for (int i = 0; i < word.length(); i++) {
        char_count[word[i] - 'a']++;
    }

    int maxn = 0, minn = 100;
    for (int i = 0; i < 26; i++) {
        if (char_count[i] > 0) {
            maxn = max(maxn, char_count[i]);
            minn = min(minn, char_count[i]);
        }
    }

    if (isPrime(maxn - minn)) {
        cout << "Lucky Word" << std::endl;
        cout << maxn - minn << std::endl;
    } else {
        cout << "No Answer" << std::endl;
        cout << 0 << std::endl;
    }

    return 0;
}
