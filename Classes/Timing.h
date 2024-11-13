#ifndef TIMING_H

#define TIMING_H
#include <string>
#include "Time.h"

namespace planning{

class Timing
{
private:
	std::string day;
	Time start;
	Time duration;

	int getDayOrder(const std::string&) const;
	int compTiming(const Timing&) const;

public:
	static const std::string MONDAY;
	static const std::string TUESDAY;
	static const std::string WEDNESDAY; 
	static const std::string THURSDAY;
	static const std::string FRIDAY;
	static const std::string SATURDAY;
	static const std::string SUNDAY;

	Timing();
	Timing(std::string,const Time&, const Time&);
	Timing(const Timing&);
	~Timing();

	std::string getDay() const;
	Time getStart() const;
	Time getDuration() const;
	void setDay(std::string);
	void setStart(const Time&);
	void setDuration(const Time&);

	void display() const;

	int operator<(const Timing&) const;
	int operator>(const Timing&) const;
	int operator==(const Timing&) const;
	int operator!=(const Timing&) const;
};

}//namespace

#endif