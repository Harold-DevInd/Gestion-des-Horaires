#include "Classroom.h"
#include "Schedulable.h"
#include <iostream>
#include <string.h>

using namespace std;

//*******************************************************************************************************
//Constructeurs et descructeurs
//*******************************************************************************************************

Classroom::Classroom()
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut de Classroom"<<endl;
	#endif
	name = "none";
}

Classroom::Classroom(int i, std::string n, int s) : Schedulable(i)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation de Classroom"<<endl;
	#endif
	this->setName(n);
	this->setSeatingCapacity(s);
}

Classroom::Classroom(const Classroom& c): Schedulable(c)
{
	#ifdef DEBUG
	cout<<"Constructeur de copie  de Classroom"<<endl;
	#endif

	this->setName(c.name);
	this->setSeatingCapacity(c.seatingCapacity);
}

Classroom::~Classroom()
{
	#ifdef DEBUG
	cout<<"Destructeur par defaut de Classroom"<<endl;
	#endif
}

//*******************************************************************************************************
//Setteurs et getteurs
//*******************************************************************************************************

std::string Classroom::getName() const
{
	return name;
}

int Classroom::getSeatingCapacity() const
{
	return seatingCapacity;
}

void Classroom::setName(std::string n)
{
	name = n;
}

void Classroom::setSeatingCapacity(int s)
{
	seatingCapacity = s;
}

//*******************************************************************************************************
//Methodes publiques generales
//*******************************************************************************************************

std::string Classroom::toString()
{
	std::string ret = name;

	ret = ret + " (";
	ret = ret + to_string(seatingCapacity);
	ret += ")";

	return ret;
}

std::string Classroom::tuple()
{
	std::string ret = to_string(id);

	ret += ";";
	ret += name;
	ret += " (";
	ret += to_string(seatingCapacity);
	ret += ")";

	return ret;
}
//*******************************************************************************************************
//Methodes privées generales
//*******************************************************************************************************

//*******************************************************************************************************
//Surharge des operateurs
//*******************************************************************************************************

Classroom& Classroom::operator=(const Classroom& c)
{
	this->setId(c.id);
	this->setName(c.name);
	this->setSeatingCapacity(c.seatingCapacity);

	return *this;
}

std::ostream& operator<<(std::ostream& o, Classroom& c)
{
	o << c.toString() << endl;

	return o;
}