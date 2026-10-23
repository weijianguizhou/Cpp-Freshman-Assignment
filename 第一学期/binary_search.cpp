#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int a[10];
	generate(a,a+10,rand);
	for(auto x:a)
		cout<<x<<" ";
	cout<<endl;
	sort(a,a+10);
	for(auto x:a)
	    cout<<x<<" ";
	cout<<endl;
	if(binary_search(a,a+10,15724))
	   cout<<"15724 found"<<endl;
	else{
		cout<<"15724 not found"<<endl;
	}
	auto it=find(a,a+10,15724);
	if(it==a+10)
	   cout<<"15724 not found"<<endl;
	else
	   cout<<*it<<"found by dound"<<endl;
	return 0;
	     
}
