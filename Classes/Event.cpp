#include "Event.h"
#include "Timing.h"
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

	title = "Pas de titre";
	
	timing = nullptr;

	//Incrementation de la variable globale comptant les evenements
	currentCode++;
}

Event::~Event() noexcept
{
	#ifdef DEBUG
	cout<<"Destructeur de Event"<<endl;
	#endif

	if(timing != nullptr)
	{
		delete(timing);
		timing = nullptr;
	}

	//Decrementation de la variable globale comptant les evenements
	currentCode--;
}

Event::Event(int c, std::string t)
{
	#ifdef DEBUG
	cout<<"Constructeur d initialisation de Event"<<endl;
	#endif

	this->title = t;
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


	title = e.title;

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

std::string Event::getTitle() const noexcept
{
	return this->title;
}

Timing Event::getTiming() const
{
	if(timing == nullptr)
		throw TimingException(2, "Timing null");

	return *this->timing;
}

void Event::setCode(int c)
{
	this->code = c;
}

void Event::setTitle(std::string t)
{
	this->title = t;
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

std::ofstream& operator<<(std::ofstream& ofs,const Event& e)
{
	// Construction du contenu XML-like
    ofs << "<Event>\n";
    ofs << "<code>\n"; 
    ofs << e.getCode();
    ofs << "\n</code>\n";
    ofs << "<title>\n"; 
    ofs << e.getTitle();
    ofs << "\n</title>\n";
    ofs << "<timing>\n";

    if (e.timing != nullptr)
    {
    	ofs << e.getTiming();
    }

    ofs << "\n</timing>\n";
    ofs << "</Event>\n";

	return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Event& e)
{
	std::string line;
	int i = 0;

    while (i < 34)
    {
    	std::getline(ifs, line);
    	
        if (line == "<code>")
        {
            if (std::getline(ifs, line))
            {
                e.setCode(stoi(line));
            }
        }
        else if (line == "<title>")
        {
            if (std::getline(ifs, line))
            {
                e.setTitle(line);
            }
        }
        else if (line == "<timing>")
        {
            if (std::getline(ifs, line))
            {	
            	if(line == "\0")
            	{
                	e.timing = nullptr;
            	}
            	else
            	{
            		e.timing = new Timing();
            		ifs >> *(e.timing);
            	}
            }
        }

        i++;
    }

	return ifs;
}

}//namespace