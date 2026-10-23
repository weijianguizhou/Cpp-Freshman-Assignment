#include<iostream>
#include<cmath>
using namespace std;
class Complex{
	double x,y;
	double mode;
	public:
		Complex(double a=0,double b=0){
			x=a;
			y=b;
		}
		double modulus(){
			return sqrt(x*x+y*y);
		}
		Complex operator+(const Complex &c){
			return Complex(x+c.x,y+c.y);
		}
		Complex operator-(const Complex &c){
			return Complex(x-c.x,y-c.y);
		}
		Complex operator*(const Complex &c){
			return Complex(x*c.x-y*c.y,x*c.y+y*c.x);
		}
		Complex operator/(const Complex &c){
			return Complex((x*c.x+y*c.y)/(c.x*c.x+c.y*c.y),(y*c.x-x*c.y)/(c.x*c.x+c.y*c.y));
		}
		bool operator<(const Complex &c){
			return ((x*x+y*y)<(c.x*c.x+c.y*c.y));
		}
		bool operator>(const Complex &c){
			return ((x*x+y*y)>(c.x*c.x+c.y*c.y));
		}
		bool operator==(const Complex &c){
			return ((x*x+y*y)==(c.x*c.x+c.y*c.y));
		}
		friend ostream &operator<<(ostream &os,const Complex &c){
			if(c.y>0){
				os<<c.x<<" "<<"+"<<" "<<c.y<<"i";
				return os;
			}
			if(c.y<0){
				os<<c.x<<" "<<"-"<<" "<<abs(c.y)<<"i";
				return os;
			}
			if(c.y==0){
				os<<c.x;
				return os;
			}
		}
		friend istream &operator>>(istream &is,Complex &c){
			is>>c.x>>c.y;
			return is;
		}
};
int main() {
    Complex c1,c2;
    cin>>c1>>c2;
    cout<<c1<<'\n'<<c2<<endl; 
    cout<<c1.modulus()<<'\n'<<c2.modulus()<<endl; //Ä£µÄÊä³ö 
    if(c1>c2) cout<<c1+c2<<endl;
    else cout<<c1-c2<<endl;
    return 0;
}


