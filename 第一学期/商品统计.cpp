#include<bits/stdc++.h>
using namespace std;
struct Goods {
    string name;
    string kind;
    int num;
};
int main() {
    int n;
    cin>>n;
    Goods s[100];
    for (int i=0;i<n;i++) {
        cin>>s[i].name>>s[i].kind>>s[i].num;
    }
    bool kindPrinted[100]={false};
    for (int i=0;i<n;i++){
        int sum=0;
        for (int j=0;j<n;j++) {
            if (s[i].kind==s[j].kind&&s[i].name==s[j].name) {
                sum+=s[j].num;
            }
        }
        int kindIndex=-1;
        for (int k=0;k<i;k++) {
            if (s[i].kind==s[k].kind) {
                kindIndex=k;
                break;
            }
        }
        if (kindIndex==-1) {
            cout<<s[i].kind<<endl;
            kindPrinted[i]=true;
        }
        bool isNamePrinted=false;
        for (int m=0;m<i;m++) {
            if (s[m].kind==s[i].kind && s[m].name==s[i].name) {
                isNamePrinted = true;
                break;
            }
        }
        if (!isNamePrinted) {
            cout << "    " << s[i].name << " " << sum << endl;
        }
    }
    return 0;
}
