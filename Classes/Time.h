#ifndef Time_H

#define Time_H
#include <iostream>
#include <fstream>
#include <sstream>

namespace planning{

class Time
{
friend Time operator+(int, const Time&);
friend Time operator+(const Time&, const Time&);
friend Time operator-(int, const Time&);
friend Time operator-(const Time&, const Time&);
friend std::ofstream& operator<<(std::ofstream&, const Time&);
friend std::ifstream& operator>>(std::ifstream&, Time&);

private: 
	int hour;
	int minute;
	int compTime(const Time&) const noexcept;

public:
	Time() noexcept;
	Time(int, int);	
	Time(int);
	Time(const Time&) noexcept;
	~Time() noexcept;

	int getHour() const noexcept;
	int getMinute() const noexcept;
	void setHour(int);
	void setMinute(int);
	void display() const noexcept;

	Time& operator=(const Time&);
	Time& operator=(int);
	Time operator+(int) const;
	Time operator-(int) const;
	int operator<(const Time&) const noexcept;
	int operator>(const Time&) const noexcept;
	int operator==(const Time&) const noexcept;
	Time operator++();
	Time operator++(int);
	Time operator--();
	Time operator--(int);
};

}//namespace

#endif