#include <iostream>
using namespace std;
class date
{
private:
    int day, month, year;

public:
    date();
    void print ();
    void input ();
    void setday ();
    void getday ();
    void setmonth ();
    void getmonth ();
    void setyear ();
    void getyear ();
};