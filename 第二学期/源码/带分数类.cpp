#include <iostream>
#include<cmath>
using namespace std;
 int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
class Fraction {
private:
    int numerator;
    int denominator;
   
public:
    Fraction(int x = 0, int y = 1) : numerator(x), denominator(y) {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        if (numerator == 0) {
            denominator = 1;
        } else {
            int d = gcd(abs(numerator), abs(denominator));
            numerator /= d;
            denominator /= d;
        }
    }
    void show() {
        cout << numerator << "/" << denominator << endl;
    }
    int Getnumerator() const {
        return numerator;
    }
    int Getdenominator() const {
        return denominator;
    }
};

class MixedFraction : public Fraction {
private:
    int wholePart;
public:
    MixedFraction(const Fraction &f) : Fraction(f.Getnumerator() % f.Getdenominator(), f.Getdenominator()) {
        wholePart = f.Getnumerator() / f.Getdenominator();
    }
    MixedFraction(int a, int b, int c) : Fraction(b%c,c) {
        wholePart = (b + a * c) / c;
    }

    friend ostream& operator<<(ostream &os, const MixedFraction &mf) {
    	if(mf.wholePart==0){
    		os<<mf.Getnumerator()<<"/"<<mf.Getdenominator();
    		return os;
		}
		else{
		os << mf.wholePart << " " << mf.Getnumerator() << "/" << mf.Getdenominator();
		return os;
		}
        
        
    }

    MixedFraction operator+(const MixedFraction &mf) {
        int newNumerator = (wholePart * Getdenominator() + Getnumerator()) * mf.Getdenominator() + (mf.wholePart * mf.Getdenominator() + mf.Getnumerator()) * Getdenominator();
        int newDenominator = Getdenominator() * mf.Getdenominator();
        Fraction resultFraction(newNumerator, newDenominator);
        return MixedFraction(resultFraction);
    }
};
int main() {
    int wholePart,numerator,denominator;
    cin>>numerator>>denominator;
    Fraction f(numerator,denominator);
    MixedFraction mf1(f);
    cin>>wholePart>>numerator>>denominator;
    MixedFraction mf2(wholePart,numerator,denominator);
    cout<<mf1<<endl;
    cout<<mf2<<endl;
    cout<<mf1+mf2;
    return 0;
}
