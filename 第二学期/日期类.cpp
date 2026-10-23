#include<bits/stdc++.h>
using namespace std;
bool Leap(int a){
	if(a%4==0&&a%100!=0||a%400==0){
		return true;
	}
	else{
		return false;
	}
}
int daysInMonth(int y,int m){
	int u[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(m==2&&Leap(y)==1){
		return 29;
	}
	else{
		return u[m];
	}
}
class Date{
	private:
		int year;
		int month;
		int day;
	public:
		Date(int a,int b,int c){
			if(Leap(a)==1){
				if(c>daysInMonth(a,b)){
					cout<<"Error"<<endl;
				}
				else{
					year=a;
					month=b;
					day=c;
				}
			}
			else{
				if(c>daysInMonth(a,b)){
					cout<<"Error"<<endl;
				}
				else{
					year=a;
					month=b;
					day=c;
				}
			}
		}
    Date operator+(int days) const {
        int totalDays = days;
        int currentYear = year;
        int currentMonth = month;
        int currentDay = day;
        currentDay += totalDays;
        while (currentDay > daysInMonth(currentYear, currentMonth)) {
            currentDay -= daysInMonth(currentYear, currentMonth);
            currentMonth++;
            if (currentMonth > 12) {
                currentMonth = 1;
                currentYear++;
            }
        }
        return Date(currentYear, currentMonth, currentDay);
    }
        Date operator-(int days) const {
        int totalDays = days;
        int currentYear = year;
        int currentMonth = month;
        int currentDay = day;
        currentDay -= totalDays;
        while (currentDay<=0) {
            currentMonth--;
            if (currentMonth<=0) {
                currentMonth = 12;
                currentYear--;
            }
        }
        return Date(currentYear, currentMonth, currentDay);
    }
	friend ostream& operator<<(ostream& os,Date& d){
		os<<d.year<<"/"<<d.month<<"/"<<d.day<<endl;
		return os;
	}
	bool operator==(Date& d){
		if(d.year==year&&d.month==month&d.day==day){
			return true;
		}
		else{
			return false;
		}
	}
	bool operator>(Date& d){
		if(year>d.year){
			return true;
		}else if(year==d.year&&month>d.month){
			return true;
		}else if(year==d.year&&month==d.month&&day>d.day){
			return true;
		}
		else{
			return false;
		}
	}
	bool operator<(Date& d){
		if(year<d.year){
			return true;
		}else if(year==d.year&&month<d.month){
			return true;
		}else if(year==d.year&&month==d.month&&day<d.day){
			return true;
		}
		else{
			return false;
		}
	}
};
int main() {
    Date d1(2023, 10, 1);
    Date d2(2023, 10, 10);
    if (d1 < d2) {
        Date d3 = d2 - 5;
        cout << d3;
    }
    return 0;
}



