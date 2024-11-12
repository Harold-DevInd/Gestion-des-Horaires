#include "Event.h"

#include <string.h>
#include <iostream>

using namespace std;

//*******************************************************************************************************
//Constructeurs et descructeurs
//*******************************************************************************************************

Event::Event()
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut"<<endl;
	#endif

	code = 0;

	//title = nullptr;
	title = new char[30];
	strcpy(title, "Evenement sans titre");
}

Event::~Event()
{
	#ifdef DEBUG
	cout<<"Descructeur de Event"<<endl;
	#endif

	if(title != nullptr)
	{
		delete(title);
		title = nullptr;
	}
}

Event::Event(int c, const char* t)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation"<<endl;
	#endif

	this->title = new char[strlen(t)+1];
	strcpy(this->title, t);
	this->code = c;

}

Event::Event(const Event& e)
{
	#ifdef DEBUG
	cout<<"Constructeur par copie"<<endl;
	#endif


	title = new char[strlen(e.title)+1];
	strcpy(title, e.title);

	this->code = e.code;
	//this->title = title;
}

int Event::getCode() const
{
	return this->code;
}

const char* Event::getTitle() const
{
	return this->title;
}

void Event::setCode(int c)
{
	this->code = c;
}

void Event::setTitle(const char* t)
{
	delete(title);
	title = new char[strlen(t)+1];
	strcpy(title, t);
}


//*******************************************************************************************************
//Methodes publiques generales
//*******************************************************************************************************

void Event::display() const
{
	cout << "Code : "<<code<<" intitule : "<<title<<endl;
}