#include "Event.h"
#include "TimingException.h"

#include <string.h>
#include <iostream>

using namespace std;
namespace planning{

int Event::currentCode = 1;

//*******************************************************************************************************
//Constructeurs et descructeurs
//*******************************************************************************************************

Event::Event() noexcept
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut de Event"<<endl;
	#endif

	code = 0;

	title = new char[30];
	strcpy(title, "Evenement sans titre");
	timing = nullptr;

	//Incrementation de la variable globale comptant les evenements
	currentCode++;
}

Event::~Event() noexcept
{
	#ifdef DEBUG
	cout<<"Destructeur de Event"<<endl;
	#endif

	if(title != nullptr)
	{
		delete(title);
		title = nullptr;
	}

	if(timing != nullptr)
	{
		delete(timing);
		timing = nullptr;
	}

	//Decrementation de la variable globale comptant les evenements
	currentCode--;
}

Event::Event(int c, const char* t)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation de Event"<<endl;
	#endif

	this->title = new char[strlen(t)+1];
	strcpy(this->title, t);
	this->code = c;

	this->timing = nullptr;

	//Incrementation de la variable globale comptant les evenements
	currentCode++;
}

Event::Event(const Event& e)
{
	#ifdef DEBUG
	cout<<"Constructeur par copie de Event"<<endl;
	#endif


	title = new char[strlen(e.title)+1];
	strcpy(title, e.title);

	this->code = e.code;

	if(e.timing != nullptr)
	{
		this->timing = new Timing(*e.timing);
	}
	else
	{
		this->timing = nullptr;
	}

	//Incrementation de la variable globale comptant les evenements
	currentCode++;
}

int Event::getCode() const noexcept
{
	return this->code;
}

const char* Event::getTitle() const noexcept
{
	return this->title;
}

Timing Event::getTiming()
{
	if(timing != nullptr)
		throw TimingException(2, "Timing null");

	return *this->timing;
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

void Event::setTiming(const Timing& ti)
{
	this->timing = new Timing(ti);
}


//*******************************************************************************************************
//Methodes publiques generales
//*******************************************************************************************************

void Event::display() const noexcept
{
	cout << "Code : "<<code<<" intitule : "<< title;
	cout << "\nSe deroule ";

	if(timing != nullptr)
	{
		timing->display();
	}
	else
	{
		cout << "Pas defini";
	}
	
	cout<<endl;
}

}//namespace