#include <iostream>
#include "point.h"
using namespace std;
class circle
{
    float radius;
    point center;
public:
    circle(int x, int y, float r) : center(x, y)
    {
        radius = r;
        cout<<"Circle () called!"<<endl;
    }
    void printcircle()
    {
        cout << "Radius: " << radius<<endl;
        cout << "Center: "
             << "(" << center.x << "," << center.y << ")"<<endl;
        // center.printpoint();
    }
    ~circle()
    {
        cout<<"~Circle () called!"<<endl;
    }
};