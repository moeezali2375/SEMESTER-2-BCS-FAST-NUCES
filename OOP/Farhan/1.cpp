#include <iostream>
using namespace std;
// class fraction
// {
//     int num;
//     int denum;
//     static int a;

// public:
//     fraction(int n = 0, int d = 1)
//     {
//         num = n;
//         denum = d;
//         a++;
//     }
//     fraction getter(fraction f)
//     {
//         return this;
//     }
//     friend ostream &operator<<(ostream &out, fraction f);
// };

// int getter(int a)
// {
//     return a;
// }
// ostream &operator<<(ostream &out, fraction f)
// {
//     cout << "The fraction is: " << f.num << "/" << f.denum << endl;
//     return out;
// }
// int main()
// {
//     fraction a(1, 2), b;
//     cout << getter(5);
//     a.getter();

//     // cout << a << b << temp;
// }
class set
{
    int *ptr;
    int size;

public:
    set()
    {
        ptr = nullptr;
        size = 0;
    }
    set(set &a)
    {
        this->size = a.size;
        this->ptr = new int[size];
        for (int i = 0; i < a.size; i++)
        {
            this->ptr[i] = a.ptr[i];
        }
    }
    set &operator=(set a)
    {
        if (this->size > 0)
            delete[] this->ptr;
        this->size = a.size;
        this->ptr = new int[size];
        for (int i = 0; i < a.size; i++)
        {
            this->ptr[i] = a.ptr[i];
        }
        return *this;
    }
    set(int s)
    {
        size = s;
        cout << "Enter the data for the set: ";
        ptr = new int[s];
        for (int i = 0; i < s; i++)
        {
            cin >> ptr[i];
        }
    }
    ~set()
    {
        if (size > 0)
            delete[] ptr;
    }
    friend ostream &operator<<(ostream &out, set a);
};
ostream &operator<<(ostream &out, set a)
{
    out << "The set is: " << endl;
    out << "{";
    for (int i = 0; i < a.size; i++)
    {
        out << a.ptr[i];
        if (i == a.size - 1)
            cout << "}" << endl;
        else
            cout << ",";
    }
    cout << "The size is: " << a.size << endl;
    return out;
}
int main()
{
    set a(5);
    cout << a;
    set b;
    b = a;
}

// a.ptr=69;
// b.ptr=NULL;
// b=a; b.ptr=a.ptr,b.size=a.size;
// b.ptr=69;
