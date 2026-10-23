#include<bits/stdc++.h>
using namespace std;
class MyString{
	private:
		char*str;
		int size;
	public:
		MyString(){
			size=10;
			str=new char[size];
		}
		MyString(const char*s){
			size=strlen(s);
			str=new char[size+1];
			strcpy(str,s);
		}
		MyString(const MyString &s){
			size=s.size;
			str=new char[size+1];
			strcpy(str,s.str);
		}
		~MyString(){
			delete[] str;
			size=0;
		}
    MyString operator+(const MyString &s) {
        char *p;
        int t = size;
        int newSize = size + s.size;
        p = new char[newSize + 1];
        strcpy(p, str);
        strcat(p, s.str);
        MyString result(p);
        delete[] p;
        return result;
    }
    bool operator==(const MyString &s) {
        if (size != s.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (str[i] != s.str[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const MyString &s) {
        return !(*this == s);
    }
		friend ostream& operator<<(ostream&os,MyString &s){
			os<<s.str<<endl;
		}
};
int main() {
    MyString s1("hello");
    MyString s2(" world");
    MyString s3 = s1 + s2;
    cout << s3;
    if (s1 != s2) {
        cout << "Strings are not equal";
    }
    return 0;
}



