#ifndef SCHEDULABLE_H

#define SCHEDULABLE_H
#include <string>

class Schedulable
{
protected:
	int id;

public:
	Schedulable();
	Schedulable(int);
	Schedulable(const Schedulable&) = default;
	virtual ~Schedulable();

	int getId();
	void setId(int);

	virtual std::string toString() = 0;
	virtual std::string tuple() = 0;
};

#endif