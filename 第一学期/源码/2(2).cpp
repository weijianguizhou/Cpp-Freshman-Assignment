#include<bits/stdc++.h>
using namespace std;
int n;
string change(int x)
{
	string s="";
	int t;
	while(x>0)
	{
		t=x%n;
		x=x/n;
		if(t>9) s=(char)(t-10+'A')+s;
		else s=(char)(t+'0')+s;
	}
	return s;
}
bool ishw(string str)
{
	for(int i=0;i<str.size()/2;i++)
	{
		int j=str.size()-i-1;
		if(str[j]!=str[i]) 
		{
		    return false;
		    break;
		}
	}
	return true;
}
int main()
{
	cin>>n;
	for(int i=1;i<=200;i++)
	{
	    string op1=change(i);
		string op=change(i*i);
		if(ishw(op)==true)
		{
			cout<<op1<<' '<<op;
			cout<<endl;
		}
		else continue;
	}
	return 0;
}
