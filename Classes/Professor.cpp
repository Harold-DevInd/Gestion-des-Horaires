#include "Professor.h"
#include "Schedulable.h"
#include <iostream>
#include <string.h>

using namespace std;

//*******************************************************************************************************
//Constructeurs et descructeurs
//*******************************************************************************************************

Professor::Professor()
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut de professor"<<endl;
	#endif
	lastName = "none";

	firstName = "none";
}

Professor::Professor(int i, std::string l, std::string f) : Schedulable(i)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation de professor"<<endl;
	#endif
	this->setLastName(l);
	this->setFirstName(f);
}

Professor::Professor(const Professor& p): Schedulable(p)
{
	#ifdef DEBUG
	cout<<"Constructeur de copie de professor"<<endl;
	#endif

	this->setLastName(p.lastName);
	this->setFirstName(p.firstName);
}

Professor::~Professor()
{
	#ifdef DEBUG
	cout<<"Destructeur par defaut  de professor"<<endl;
	#endif
}

//*******************************************************************************************************
//Setteurs et getteurs
//*******************************************************************************************************

std::string Professor::getLastName() const
{
	return lastName;
}

std::string Professor::getFirstName() const
{
	return firstName;
}

void Professor::setLastName(std::string l)
{
	lastName = l;
}

void Professor::setFirstName(std::string f)
{
	firstName = f;
}

//*******************************************************************************************************
//Methodes publiques generales
//*******************************************************************************************************

std::string Professor::toString()
{
	std::string ret = lastName;

	ret = ret + " ";
	ret = ret + firstName;

	return ret;
}

std::string Professor::tuple()
{
	std::string ret = to_string(id);

	ret += ";";
	ret += lastName;
	ret += ";";
	ret += firstName;

	return ret;
}
//*******************************************************************************************************
//Methodes privées generales
//*******************************************************************************************************

//*******************************************************************************************************
//Surharge des operateurs
//*******************************************************************************************************

Professor& Professor::operator=(const Professor& p)
{
	this->setId(p.id);
	this->setLastName(p.lastName);
	this->setFirstName(p.firstName);

	return *this;
}

std::ostream& operator<<(std::ostream& o, Professor& p)
{
	o << p.toString() << endl;

	return o;
}
