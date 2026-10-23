#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b){
	while(b!=0){
		int t=a%b;
		b=a;
		a=t;
	}
	return a;
}
class Fraction{
	private:
		int numerator;
		int denominator;
	public:
		Fraction(){
			numerator=0;
			denominator=1;
		}
		Fraction(int a,int b){
			int t=abs(gcd(abs(a),abs(b)));
			if(a*b<0){
				numerator=-(abs(a/t));
				denominator=abs(b/t);
			}
			if(a*b>0){
				numerator=abs(a/t);
				denominator=abs(b/t);
			}
			if(a==0){
				numerator=0;
				denominator=1;
			}
		}
		int getNu()const{
			return numerator;
		}
		int getDe()const{
			return denominator;
		}
};
class MixedFraction:public Fraction{
	private:
		int wholePart;
	public:
		MixedFraction(const Fraction &f){
			Fraction(f.getNu()%f.getDe(),f.getDe());
			wholePart=f.getNu()/f.getDe();
		}
		MixedFraction(int a=0,int b=0,int c=1){
			Fraction(b%c,c);
			wholePart=(a+b*c)/c;
			}
		friend ostream &operator<<(ostream& os,const MixedFraction &f){
			if(f.getWh()==0){
				os<<f.getNu()<<"/"<<f.getDe()<<endl;
			}
			else{
				os<<f.getWh()<<" "<<f.getNu()<<"/"<<f.getDe();
			}
			return os;
		}
		int getWh()const{
			return wholePart;
		}
		MixedFraction operator+(MixedFraction &f){
			return (MixedFraction((wholePart*getDe()+getNu())*f.getDe()+(f.getWh()*f.getDe()+f.getNu())*getDe(),getDe()*f.getDe()));
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

