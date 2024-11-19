#include "TimeException.h"

#include <string>
#include "Exception.h"
using namespace std;
namespace planning{

const int INVALID_HOUR = 1;
const int INVALID_MINUTE = 2;
const int OVERFLOW = 3;

//*******************************************************************************************************
//Constructeurs et descructeurs
//*******************************************************************************************************
TimeException::TimeException()
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut de TimeException"<<endl;
	#endif

}

TimeException::~TimeException()
{
	#ifdef DEBUG
	cout<<"Descructeur de TimeException"<<endl;
	#endif
}

TimeException::TimeException(int c, std::string n) : Exception(n)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation de TimeException"<<endl;
	#endif

	this->setCode(c);
}

TimeException::TimeException(const TimeException& te) : Exception(te)
{
	#ifdef DEBUG
	cout<<"Constructeur de copie de TimeException"<<endl;
	#endif

	this->setCode(te.code);
}
//*******************************************************************************************************
//Setteurs et getteurs
//*******************************************************************************************************

int TimeException::getCode() const
{
	return this->code;
}

void TimeException::setCode(int c)
{
	this->code = c;
}

}//namespace