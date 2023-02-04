#include <iostream>
#include "3.h"
using namespace std;
date::date()
{
    cout << "Default constructor called!" << endl;
    day = 1;
    month = 1;
    year = 1969;
}
void date::print()
{
    cout << day << "/" << month << "/" << year << endl;
}
void date::input()
{
    for (int i=0;i<1;i++)
    {
        cout << "Enter date: ";
        cin >> day;
        if (day>32)
        {
            cout<<"Invalid entry!"<<"Enter again!"<<endl;
            i--;
        }
    }
    for (int i=0;i<1;i++)
    {
        cout << "Enter month: ";
        cin >> month;
        if (month>13||month<0)
        {
            cout<<"Invalid entry!"<<"Enter again"<<endl;
            i--;
        }
    }
    for (int i=0;i<1;i++)
    {
        cout << "Enter year: ";
        cin >> year;
    }
}
void date :: setday ()
{
    int x;
    cout<<"Enter day: ";cin>>x;
    day=x;
}
void date :: getday ()
{
    cout<<"Your day is: "<<day;
}
void date :: getmonth ()
{
    cout<<"Your month is: "<<month;
}
void date :: getyear ()
{
    cout<<"Your year is: "<<year;
}
void date :: setmonth ()
{
    int x;
    cout<<"Enter month: ";cin>>x;
    month=x;
}
void date :: setyear ()
{
    int x;
    cout<<"Enter day: ";cin>>x;
    year=x;
}

int main()
{
    date date1;
    date1.input();
    date1.print();
    date xmasday;
    xmasday.print ();
    xmasday.setday ();
    xmasday.setmonth();
    xmasday.setyear ();
    xmasday.print();
    xmasday.getday();
    xmasday.getmonth();
    xmasday.getyear();

}