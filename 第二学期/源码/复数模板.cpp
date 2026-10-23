#include<iostream>
#include<cmath> 
using namespace std;
template <typename T>
class Complex{
	private:
		T real;
		T imag;
	public:
		Complex(T r=0,T i=0):real(r),imag(i){}
		double modulus() const {
        double realDouble = static_cast<double>(real);
        double imagDouble = static_cast<double>(imag);
        return sqrt(realDouble * realDouble + imagDouble * imagDouble);;
    }
		Complex<T> operator+(const Complex<T> &c)const{
			return Complex<T>(real+c.real,imag+c.imag);
		}
		Complex<T> operator-(const Complex<T> &c)const{
			return Complex<T>(real-c.real,imag-c.imag);
		}
		Complex<T> operator*(const Complex<T> &c)const{
			return Complex(real*c.real-imag*c.imag,real*c.imag+imag*c.real);
		}
		Complex<T> operator/(const Complex<T> &c)const{
			return Complex((real*c.real+imag*c.imag)/(c.real*c.real+c.imag*c.imag),(imag*c.real-real*c.imag)/(c.real*c.real+c.imag*c.imag));
		}
        bool operator<(const Complex<T> &c)const{
			return ((real*real+imag*imag)<(c.real*c.real+c.imag*c.imag));
		}
		bool operator>(const Complex<T> &c)const{
			return ((real*real+imag*imag)>(c.real*c.real+c.imag*c.imag));
		}
		bool operator==(const Complex<T> &c)const{
			return ((real*real+imag*imag)==(c.real*c.real+c.imag*c.imag));
		}
		friend ostream &operator<<(ostream &os,const Complex<T> &c){
			if(c.imag>T()){
				os<<c.real<<"+"<<c.imag<<"i";
				return os;
			}
			else if(c.imag<T()){
				os<<c.real<<"-"<<-(c.imag)<<"i";
				return os;
			}
			else{
				os<<c.real;
				return os;
			}
		}
		friend istream &operator>>(istream &is,Complex<T> &c){
			is>>c.real>>c.imag;
			return is;
		}
};
class Fraction {
private:
    int numerator;
    int denominator;
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
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
    Fraction operator+(const Fraction& f) const {
        return Fraction(numerator * f.denominator + f.numerator * denominator,
                        denominator * f.denominator);
    }
    Fraction operator-(const Fraction& f) const {
        return Fraction(numerator * f.denominator - f.numerator * denominator,
                        denominator * f.denominator);
    }
    Fraction operator*(const Fraction& f) const {
        return Fraction(numerator * f.numerator, denominator * f.denominator);
    }
    Fraction operator/(const Fraction& f) const {
        return Fraction(numerator * f.denominator, denominator * f.numerator);
    }
    bool operator<(const Fraction& f) const {
        return numerator * f.denominator < denominator * f.numerator;
    }
    bool operator==(const Fraction& f) const {
        return numerator * f.denominator == denominator * f.numerator;
    }
    bool operator>(const Fraction& f) const {
        return numerator * f.denominator > denominator * f.numerator;
    }
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.denominator == 1) {
            os << f.numerator;
        } else {
            os << f.numerator << "/" << f.denominator;
        }
        return os;
    }
    friend istream& operator>>(istream& is, Fraction& f) {
        int num, den;
        is >> num >> den;
        f = Fraction(num, den);
        return is;
    }
    operator double() const {
        return static_cast<double>(numerator) / denominator;
    }
    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }
};
int main() {
    Complex<Fraction> c1,c2;
    cin>>c1>>c2;
    cout<<c1<<'\n'<<c2<<endl;
    cout<<c1.modulus()<<'\n'<<c2.modulus()<<endl; 
    if(c1>c2) cout<<c1+c2<<endl;
    else cout<<c1*c2<<endl;
    return 0;
}


