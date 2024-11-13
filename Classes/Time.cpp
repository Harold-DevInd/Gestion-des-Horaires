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
	#ifdef DEBUG
	cout<<"Constructeur par defaut de time"<<endl;
	#endif

	hour = 0;
	minute = 0;
}

Time::~Time()
{
	#ifdef DEBUG
	cout<<"Descructeur de Time"<<endl;
	#endif
}

Time::Time(int h, int m)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation avec instant"<<endl;
	#endif

	setHour(h);
	setMinute(m);
}

Time::Time(int d)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation avec duree"<<endl;
	#endif

	setHour(d / 60);
	setMinute(d % 60);
}

Time::Time(const Time& t)
{
	#ifdef DEBUG
	cout<<"Constructeur de copie de time"<<endl;
	#endif

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

//*******************************************************************************************************
//Methodes privées generales
//*******************************************************************************************************

int Time::compTime(const Time& t) const
{
	if (this->hour > t.getHour())
		return 1;
	if (this->hour < t.getHour())
		return -1;
	//Heure égale
	if (this->minute > t.getMinute())
		return 1;
	if (this->minute < t.getMinute())
		return -1;
	//Minute égale
	return 0;
}

//*******************************************************************************************************
//Surharge des operateurs
//*******************************************************************************************************
Time& Time::operator=(const Time& t)
{
	this->setHour(t.hour);
	this->setMinute(t.minute);

	return (*this);
}

Time& Time::operator=(int d)
{
	int x = d;

	this->setHour(x/60);
	this->setMinute(x%60);

	return (*this);
}

Time Time::operator+(int m) const
{
	Time resultat(*this);

	while((resultat.getMinute() + m) >= 60)
	{
		m = m - (60 - resultat.getMinute());
		resultat.setHour(resultat.getHour() + 1);
		resultat.setMinute(0);
	}

	resultat.setMinute(resultat.getMinute() + m);

	return resultat;
}

Time operator+(int m, const Time& d)
{
	Time t(d);

	return t + m;
}

Time operator+(const Time& t, const Time& d)
{
	Time h1(t);
	Time h2(d);

	while((h1.getMinute() + h2.getMinute()) >= 60)
	{
		
		h2.setMinute(h2.getMinute() - (60 - h1.getMinute()));
		h1.setMinute(0);
		h1.setHour(h1.getHour() + 1);
	}

	h1.setMinute(h1.getMinute() + h2.getMinute());
	h1.setHour(h1.getHour() + h2.getHour());

	return h1;
}


Time Time::operator-(int m) const
{
	Time resultat(*this);
	
	while((resultat.getMinute() - m) < 0)
	{
		m = m - resultat.getMinute();
		resultat.setHour(resultat.getHour() - 1);
		resultat.setMinute(60);
	}
	
	resultat.setMinute(resultat.getMinute() - m);

	return resultat;
}

Time operator-(int m, const Time& d)
{
	Time t1(m);
	Time t2(d);

	return t1 - t2;
}

Time operator-(const Time& t, const Time& d)
{
	Time h1(t);
	Time h2(d);
	
	while((h1.getMinute() - h2.getMinute()) < 0)
	{
		h2.setMinute(h2.getMinute() - h1.getMinute());
		h1.setHour(h1.getHour() - 1);
		h1.setMinute(60);
	}

	h1.setMinute(h1.getMinute() - h2.getMinute());
	h1.setHour(h1.getHour() - h2.getHour());

	return h1;
}

int Time::operator>(const Time& t) const
{
	return compTime(t) == 1;
}

int Time::operator<(const Time& t) const
{
	return compTime(t) == -1;
}

int Time::operator==(const Time& t) const
{
	return compTime(t) == 0;
}

std::ostream& operator<<(std::ostream& s,const Time& t)
{
	s << t.getHour() << "h" << t.getMinute() << endl;

	return s;
}

std::istream& operator>>(std::istream& e, Time& t)
{
	std::string saisie;

	cin >> saisie;

	int heure = std::stoi(saisie.substr(0,2));
	int minute = std::stoi(saisie.substr(3,2));

	t.setHour(heure);
	t.setMinute(minute);

	return e;
}

Time Time::operator++()
{
	*this = (*this) + 30;

	return (*this);
}

Time Time::operator++(int)
{
	Time temp(*this);

	*this = (*this) + 30;

	return temp;
}

Time Time::operator--()
{
	*this = (*this) - 30;

	return (*this);
}

Time Time::operator--(int)
{
	Time temp(*this);

	*this = (*this) - 30;

	return temp;
}

}//namespace
