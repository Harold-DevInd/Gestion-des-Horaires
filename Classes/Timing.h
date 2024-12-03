#ifndef TIMING_H

#define TIMING_H
#include <string>
#include "Time.h"

namespace planning{

class Timing
{
friend std::ofstream& operator<<(std::ofstream&, const Timing&);
friend std::ifstream& operator>>(std::ifstream&, Timing&);

private:
	std::string day;
	Time start;
	Time duration;

	int getDayOrder(const std::string&) const noexcept;
	int compTiming(const Timing&) const;

public:
	static const std::string MONDAY;
	static const std::string TUESDAY;
	static const std::string WEDNESDAY; 
	static const std::string THURSDAY;
	static const std::string FRIDAY;
	static const std::string SATURDAY;
	static const std::string SUNDAY;

	Timing() noexcept;
	Timing(std::string,const Time&, const Time&);
	Timing(const Timing&);
	~Timing() noexcept;

	std::string getDay() const noexcept;
	Time getStart() const noexcept;
	Time getDuration() const noexcept;
	void setDay(std::string);
	void setStart(const Time&);
	void setDuration(const Time&);

	void display() const noexcept;

	int operator<(const Timing&) const noexcept;
	int operator>(const Timing&) const noexcept;
	int operator==(const Timing&) const noexcept;
	int operator!=(const Timing&) const noexcept;
};

}//namespace

#endif