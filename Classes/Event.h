#ifndef EVENT_H

#define EVENT_H
#include "Timing.h"

namespace planning{

class Event 
{
private:
	int code;
	char* title;
	Timing* timing;

public:
	Event() noexcept;
	~Event() noexcept;
	Event(int,const char*);
	Event(const Event&);

	void display() const noexcept;

	int getCode() const noexcept;
	const char* getTitle() const noexcept;
	Timing getTiming();

	void setCode(int) ;
	void setTitle(const char*);
	void setTiming(const Timing&);

	static int currentCode;
};

}//namespace

#endif