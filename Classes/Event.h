#ifndef EVENT_H

#define EVENT_H
#include "Timing.h"
#include <string>

namespace planning{

class Event 
{
friend std::ofstream& operator<<(std::ofstream&, const Event&);
friend std::ifstream& operator>>(std::ifstream&, Event&);

private:
	int code;
	std::string title;
	Timing* timing;

public:
	Event() noexcept;
	~Event() noexcept;
	Event(int, std::string);
	Event(const Event&);

	void display() const noexcept;

	int getCode() const noexcept;
	std::string getTitle() const noexcept;
	Timing getTiming() const;

	void setCode(int) ;
	void setTitle(std::string);
	void setTiming(const Timing&);

	static int currentCode;
};

}//namespace

#endif