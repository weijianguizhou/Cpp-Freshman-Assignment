#include<iostream>
using namespace std;
int main(){
	int s,v,walktime,t;
	cin>>s>>v;
	if(s%v==0){
	walktime=s/v;
	}else walktime=s/v+1;
	t=walktime+10;
	if(t<60){
		cout<<"07"<<":"<<60-t<<endl;
	}else if(t==60){
		cout<<"07"<<":"<<"00"<<endl;
	}else if(t==120){
		cout<<"06"<<":"<<"00"<<endl;
	}else if(t==180){
		cout<<"05"<<":"<<"00"<<endl;
	}else if(t==240){
		cout<<"04"<<":"<<"00"<<endl;
	}else if(t==300){
		cout<<"03"<<":"<<"00"<<endl;
	}else if(t==360){
		cout<<"02"<<":"<<"00"<<endl;
	}else if(t==420){
		cout<<"01"<<":"<<"00"<<endl;
	}else if(t==480){
		cout<<"00"<<":"<<"00"<<endl;
	}else if(t==540){
		cout<<"23"<<":"<<"00"<<endl;
	}else if(t==600){
		cout<<"22"<<":"<<"00"<<endl;
	}else if(t==660){
		cout<<"21"<<":"<<"00"<<endl;
	}else if(t==720){
		cout<<"20"<<":"<<"00"<<endl;
	}else if(t==780){
		cout<<"19"<<":"<<"00"<<endl;
	}else if(t==840){
		cout<<"18"<<":"<<"00"<<endl;
	}else if(t==900){
		cout<<"17"<<":"<<"00"<<endl;
	}else if(t==960){
		cout<<"16"<<":"<<"00"<<endl;
	}else if(t==1020){
		cout<<"15"<<":"<<"00"<<endl;
	}else if(t==1080){
		cout<<"14"<<":"<<"00"<<endl;
	}else if(t==1140){
		cout<<"13"<<":"<<"00"<<endl;
	}else if(t==1200){
		cout<<"12"<<":"<<"00"<<endl;
	}else if(t==1260){
		cout<<"11"<<":"<<"00"<<endl;
	}else if(t==1320){
		cout<<"10"<<":"<<"00"<<endl;
	}else if(t==1380){
		cout<<"09"<<":"<<"00"<<endl;
	}else if(t==1440){
		cout<<"08"<<":"<<"00"<<endl;
	}else if(t==60){
		cout<<"07"<<":"<<"00"<<endl;
	}else if(t==60){
		cout<<"07"<<":"<<"00"<<endl;
	}else if(t==60){
		cout<<"07"<<":"<<"00"<<endl;
	}else if(t==60){
		cout<<"07"<<":"<<"00"<<endl;
	}else if(t<120){
		cout<<"06"<<":"<<120-t<<endl;
	}else if(t<180){
		cout<<"05"<<":"<<180-t<<endl;
	}else if(t<240){
		cout<<"04"<<":"<<240-t<<endl;
	}else if(t<300){
		cout<<"03"<<":"<<300-t<<endl;
	}else if(t<360){
		cout<<"02"<<":"<<360-t<<endl;
	}else if(t<420){
		cout<<"01"<<":"<<420-t<<endl;
	}else if(t<480){
		cout<<"00"<<":"<<480-t<<endl;
	}else if(t<540){
		cout<<"23"<<":"<<540-t<<endl;
	}else if(t<600){
		cout<<"22"<<":"<<600-t<<endl;
	}else if(t<660){
		cout<<"21"<<":"<<660-t<<endl;
	}else if(t<720){
		cout<<"20"<<":"<<720-t<<endl;
	}else if(t<780){
		cout<<"19"<<":"<<780-t<<endl;
	}else if(t<840){
		cout<<"18"<<":"<<840-t<<endl;
	}else if(t<900){
		cout<<"17"<<":"<<900-t<<endl;
	}else if(t<960){
		cout<<"16"<<":"<<960-t<<endl;
	}else if(t<1020){
		cout<<"15"<<":"<<1020-t<<endl;
	}else if(t<1080){
		cout<<"14"<<":"<<1080-t<<endl;
	}else if(t<1140){
		cout<<"13"<<":"<<1140-t<<endl;
	}else if(t<1200){
		cout<<"12"<<":"<<1200-t<<endl;
	}else if(t<1260){
		cout<<"11"<<":"<<1260-t<<endl;
	}else if(t<1320){
		cout<<"10"<<":"<<1320-t<<endl;
	}else if(t<1380){
		cout<<"09"<<":"<<1380-t<<endl;
	}else if(t<1440){
		cout<<"08"<<":"<<1440-t<<endl;
    }
	return 0;
}
