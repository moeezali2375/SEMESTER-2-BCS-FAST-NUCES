#include <iostream>
using namespace std;

class Base
{
private:
    int a;

public:
    Base(int a = 0)
    {
        this->a = a;
    }
    void base_setter(int a)
    {
        this->a = a;
    }
};

class derived : public Base
{
    int b;

public:
    derived(int b = 0)
    {
        this->b = b;
    }
    void setter(int base, int derive)
    {
        b = derive;
        // a = base;
        Base::base_setter(base);
    }
};

class PUBLIC
{
    Base public_base;

public:
    PUBLIC()
    {
        ;
    }
    void public_setter(int a_public)
    {
        public_base.a = a_public;
    }
};
int main()
{
    Base base;
    cout << "Hello" << endl;
}