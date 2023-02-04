#include <iostream>
using namespace std;
class date
{
    int day;
    char *month;
    int year;

public:
    date(int d = 0, char *m = nullptr, int y = 0) : day(d), month(m), year(y)
    {
        // if (month==nullptr)
        // ;
        // else
        // delete []month;
        // month=new char [strlen(m)+1];
        // strcpy(month,m);
    }
    friend ostream &operator<<(ostream &out, date d);
};
ostream &operator<<(ostream &out, date d)
{
    out << "Date is: " << endl;
    out << "Day: " << d.day << endl;
    out << "Month: " << d.month << endl;
    out << "Year: " << d.year;
    out << endl;
    return out;
}
int main()
{
    char array[] = {"Hello"};
    date d1(1,array);
    cout << d1;
}