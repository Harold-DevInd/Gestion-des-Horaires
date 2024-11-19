#ifndef EXCEPTION_H

#define EXCEPTION_H
#include <string>

namespace planning{

class Exception
{
protected:
	std::string message;

public:
	Exception();
	Exception(std::string);
	Exception(const Exception&) = default;
	~Exception();

	std::string getMessage() const;
	void setMessage(std::string);
};

}//namespace

#endif