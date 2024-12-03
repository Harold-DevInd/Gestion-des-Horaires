#include "Time.h"
#include "TimeException.h"

#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
namespace planning{

//*******************************************************************************************************
//Constructeurs et descructeurs
//*******************************************************************************************************

Time::Time() noexcept
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut de time"<<endl;
	#endif

	hour = 0;
	minute = 0;
}

Time::~Time() noexcept
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

Time::Time(const Time& t) noexcept
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
	if(h < 0 || h > 23)
		throw TimeException(1, "Heure invalide");
	this->hour = h;
}

void Time::setMinute(int m)
{
	if(m < 0 || m > 59)
		throw TimeException(2, "Minute invalide");
	this->minute = m;
}

int Time::getHour() const noexcept
{
	return this->hour;
}

int Time::getMinute() const noexcept
{
	return this->minute;
}


//*******************************************************************************************************
//Methodes publiques generales
//*******************************************************************************************************

void Time::display() const noexcept
{
	cout << hour << "H" << minute;
}

//*******************************************************************************************************
//Methodes privées generales
//*******************************************************************************************************

int Time::compTime(const Time& t) const noexcept
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

	while((resultat.minute + m) >= 60)
	{
		m = m - (60 - resultat.minute);
		resultat.hour = resultat.hour + 1;
		resultat.minute = 0;
	}

	resultat.minute = resultat.minute + m;

	//Exception levée
	if(resultat.hour > 23)
		throw TimeException(3, "Erreur d'overflow");

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

	while(h1.minute + h2.minute >= 60)
	{
		
		h2.minute = h2.minute - (60 - h1.minute);
		h1.minute = 0;
		h1.hour =h1.hour + 1;
	}

	h1.minute = h1.minute + h2.minute;
	h1.hour = h1.hour + h2.hour;

	//Exception levée
	if(h1.hour > 23)
		throw TimeException(3, "Erreur d'overflow");

	return h1;
}


Time Time::operator-(int m) const
{
	Time resultat(*this);
	
	while((resultat.minute - m) < 0)
	{
		m = m - resultat.minute;
		resultat.hour = resultat.hour - 1;
		resultat.minute = 60;
	}
	
	resultat.minute = resultat.minute - m;

	//Exception levée
	if((resultat.hour < 0) || (resultat.minute > 59))
		throw TimeException(3, "Erreur d'overflow");

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

	 // Gestion des minutes
    if (h1.minute < h2.minute) {
        // Emprunt d'une heure si nécessaire
        h1.hour = h1.hour - 1;
        h1.minute =h1.minute + 60;
    }

    h1.minute = h1.minute - h2.minute;
    h1.hour = h1.hour - h2.hour;

	//Exception levée
	if((h1.hour < 0) || (h1.minute < 0))
		throw TimeException(3, "Erreur d'overflow");

	return h1;
}

int Time::operator>(const Time& t) const noexcept
{
	return compTime(t) == 1;
}

int Time::operator<(const Time& t) const noexcept
{
	return compTime(t) == -1;
}

int Time::operator==(const Time& t) const noexcept
{
	return compTime(t) == 0;
}

std::ofstream& operator<<(std::ofstream& ofs,const Time& t)
{
	/*std::ostringstream oss;	
	printf("avant la serialisation");
	oss << "<Time>\n<hour>\n" << t.getHour() << "\n<"\"hour>\n<minute>\n" << t.getMinute() << "\n<'\'minute>\n<'\'Time>";

	printf("apres la serialisation");
	std::string resultat = oss.str();

	ofs << resultat;*/

	// Construction du contenu XML-like
    ofs << "<Time>\n";
    ofs << "<hour>\n" << t.getHour() << "\n</hour>\n";
    ofs << "<minute>\n" << t.getMinute() << "\n</minute>\n";
    ofs << "</Time>";

	return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Time& t)
{
	std::string line;
    int hour = 0, minute = 0, i = 0;

    while (i < 8)
    {
    	std::getline(ifs, line);

        if (line == "<hour>")
        {
            if (std::getline(ifs, line))
            {
                t.setHour(std::stoi(line));
            }
        }
        else if (line == "<minute>")
        {
            if (std::getline(ifs, line))
            {
                t.setMinute(std::stoi(line));
            }
        }
        else if(line == "</Time>")
        {
        	i = 8;
        }

        i++;
    }

	return ifs;
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
