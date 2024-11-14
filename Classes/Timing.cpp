#include "Timing.h"

#include <string.h>
#include <iostream>

using namespace std;
namespace planning{

const std::string Timing::MONDAY = "Lundi";
const std::string Timing::TUESDAY = "Mardi";
const std::string Timing::WEDNESDAY = "Mercredi"; 
const std::string Timing::THURSDAY= "Jeudi";
const std::string Timing::FRIDAY = "Vendredi";
const std::string Timing::SATURDAY = "Samedi";
const std::string Timing::SUNDAY = "Dimanche";

//*******************************************************************************************************
//Constructeurs et descructeurs
//*******************************************************************************************************

Timing::Timing()
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut de Timing"<<endl;
	#endif

	this->day = "Pas de date";

	this->start = Time(0,0);
	this->duration = Time(0);
}

Timing::~Timing()
{
	#ifdef DEBUG
	cout<<"Destructeur par defaut de Timing"<<endl;
	#endif
}

Timing::Timing(std::string da, const Time& s, const Time& du)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation de Timing"<<endl;
	#endif

	setDay(da);
	setStart(s);
	setDuration(du);
}

Timing::Timing(const Timing& tm)
{
	#ifdef DEBUG
	cout<<"Constructeur par copie de Timing"<<endl;
	#endif

	setDay(tm.day);
	setStart(tm.start);
	setDuration(tm.duration);
}

//*******************************************************************************************************
//Setteurs et getteurs
//*******************************************************************************************************

std::string Timing::getDay()
{
	return day;
}

Time Timing::getStart()
{
	return start;
}

Time Timing::getDuration()
{
	return duration;
}

void Timing::setDay(std::string d)
{
	this->day = d;
}

void Timing::setStart(const Time& s)
{
	this->start = s;
}

void Timing::setDuration(const Time& d)
{
	this->duration = d;
}

//*******************************************************************************************************
//Methodes publiques generales
//*******************************************************************************************************

void Timing::display() const
{
	cout << "le " << day << ", a ";
	start.display();
	cout << " et durera ";
	duration.display();
	cout << " de temps."<<endl;
}

}//namespace