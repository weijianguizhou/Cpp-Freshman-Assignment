#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    char currentChar = 'A';
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << currentChar;
            currentChar = (currentChar - 'A' + 1) % 26 + 'A';
        }
        cout << endl;
    }
    return 0;
}   


