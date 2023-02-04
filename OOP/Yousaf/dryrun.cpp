#include <iostream>
using namespace std;
class base
{
public:
    base()
    {
        cout << "Base constructor called!" << endl;
    }
    ~base()
    {
        cout << "Base destructor called!" << endl;
    }
};
class derived : public base
{
public:
    derived()
    {
        cout << "Derived constructor called!" << endl;
    }
    ~derived()
    {
        cout << "Derived Destructor called" << endl;
    }
};
int main()
{
    derived a;
    cout << "Huihui" << endl;
}