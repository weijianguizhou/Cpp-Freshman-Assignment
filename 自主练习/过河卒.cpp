# include<iostream>
using namespace std;
class position{
	public:
		int x,y;
		position(int a,int b){
			x=a;
			y=b;
		}
};
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	position possolider(a,b),poshorse(c,d);
	cout<<possolider.x<<possolider.y<<poshorse.x<<poshorse.y;
}
