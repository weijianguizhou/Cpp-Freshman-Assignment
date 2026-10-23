#include <bits/stdc++.h>
using namespace std;
int n1,m1,n2,m2;
double a[4000][4000],b[4000][4000],ans[4000][4000];
int main()
{
	scanf("%d%d%d%d",&n1,&m1,&n2,&m2);
	for (int i=1;i<=n1;i++)
	{
		for (int j=1;j<=m1;j++)
		{
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=n2;i++)
	{
		for (int j=1;j<=m2;j++)
		{
			cin>>b[i][j];
		}
	}
	for (int i=1;i<=n1;i++)
	{
		for (int j=1;j<=m1;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	for (int i=1;i<=n2;i++)
	{
		for (int j=1;j<=m2;j++)
		{
			cout<<b[i][j]<<' ';
		}
		cout<<endl;
	}
	for (int i=1;i<=n1;i++)
	{
		for (int j=1;j<=m2;j++)
		{
			for (int k=1;k<=m1;k++)
			{
				ans[i][j]=ans[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	for (int i=1;i<=n1;i++)
	{
		for (int j=1;j<=m2;j++)
		{
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
