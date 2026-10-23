#include <iostream>
using namespace std;
 
int main() {
	int a, b, suma, sumb, i, j, m;
	cin>>m;
	for (i = 1; i <= m; i++) {
		cin>>a>>b;
		suma = 0;
		for (j = 1; j < a; j++) {
			if (a % j == 0) {
				suma += j;
			}
		}
		sumb = 0;
		for (j = 1; j < b; j++) {
			if (b % j == 0) {
				sumb += j;
			}
		}
		if (a == sumb && b == suma) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
