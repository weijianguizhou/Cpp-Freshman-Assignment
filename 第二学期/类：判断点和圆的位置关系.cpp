#include<bits/stdc++.h>
using namespace std;
class Point{
	private:
		int m_X;
		int m_Y;
	public:
		void setX(double x){
			m_X=x;
		}
		double getX(){
			return m_X;
		}
		void setY(double y){
			m_Y=y;
		}
		double getY(){
			return m_Y;
		}
};
class Circle{
	private:
		double m_R;
		Point m_Circle;
	public:
		void setX(double x){
			m_Circle.setX(x);
		}
		double getX(){
			return m_Circle.getX();
		}
		void setY(double y){
			m_Circle.setY(y);
		}
		double getY(){
			return m_Circle.getY();
		}
		void setR(double r){
			m_R=r;
		}
		double getR(){
			return m_R;
		}
};
void IsinCircle(Circle a,Point b){
	double i=(a.getX()-b.getX())*(a.getX()-b.getX())+(a.getY()-b.getY())*(a.getY()-b.getY());
	double j=a.getR()*a.getR();
	if(i>j){
		cout<<"点在圆外"<<endl;
	}else if(i==j){
		cout<<"点在圆上"<<endl;
	}else{
		cout<<"点在圆内"<<endl;
	}
}
int main(){
	double x1,x2,y1,y2,r;
	Circle m_A;
	Point m_B;
	cin>>r>>x1>>y1>>x2>>y2;
	m_A.setR(r);
	m_A.setX(x1);
	m_A.setY(y1);
	m_B.setX(x2);
	m_B.setY(y2);
	IsinCircle(m_A,m_B);
	return 0;
}


