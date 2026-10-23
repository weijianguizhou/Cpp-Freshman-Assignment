#include<bits/stdc++.h>
using namespace std;
int getRev(int a){
    int ans = 0;
    while (a > 0) {
        ans = ans * 10 + (a % 10);
        a /= 10;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int c, d, i = 0;
    for (;; i++) {
        c = getRev(n);
        d = n + c;
        if (getRev(d) == d) break;
        else {
		    cout << n << "+" << c << "=" << d << endl;
            n = d;
            continue;
        }
    }
    cout << "ÐèÒª" << i << "²½" << endl;
    return 0;
}


