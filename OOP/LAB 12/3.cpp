#include <iostream>

using namespace std;

class birthDate
{
    int day;
    int month;
    int year;

public:
    birthDate()
    {
        day = 1;
        month = 1;
        year = 2000;
    }

    bool leapYear()
    {
        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                    return true;
                else
                    return false;
            }
            else
                return true;
        }
        else
            return false;
    }

    void invalidMonth()
    {
        try
        {
            if (month > 12 || month <= 0)
                throw month;
        }
        catch (int num)
        {
            cout << "Invalid Month: " << num << endl;
        }
    }

    void invalidDay()
    {
        try
        {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                if (day > 31 || day <= 0)
                    throw day;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                if (day > 30 || day <= 0)
                    throw day;
            }
            else if (month == 2 && leapYear() == 1)
            {
                if (day > 29 || day <= 0)
                    throw day;
            }
            else if (month == 2 && leapYear() == 0)
            {
                if (day > 28 || day <= 0)
                    throw day;
            }
        }
        catch (int num)
        {
            cout << "Invalid Day: " << num << endl;
        }
    }

    void invalidYear()
    {
        try
        {
            if (year >= 2022 || year <= 0)
                throw year;
        }
        catch (int num)
        {
            cout << "Invalid Year: " << num << endl;
        }
    }

    birthDate(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        invalidDay();
        invalidMonth();
        invalidYear();

        if (month == 1)
            cout << "January ";
        else if (month == 2)
            cout << "February ";
        else if (month == 3)
            cout << "March ";
        else if (month == 4)
            cout << "April ";
        else if (month == 5)
            cout << "May ";
        else if (month == 6)
            cout << "June ";
        else if (month == 7)
            cout << "July ";
        else if (month == 8)
            cout << "August ";
        else if (month == 9)
            cout << "September ";
        else if (month == 10)
            cout << "Ovtober ";
        else if (month == 11)
            cout << "November ";
        else if (month == 12)
            cout << "December ";
        cout << day << ", " << year << ".\n";
    }
};

int main()
{
    birthDate obj1(32, 12, 2003);

    return 0;
}