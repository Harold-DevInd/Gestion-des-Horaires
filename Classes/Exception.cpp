#include "Exception.h"

#include <string>

using namespace std;
namespace planning{

//*******************************************************************************************************
//Constructeurs et descructeurs
//*******************************************************************************************************

Exception::Exception()
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut d Exception"<<endl;
	#endif
}

Exception::~Exception()
{
	#ifdef DEBUG
	cout<<"Descructeur d Exception"<<endl;
	#endif
}
	
Exception::Exception(std::string m)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation d Exception"<<endl;
	#endif

	this->message = m;
}

//*******************************************************************************************************
//Setteurs et getteurs
//*******************************************************************************************************

std::string Exception::getMessage() const
{
	return message;
}

void Exception::setMessage(std::string m)
{
	this->message = m;
}

}//namespace
