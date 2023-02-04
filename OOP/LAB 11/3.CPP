#include <iostream>
using namespace std;
class shape
{
public:
    virtual void rectanglearea(int a, int b) = 0;
    virtual void squarearea(int a) = 0;
    virtual void circlearea(float a) = 0;
};
class area : public shape
{
public:
    void rectanglearea(int a, int b)
    {
        cout<<"The area of rectangle is: "<<a*b<<endl;
    }
    void squarearea(int a)
    {
        cout<<"The area of square is: "<<a*a<<endl;
    }
    void circlearea (float a)
    {
        cout<<"The area of circle is: "<<a*a*22/7<<endl;
    }
};
int main()
{
    area huihui;
    huihui.squarearea(5);
    huihui.rectanglearea(5,4);
    huihui.circlearea(5);
    
}
