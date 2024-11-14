#ifndef PROFESSOR_H

#define PROFESSOR_H
#include <string.h>
#include <iostream>
#include "Schedulable.h"

class Professor : public Schedulable
{
friend std::ostream& operator<<(std::ostream&, Professor&);

protected:
	std::string lastName;
	std::string firstName;

public:
	Professor();
	Professor(int, std::string, std::string);
	Professor(const Professor&);
	~Professor();

	std::string getLastName() const;
	std::string getFirstName() const;
	void setLastName(std::string);
	void setFirstName(std::string);

	std::string toString() override;
	std::string tuple() override;

	Professor& operator=(const Professor&);
};
#endif