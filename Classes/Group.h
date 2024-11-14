#ifndef GROUP_H

#define GROUP_H
#include <string>
#include <iostream>
#include "Schedulable.h"

class Group : public Schedulable
{
friend std::ostream& operator<<(std::ostream&,Group&);

protected:
	std::string name;

public:
	Group();
	Group(int, std::string);
	Group(const Group&);
	~Group();

	std::string getName() const;
	void setName(std::string);

	std::string toString() override;
	std::string tuple() override;

	Group& operator=(const Group&);
};
#endif