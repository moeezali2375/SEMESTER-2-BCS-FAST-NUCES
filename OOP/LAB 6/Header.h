#include <iostream>
using namespace std;
class event
{
private:
	char *eventname;
	char *eventvenue;
	char eventdate[11];
	char eventtime[9];

public:
	event();
	~event();
	event(char eventname[20], char eventvenue[50], char eventdate[11], char eventime[9]);
	void set1(char a[20]);
	void set2(char a[50]);
	void set3(char a[11]);
	void set4(char a[9]);
	char *get1();
	char *get2();
	char *get3();
	char *get4();

	void displayevent();
};

// DEFAULT CONSTRUCTOR
event::event()
{
	cout << "Default constructor called!!!!!" << endl;
	eventname = nullptr;
	eventvenue = nullptr;
}

// OVERLOADED CONSTRUCTOR
event::event(char eventname[20], char eventvenue[50], char eventdate[11], char eventtime[9])
{
	cout << "Overloaded constructor called!!!!" << endl;
	this->eventname = new char[strlen(eventname) + 1];
	this->eventvenue = new char[strlen(eventvenue) + 1];
	int i;
	for (i = 0; eventname[i] != '\0'; i++)
	{
		this->eventname[i] = eventname[i];
	}
	this->eventname[i] = '\0';
	for (i = 0; eventvenue[i] != '\0'; i++)
	{
		this->eventvenue[i] = eventvenue[i];
	}
	this->eventvenue[i] = '\0';
	for (int i = 0; i < 11; i++)
	{
		this->eventdate[i] = eventdate[i];
	}
	this->eventdate[i] = '\0';
	for (int i = 0; i < 9; i++)
	{
		this->eventtime[i] = eventtime[i];
	}
	this->eventtime[i] = '\0';
}

// SETTERS
void event::set1(char a[20])
{
	int i;
	int l = strlen(a);
	delete[]this->eventname;
	this->eventname=new char (l+1);
	for (i = 0; i < l; i++)
	{
		this->eventname[i] = a[i];
	}
	this->eventname[i+1] = '\0';
}

void event::set2(char a[50])
{
	int i;
	int l = strlen(a);
	delete[]this->eventvenue;
	this->eventvenue=new char (l+1);
	for (i = 0; i < l; i++)
	{
		this->eventvenue[i] = a[i];
	}
	this->eventvenue[i] = '\0';
}

void event::set3(char a[11])
{
	int i;
	int l = strlen(a);
	for (i = 0; a[i] != '\0'; i++)
	{
		this->eventdate[i] = a[i];
	}
	this->eventdate[i] = '\0';
}

void event::set4(char a[9])
{
	int i;
	int l = strlen(a);
	for (i = 0; a[i] != '\0'; i++)
	{
		this->eventtime[i] = a[i];
	}
	this->eventtime[i] = '\0';
}

// GETTERS
char *event::get1()
{
	return this->eventname;
}

char *event::get2()
{
	return this->eventvenue;
}

char *event::get3()
{
	return this->eventdate;
}

char *event::get4()
{
	return this->eventtime;
}

// DESTRUCTOR
event::~event()
{
	cout << "Default destructor called!!!!" << endl;
	delete[] eventname;
	delete[] eventvenue;
}

// DISPLAY
void event::displayevent()
{
	cout << "Displaying the info of the event!" << endl;
	cout << "The Event NAME is: " << this->eventname << endl;
	cout << "The Event VENUE is: " << this->eventvenue << endl;
	cout << "The Event DATE is: " << this->eventdate << endl;
	cout << "The Event TIME is: " << this->eventtime << endl;
}