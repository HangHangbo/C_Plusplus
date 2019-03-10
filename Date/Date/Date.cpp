#include<iostream>
using namespace std;


class Date
{
public:
	int getMonthday(int year, int month)
	{
		int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	/*	int day = days[13];*/
		if (month == 2){
			//闰年
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
				return days[month]+1;
			}
			else{
				return days[month];
			}
		}
		return days[month];

	}
	Date(int year = 1900, int month = 1, int day = 1){     //初始化对象
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d){       //拷贝构造
		_year = d._year;
		_month =d._month;
		_day = d._day;
	}
	Date operator+=(int days){
		if (days<0){
			return *this -= -days;
		}
			_day += days;
			while (_day > getMonthday(_year, _month)){
				++_month;
				if (_month == 13){
					++_year;
					_month = 1;
				}
			}
			return *this;
	
	}
	Date operator-=(int days){
		if (days < 0){
			return *this += -days;
		}
		_day -= days;
		while (_day < 0){
			--_month;
			if (_month == 0){
				--_year;
				_month = 12;
			}
			_day += getMonthday(_year, _month);
		}
		return *this;
	}
	Date& operator=(const Date& d){
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	Date operator+(int days){
		return *this += days;
	}
	Date operator-(int days){
		return *this -= days;
	}
	int operator-(const Date& d){
		int days = 0;
		int flag = 1;
		Date ret = *this;
		if (*this > d){
			while (ret > d){
				ret--;
				days++;
			}
		}
		else{
			flag = -1;
			while (ret < d){
				ret++;
				days++;
			}
		}
		return flag*days;
	}
Date& operator++()
{
	//_day++;
	//if (_day> getMonthday(_year, _month)){
	//	++_month;
	//	if (_month == 13){
	//		++_year;
	//		_month = 1;
	//	}
	//}
	return *this+=1;
}
Date operator++(int){
	Date ret = *this;
	*this += 1;
	return ret;
}
Date& operator--(){
	return *this -= 1;
}
Date operator--(int){
	Date ret = *this;
	*this -= 1;
	return ret;
}
bool operator>(const Date& d)const{
	if ((_year > d._year) || (_year == d._year&&_month > d._month) || (_year == d._year&&_month == d._month&&_day > d._day))
	{
		return true;
	}
	else {
		return false;
	}
}
bool operator>=(const Date& d)const
{
	return(*this > d&&*this == d);
}
bool operator<(const Date& d)const{
	return !(*this >= d);
}
bool operator<=(const Date& d)const{
	return!(*this>d);
}
bool operator==(const Date& d)const{
	if ((_year == d._year) && (_month == d._month) && (_day == d._day))
		return true;
	else
		return false;
}
bool operator!=(const Date& d)const{
	return!(*this == d);
}
	void Display()
{
		cout << _year << "-" << _month << "-" << _day <<endl;
}

void SetDate(int year, int month, int day)
	{
		if ((year < 1900) || (month < 1) || (month > 12) || (day < 1) || (day > getMonthday(year, month)))
		{
			cout << "非法日期，输入错误" << endl;
		}
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(1997, 8, 8);
	Date d2(1997, 9, 8);
	
	d1.Display();
    d2.Display();
	
	system("pause");
	return 0;
}