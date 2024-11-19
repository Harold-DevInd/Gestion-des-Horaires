#include "Timing.h"
#include "TimingException.h"

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

Timing::Timing() noexcept
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut de Timing"<<endl;
	#endif

	this->day = "Pas de date";

	this->start = Time(0,0);
	this->duration = Time(0);
}

Timing::~Timing() noexcept
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

std::string Timing::getDay() const noexcept
{
	return day;
}

Time Timing::getStart() const noexcept
{
	return start;
}

Time Timing::getDuration() const noexcept
{
	return duration;
}

void Timing::setDay(std::string d)
{
	if(getDayOrder(d) == 0)
		throw TimingException(1, "Jour invalide");

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

void Timing::display() const noexcept
{
	cout << "le " << day << ", a ";
	start.display();
	cout << " et durera ";
	duration.display();
	cout << " de temps."<<endl;
}

//*******************************************************************************************************
//Methodes privées generales
//*******************************************************************************************************

int Timing::getDayOrder(const std::string& day) const noexcept
{
    if (day == Timing::MONDAY) return 1;
    if (day == Timing::TUESDAY) return 2;
    if (day == Timing::WEDNESDAY) return 3;
    if (day == Timing::THURSDAY) return 4;
    if (day == Timing::FRIDAY) return 5;
    if (day == Timing::SATURDAY) return 6;
    if (day == Timing::SUNDAY) return 7;
    return 0; // Valeur par défaut si le jour ne correspond pas
}

int Timing::compTiming(const Timing& ti) const
{
	// Comparaison du jour en utilisant l'ordre de chaque jour
    int thisDayOrder = getDayOrder(this->day);
    int otherDayOrder = getDayOrder(ti.getDay());

    if (thisDayOrder > otherDayOrder) {
        return 1;
    }
    if (thisDayOrder < otherDayOrder) {
        return -1;
    }

    // Si les jours sont égaux, comparons les heures de début
    if (this->start > ti.getStart()) {
        return  1;
    }
    if (this->start < ti.getStart()) {
        return -1;
    }

    // Si les heures de début sont égales, comparons la durée
    if (this->duration > ti.getDuration()) {
        return 1;
    }
    if (this->duration <ti.getDuration()) {
        return -1;
    }

    // Si tout est égal
    return 0;
}

//*******************************************************************************************************
//Surharge des operateurs
//*******************************************************************************************************
int Timing::operator>(const Timing& ti) const noexcept
{
	return compTiming(ti) == 1;
}

int Timing::operator<(const Timing& ti) const noexcept
{
	return compTiming(ti) == -1;
}

int Timing::operator==(const Timing& ti) const noexcept
{
	return compTiming(ti) == 0;
}

int Timing::operator!=(const Timing& ti) const noexcept
{
	//retourne true si les objets ne sont pas égaux, et false s’ils sont égaux
	return !(*this == ti);
}

}//namespace
