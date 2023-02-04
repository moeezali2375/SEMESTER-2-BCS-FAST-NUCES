#include <iostream>
#include "shape.cpp"
using namespace std;
class rectangle : public shape
{
    int area, volume;

public:
    rectangle()
    {
        cout << "rectangle () called" << endl;
    }
    ~rectangle()
    {
        cout << "~Rectangle () called " << endl;
    }
    void displayrectangle()
    {
        cout << "The length is: " << get1() << endl;
        cout << "The width is: " << get2() << endl;
    }
    void displayarea()
    {
        cout << "The area is: " << area << endl;
    }
    void displayvolume()
    {
        cout << "The volume is: " << volume << endl;
    }
};