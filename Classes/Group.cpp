#include "Group.h"

#include <iostream>
#include <string>
#include "Schedulable.h"

using namespace std;

//*******************************************************************************************************
//Constructeurs et descructeurs
//*******************************************************************************************************

Group::Group()
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut de group"<<endl;
	#endif
	name = "none";
}

Group::Group(int i, std::string n) : Schedulable(i)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation de group"<<endl;
	#endif
	this->setName(n);
}

Group::Group(const Group& g): Schedulable(g)
{
	#ifdef DEBUG
	cout<<"Constructeur de copie de group"<<endl;
	#endif

	this->setName(g.name);
}

Group::~Group()
{
	#ifdef DEBUG
	cout<<"Destructeur par defaut de group"<<endl;
	#endif
}

//*******************************************************************************************************
//Setteurs et getteurs
//*******************************************************************************************************

std::string Group::getName() const
{
	return name;
}

void Group::setName(std::string n)
{
	name = n;
}

//*******************************************************************************************************
//Methodes publiques generales
//*******************************************************************************************************

std::string Group::toString()
{
	std::string ret = name;

	return ret;
}

std::string Group::tuple()
{
	std::string ret = to_string(id);
	ret += ";";
	ret += name;

	return ret;
}
//*******************************************************************************************************
//Methodes privées generales
//*******************************************************************************************************

//*******************************************************************************************************
//Surharge des operateurs
//*******************************************************************************************************

Group& Group::operator=(const Group& g)
{
	this->setId(g.id);
	this->setName(g.name);

	return *this;
}

std::ostream& operator<<(std::ostream& o,Group& g)
{
	o << g.toString() << endl;

	return o;
}
