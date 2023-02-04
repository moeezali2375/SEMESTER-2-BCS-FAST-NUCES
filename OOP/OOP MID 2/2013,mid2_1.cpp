#include <iostream>
using namespace std;
class D
{
public:
    D() { cout << "D ctor" << endl; }
    D(D &) { cout << "D copy ctor" << endl; }
    ~D() { cout << "D dtor" << endl; }
    D check (D a)
    {
        return a;
    }
};
class A
{
public:
    A() { cout << "A ctor" << endl; }
    ~A() { cout << "A dtor" << endl; }
};
class B : public A
{
public:
    B() { cout << "B ctor" << endl; }
    ~B() { cout << "B dtor" << endl; }
    void test(D d) { A a; }
};

int main()
{
;
}