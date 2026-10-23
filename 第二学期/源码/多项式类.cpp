#include<bits/stdc++.h>
using namespace std;
class Polynomial{
	private:
		int degree;
		double *a;
	public:
		Polynomial(int d,double *p){
			degree=d;
			a=new double[degree+1];
			for(int i=0;i<degree+1;i++){
				a[i]=p[i];
			} 
		}
    Polynomial operator+(const Polynomial& p){
        int newDegree=max(degree, p.degree);
        double *k=new double[newDegree+1]();
        for(int i=0;i<=degree;i++){
            k[i]+=a[i];
        }
        for(int i=0;i<=p.degree;i++){
            k[i]+=p.a[i];
        }
        Polynomial result(newDegree,k);
        delete[] k;
        return result;
    }
    Polynomial operator-(const Polynomial& p) {
        int newDegree=max(degree, p.degree);
        double *k =new double[newDegree+1]();
        for(int i=0;i<=degree;i++){
            k[i]+=a[i];
        }
        for(int i=0;i<=p.degree;i++){
            k[i]-=p.a[i];
        }
        while(newDegree>0&&k[newDegree]==0){
            newDegree--;
        }
        Polynomial result(newDegree, k);
        delete[] k;
        return result;
    }
    Polynomial operator*(const Polynomial& p){
        int newDegree=degree+p.degree;
        double *k =new double[newDegree+1]();
        for (int i = 0;i<=degree;i++) {
            for (int j=0;j<=p.degree;j++){
                k[i+j]+=a[i]*p.a[j];
            }
        }
        Polynomial result(newDegree, k);
        delete[] k;
        return result;
    }
    friend ostream& operator<<(ostream& os,const Polynomial& p){
        bool first=true;
        for(int i=p.degree;i>=0;i--) {
            if (p.a[i]!=0){
                if(!first){
                    if(p.a[i]>0){
                        os <<" + ";
                    }else{
                    os << " - ";
                    }
                }
                if(i == 0){
                    os<<abs(p.a[i]);
                } else if(i == 1){
                    if(abs(p.a[i]) == 1){
                        os << "x";
                    }else{
                        os <<abs(p.a[i])<< "x";
                    }
                }else{
                    if(abs(p.a[i]) == 1){
                        os<<"x^"<<i;
                    } else {
                        os<<abs(p.a[i])<<"x^"<<i;
                    }
                }
                first=false;
            }
        }
        if (first){
            os<<"0";
        }
        return os;
    }
};
int main() {
    double coeffs1[] = {1, 2, 3};
    double coeffs2[] = {4, 5, 6};
    Polynomial p1(2, coeffs1);
    Polynomial p2(2, coeffs2);
    Polynomial p3 = p1 + p2;
    cout << p3;
    return 0;
}



