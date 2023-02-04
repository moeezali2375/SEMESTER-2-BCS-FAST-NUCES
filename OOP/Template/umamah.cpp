#include <iostream>
#include <string>

using namespace std;

class Date
{
    int date;
    int month;
    int year;

public:
    Date()
    {
        date = month = year = 0;
    }

    Date(int a, int b, int c)
    {
        date = a;
        month = b;
        year = c;
    }

    friend istream &operator>>(istream &in, Date &obj);

    friend ostream &operator<<(ostream &out, Date obj);
};

ostream &operator<<(ostream &out, Date obj)
{
    cout << endl;
    out << obj.date << "/" << obj.month << "/" << obj.year;
    return out;
}
istream &operator>>(istream &in, Date &obj)
{
    cout << endl
         << "Please enter the date: ";
    in >> obj.date;
    cout << endl
         << "Please enter the month: ";
    in >> obj.month;
    cout << endl
         << "Please enter the year: ";
    in >> obj.year;

    return in;
}
template <typename T>
class Set
{
    T *p;
    T count;

public:
    Set()
    {
        p = nullptr;
        count = 0;
    }

    Set(Date *a, int b)
    {
        p = a;
        count = b;
    }

    Set(T *a, T b)
    {
        p = a;
        count = b;
    }

    void print()
    {
        for (int i = 0; i < count; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl
             << endl;
    }

    // ~Set()
    // {
    //     p = nullptr;
    //     count = 0;
    // }
};

int main()
{
    int intArray[] = {2, 3, 6, 1, 2, 0, -1};
    float floatArray[] = {4.1, 3.33, 7.15};

    Date d1, d2, d3;
    cin >> d1 >> d2 >> d3;

    Date dateArray[] = {d1, d2, d3};

    Set<int> S1(intArray, 7);

    Set<float> S2(floatArray, 3);

    Set<Date> S3(dateArray, 3);
    cout << endl
         << "Array 1: " << endl;
    S1.print();
    cout << endl
         << "Array 2: " << endl;
    S2.print();
    cout << endl
         << "Array 3: " << endl;
    //S3.print();

    return 0;
}