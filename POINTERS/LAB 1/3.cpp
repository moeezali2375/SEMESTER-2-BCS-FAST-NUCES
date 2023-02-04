
#include <iostream>
using namespace std;
int main()
{
    int a = 1, b = 3, c = 5;
    int *p;
    int *q;
    int *r;
    p = &a;
    q = &b;
    r = &c;
    cout << a << '\t'<<p<<'\t' << *p << '\t'<<&p<<'\t' << &a << endl;
    cout << b << '\t'<<q<<'\t'<<*q<<'\t'<<&q<<'\t' << &b << endl;
    cout << c << '\t'<<r<<'\t'<<*r<<'\t'<<&r<<'\t'<<&c<<endl;
}