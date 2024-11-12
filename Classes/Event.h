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
	Event();
	~Event();
	Event(int,const char*);
	Event(const Event&);

	void display() const;

	int getCode() const;
	const char* getTitle() const;
	Timing getTiming();

	void setCode(int);
	void setTitle(const char*);
	void setTiming(const Timing&);

	static int currentCode;
};

}//namespace

#endif