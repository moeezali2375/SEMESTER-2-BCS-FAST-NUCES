#include <iostream>
#include "Header.h"
using namespace std;

event *addeventover(event *a)
{
	char name[20], venue[50], date[11], time[9];

	cout << "Enter the event name: " << endl;
	cin.ignore();
	cin.getline(name, 20);
	cout << "Enter the event venue: " << endl;
	cin.getline(venue, 50);
	cout << "Enter the event date: " << endl;
	cin.getline(date, 11);
	cout << "Enter the event time: " << endl;
	cin.getline(time, 9);
	a = new event(name, venue, date, time);
	return a;
}

void setevent(event &a)
{
	char name[20], venue[50], date[11], time[9];
	cout << "Enter the event name: " << endl;
	cin.ignore();
	cin.getline(name, 20);
	cout << "Enter the event venue: " << endl;
	cin.getline(venue, 50);
	cout << "Enter the event date: " << endl;
	cin.getline(date, 11);
	cout << "Enter the event time: " << endl;
	cin.getline(time, 9);
	a.set1(name);
	a.set2(venue);
	a.set3(date);
	a.set4(time);
}
int main()
{
	int choice;
	event *a = nullptr;
	event b;
	while (96)
	{
		cout << "enter choice!" << endl
			 << "Add New Event Using Overloaded Constructor: Enter 1" << endl
			 << "Add New Event Using Setters: Enter 2" << endl
			 << "Display Event: Enter 3" << endl
			 << "Exit: Enter 0" << endl;
		cin >> choice;

		if (choice == 0)
		{
			cout << "program closed!";
			break;
		}
		if (choice == 1)
		{
			a= addeventover(a);
			a->displayevent();
		}
		if (choice == 2)
		{
			setevent(b);
			b.displayevent();
		}
	}

	return 0;
}