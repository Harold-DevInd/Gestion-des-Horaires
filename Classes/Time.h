#ifndef TIME_H

#define TIME_H

namespace planning{

class Time
{
private: 
	int hour;
	int minute;

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
};

}//namespace

#endif