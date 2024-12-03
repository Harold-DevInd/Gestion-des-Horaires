#ifndef CLASSROOM_H

#define CLASSROOM_H
#include <string.h>
#include <iostream>
#include <fstream>
#include "Schedulable.h"

class Classroom : public Schedulable
{
friend std::ofstream& operator<<(std::ofstream&, const Classroom&);
friend std::ifstream& operator>>(std::ifstream&, Classroom&);

protected:
	std::string name;
	int seatingCapacity;

public:
	Classroom();
	Classroom(int, std::string, int);
	Classroom(const Classroom&);
	~Classroom();

	std::string getName() const;
	int getSeatingCapacity() const;
	void setName(std::string);
	void setSeatingCapacity(int);

	std::string toString() override;
	std::string tuple() override;

	Classroom& operator=(const Classroom&);
};
#endif