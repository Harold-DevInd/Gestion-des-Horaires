#ifndef TIMINGEXCEPTION_H

#define TIMINGEXCEPTION_H
#include "Exception.h"

namespace planning{

class TimingException : public Exception
{
protected:
	int code;

public:
	static const int INVALID_DAY;
	static const int NO_TIMING;

	TimingException();
	TimingException(int, std::string);
	TimingException(const TimingException&);
	~TimingException();

	int getCode() const;
	void setCode(int);
};

}//namespace
#endif