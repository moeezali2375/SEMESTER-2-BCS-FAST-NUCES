#include <iostream>
using namespace std;
class point
{
    friend class circle;
    int x, y;

public:
    point()
    {
        x = y = 0;
    }
    point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void printpoint()
    {
        cout << "(" << x << "," << y << ")";
    }
};
class circle
{
    float radius;
    point center;

public:
    circle()
    {
        radius=0;
    }

    circle (int x,int y, float r):center (x,y)                      //Member initializer list
    {
        radius=r;
        
    }
    void printcircle()
    {
        cout << "Radius: " << radius<<endl;
        cout << "Center: "
             << "(" << center.x << "," << center.y << ")"<<endl;
        // center.printpoint();
    }
};

int main()
{
    circle c;
    c.printcircle();
    circle c1(2,3,4);
    c1.printcircle();
}