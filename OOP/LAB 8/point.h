#include<iostream>
using namespace std;

class point
{
    int x;
    int y;
    friend class circle;

public:
    point(int a, int b)
    {
        x = a;
        y = b;
        cout<<"Point() called!"<<endl;
    }
    void print ()
    {
        cout<<"("<<x<<','<<y<<')'<<endl;
    }
    ~point ()
    {
        cout<<"~Point() called!"<<endl;
    }


};