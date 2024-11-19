#ifndef TIMEEXCEPTION_H

#define TIMEEXCEPTION_H
#include "Exception.h"

namespace planning{

class TimeException : public Exception
{
protected:
	int code;

public:
	static const int INVALID_HOUR;
	static const int INVALID_MINUTE;
	static const int OVERFLOW;

	TimeException();
	TimeException(int, std::string);
	TimeException(const TimeException&);
	~TimeException();

	int getCode() const;
	void setCode(int);
};

}//namespace
#endif