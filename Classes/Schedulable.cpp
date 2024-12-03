#include "Schedulable.h"

#include <iostream>
#include <string>

using namespace std;

//*******************************************************************************************************
//Constructeurs et descructeurs
//*******************************************************************************************************

Schedulable::Schedulable()
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut"<<endl;
	#endif
}

Schedulable::Schedulable(int i)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation"<<endl;
	#endif

	this->setId(i);
}

Schedulable::~Schedulable()
{
	#ifdef DEBUG
	cout<<"Destructeur par defaut de Schedulable"<<endl;
	#endif
}
//*******************************************************************************************************
//Setteurs et getteurs
//*******************************************************************************************************

int Schedulable::getId() const
{
	return this->id;
}

void Schedulable::setId(int i)
{
	this->id = i;
}