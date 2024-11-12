#ifndef EVENT_H

#define EVENT_H

class Event 
{
private:
	int code;
	char* title;

public:
	Event();
	~Event();
	Event(int,const char*);
	Event(const Event&);

	void display() const;
	int getCode() const;
	const char* getTitle() const;
	void setCode(int);
	void setTitle(const char*);
};

#endif