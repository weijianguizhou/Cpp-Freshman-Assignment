#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int getRev(string a) {
    int count = 0;
    for (int i = 0; i < a.length(); i++) {
        for (int j = i + 1; j < a.length(); j++) {
            if (a[i] > a[j])
                count++;
        }
    }
    return count;
}
void sort(string a[], int b[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                swap(b[j], b[j + 1]);
                swap(a[j], a[j + 1]);
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    string a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = getRev(a[i]);
    }
    sort(a, b, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << b[i] << endl;
    }
    return 0;
}
