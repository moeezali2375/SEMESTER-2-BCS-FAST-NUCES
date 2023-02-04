#include <iostream>
using namespace std;
class A
{
public:
    A() { cout << "In A’s constructor" << endl; }
    ~A() { cout << "In A’s destructor" << endl; }
};
class B : public A
{
public:
    B() { cout << "In B’s constructor" << endl; }
    ~B() { cout << "In B’s destructor" << endl; }
};
class C : public B
{
public:
    C() { cout << "In C’s constructor"
               << endl; }
    ~C() { cout << "In C’s destructor"
                << endl; }
};
int main()
{
    // C x1;
    // C *x2 = new C;
    char c = 'A';
    char *p = &c;
    char **p2 = &p;
    
}