#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	int t=0;
	while(b!=0){
		int temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}
class Rational{
	private:
		int nu;
		int den;
	public:
		Rational(){
			nu=1;
			den=1;
		}
		Rational(int a,int b){
			if(a*b<0){
				a=-abs(a);
				b=abs(b);
				nu=a/abs(gcd(a,b));
			    den=b/abs(gcd(a,b));
			}
			else if(a==0){
				nu=0;
				den=1;
			}else{
			nu=a/abs(gcd(a,b));
			den=b/abs(gcd(a,b));
			}
			
		}
		Rational operator+(const Rational &r){
			return Rational(nu*r.den+den*r.nu,den*r.den);
		}
		Rational operator-(const Rational &r){
			return Rational(nu*r.den-den*r.nu,den*r.den);
		}
		Rational operator*(const Rational &r){
			return Rational(nu*r.nu,den*r.den);
		}
		Rational operator/(const Rational &r){
			return Rational(nu*r.den,den*r.nu);
		}
		bool operator<(const Rational &r){
			return (nu*r.den<den*r.nu);
		}
		bool operator>(const Rational &r){
			return (nu*r.den>den*r.nu);
		}
		bool operator==(const Rational &r){
			return (nu*r.den==den*r.nu);
		}
		bool operator<=(const Rational &r){
			return (nu*r.den<=den*r.nu);
		}
		bool operator>=(const Rational &r){
			return (nu*r.den>=den*r.nu);
		}
		friend ostream& operator<<(ostream& os,const Rational &r){
			if(r.den==1){
				os<<r.nu;
			}else{
				os<<r.nu<<"/"<<r.den;
			}
			return os;
		}
		friend istream& operator>>(istream& is,Rational &r){
			int a,b;
			is>>a>>b;
			r=Rational(a,b);
			return is;
		}
};
int main() {
    Rational r1, r2;
    cin >> r1 >> r2;
    if (r1 > r2) {
        cout << r1 - r2;
    } else {
        cout << r1 * r2;
    }
    return 0;
}



