#include <iostream>
using namespace std;
class complex
{
    int real;
    int imag;

public:
    complex()
    {
        real = 0;
        imag = 0;
    }
    complex(int a, int b)
    {
        real = a;
        imag = b;
    }
    complex(complex &a)
    {
        real = a.real;
        imag = a.imag;
    }
    complex operator+(complex a)
    {
        complex res;
        res.real = this->real + a.real;
        res.imag = this->real + a.imag;
        return res;
    }
    complex operator-(complex a)
    {
        complex res;
        res.real = this->real - a.real;
        res.imag = this->real - a.imag;
        return res;
    }
    bool operator<(complex a)
    {
        if (real < a.real && imag < a.imag)
            return true;
        return false;
    }
    bool operator>(complex a)
    {
        if (real > a.real && imag > a.imag)
            return true;
        return false;
    }
    bool operator==(complex a)
    {
        if (real == a.real && imag == a.imag)
            return true;
        return false;
    }
    bool operator!=(complex a)
    {
        if (real != a.real && imag != a.imag)
            return true;
        return false;
    }
    complex operator++(int)
    {
        complex temp;
        temp.real = this->real++;
        temp.imag = this->imag ++;
        return temp;
    }
    complex &operator++()
    {
        complex temp;
        temp.real = ++this->real;
        temp.imag = ++this->imag;
        return temp;
    }
    // ~complex()
    // {
    //     cout<<"Destructor called!";
    // }
};
int main()
{
    complex C1;
    complex C2(5, 7);
    complex C3(4, 6);
    C1 = C2 + C3;
    C1 = C2 - C3;
    C1++;
    ++C1;
    
    if (C1 == C2)
        cout << "C1 == C2" << endl;
    else
        cout << "C1 != C2" << endl;
    if (C1 != C3)
        cout << "C1 != C3" << endl;
    else
        cout << "C1==C3" << endl;
    if (C2 > C3)
        cout << "C2 IS GREATER" << endl;
    else
        cout << "C3 IS GREATER" << endl;
    if (C2 < C3)
        cout << "C2 is smaller" << endl;
    else
        cout << "C3 is smaller" << endl;
}