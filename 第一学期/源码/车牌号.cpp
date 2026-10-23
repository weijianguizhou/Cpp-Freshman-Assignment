#include<bits/stdc++.h>
using namespace std;
int main(){
	char strTem[30];
	char strArr[110][30];
	int rec[110],i,j,n;
	cin>>n;
	int num=0;
	for(i=1;i<=n;i++){
		cin>>strTem;
		int f=0;
		for(j=1;j<=num;j++){
			if(strcmp(strTem,strArr[j])==0){
				rec[j]++;
				f=32;
				break;
			}
		}
		if(f==0){
			num++;
			strcpy(strArr[num],strTem);
			rec[num]=1;
		}
	}//完成输入过程 
	
	for(i=1;i<=num-1;i++)
	    for(j=i+1;j<=num;j++){
	    	if(rec[i]<rec[j]){
	    		int temp=rec[i];
	    		rec[i]=rec[j];
	    		rec[j]=temp;
	    		strcpy(strTem,strArr[i]);
	    		strcpy(strArr[i],strArr[j]);
	    		strcpy(strArr[j],strTem);
			}//完成排序 
		}
		for(i=1;i<=num;i++){
			cout<<strArr[i]<<":"<<rec[i]<<endl;
		}
	return 0;
}


