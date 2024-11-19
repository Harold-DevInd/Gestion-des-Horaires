#include "TimingException.h"

#include <string>
#include "Exception.h"

using namespace std;
namespace planning{

const int INVALID_DAY = 1;
const int NO_TIMING = 2;

//*******************************************************************************************************
//Constructeurs et descructeurs
//*******************************************************************************************************
TimingException::TimingException()
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut de TimingException"<<endl;
	#endif

}

TimingException::~TimingException()
{
	#ifdef DEBUG
	cout<<"Descructeur de TimingException"<<endl;
	#endif
}

TimingException::TimingException(int c, std::string n) : Exception(n)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation de TimingException"<<endl;
	#endif

	this->setCode(c);
}

TimingException::TimingException(const TimingException& tie) : Exception(tie)
{
	#ifdef DEBUG
	cout<<"Constructeur de copie de TimingException"<<endl;
	#endif

	this->setCode(tie.code);
}
//*******************************************************************************************************
//Setteurs et getteurs
//*******************************************************************************************************

int TimingException::getCode() const
{
	return this->code;
}

void TimingException::setCode(int c)
{
	this->code = c;
}

}//namespace