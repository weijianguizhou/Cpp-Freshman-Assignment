#include <iostream>
using namespace std;
int main(){
	float score=0;
	cout<<"Please Enter Acore:";
	cin>>score;
	if (score>100||score<0){
		cout<<score<<"is invalid.0-100 is valid!"<<endl;
		return 0;
	}
	switch (int (score/10)){
		case 10:
	    case 9: cout<<'A';
	            break;
	    case 8: cout<<'B';
	            break;
	    case 7: cout<<'C';
	            break;
	    case 6: cout<<'D';
	            break;
	    default:cout<<'E'; 
	}
	return 0;
}
