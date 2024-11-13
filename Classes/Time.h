#ifndef Time_H

#define Time_H
#include <iostream>

namespace planning{

class Time
{
friend Time operator+(int, const Time&);
friend Time operator+(const Time&, const Time&);
friend Time operator-(int, const Time&);
friend Time operator-(const Time&, const Time&);
friend std::ostream& operator<<(std::ostream&, const Time&);
friend std::istream& operator>>(std::istream&, Time&);

private: 
	int hour;
	int minute;
	int compTime(const Time&) const;

public:
	Time();
	Time(int, int);
	Time(int);
	Time(const Time&);
	~Time();

	int getHour() const;
	int getMinute() const;
	void setHour(int);
	void setMinute(int);
	void display() const;

	Time& operator=(const Time&);
	Time& operator=(int);
	Time operator+(int) const;
	Time operator-(int) const;
	int operator<(const Time&) const;
	int operator>(const Time&) const;
	int operator==(const Time&) const;
	Time operator++();
	Time operator++(int);
	Time operator--();
	Time operator--(int);
};

}//namespace

#endif