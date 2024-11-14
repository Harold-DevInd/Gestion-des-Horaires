#include "Time.h"

#include <string.h>
#include <iostream>

using namespace std;
namespace planning{

//*******************************************************************************************************
//Constructeurs et descructeurs
//*******************************************************************************************************

Time::Time()
{
	/*#ifdef DEBUG
	cout<<"Constructeur par defaut"<<endl;
	#endif*/

	hour = 0;
	minute = 0;
}

Time::~Time()
{
	/*#ifdef DEBUG
	cout<<"Descructeur de Time"<<endl;
	#endif*/
}

Time::Time(int h, int m)
{
	/*#ifdef DEBUG
	cout<<"Constructeur d initialisation avec instant"<<endl;
	#endif*/

	setHour(h);
	setMinute(m);
}

Time::Time(int d)
{
	/*#ifdef DEBUG
	cout<<"Constructeur d initialisation avec duree"<<endl;
	#endif*/

	setHour(d / 60);
	setMinute(d % 60);
}

Time::Time(const Time& t)
{
	/*#ifdef DEBUG
	cout<<"Constructeur par copie"<<endl;
	#endif*/

	this->hour = t.hour;
	this->minute = t.minute;
}


//*******************************************************************************************************
//Setteurs et getteurs
//*******************************************************************************************************

void Time::setHour(int h)
{
	this->hour = h;
}

void Time::setMinute(int m)
{
	this->minute = m;
}

int Time::getHour() const
{
	return this->hour;
}

int Time::getMinute() const
{
	return this->minute;
}


//*******************************************************************************************************
//Methodes publiques generales
//*******************************************************************************************************

void Time::display() const
{
	cout << hour << "H" << minute;
}

}//namespace