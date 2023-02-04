#include <iostream>
using namespace std;
class A
{
    int a;

public:
    A() : a(0)
    {
        cout << "A()" << endl;
    }
    A(int a) : a(a)
    {
        cout << "A(int a)" << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
    void print()
    {
        cout << "a=" << a << endl;
    }
    void seta(int a)
    {
        this->a = a;
        cout << "seta(int a)" << endl;
    }

protected:
    void prot_func_A()
    {
        cout << "prot_func_A()from A" << endl;
    }
};
class B : protected A
{
    int b;

public:
    B() : b(0)
    {
        cout << "B()";
    }
    B(int b, int a = 0) : b(b)
    {
        cout << "B(intb, inta=0)" << endl;
        seta(a);
    }
    ~B()
    {
        cout << "~B()" << endl;
    }
    void print()
    {
        cout << "b=" << b << endl;
        A::print();
    }
    void prot_func_A()
    {
        cout << "prot_func_A() fromB" << endl;
    }
};
int main()
{
    B objB(10, 20);
    objB.print();
    objB.prot_func_A();
}