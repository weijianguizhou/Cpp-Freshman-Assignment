#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        bool found = false;
        for (int j = 0; j < result.length(); j++) {
            if (s[i] == result[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result += s[i];
        }
    }
    cout << result << endl;
    return 0;
}
