#include <iostream>
#include "shape.cpp"
using namespace std;
class square : public shape
{
    int area;
    int volume;
    public: 
    square()
    {
        cout << "Square() called " << endl;
    }
    ~square()
    {
        cout << "~Square() called " << endl;
    }
    void displaysquare()
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