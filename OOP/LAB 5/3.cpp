#include <iostream>
using namespace std;
class rectangle
{
    int length;
    int breadth;

public:
    rectangle()
    {
        length = 0;
        breadth = 0;
    }
    rectangle (int ele,int b)
    {
        length=ele;
        breadth=b;
    }
    rectangle(int ele)
    {
        length=ele;
        breadth=ele;
    }
    int area(rectangle)
    {
        int temp=length*breadth;
        return temp;
    }
};
int main()
{
    int a1=5,b1=2;
    int a2=10;
    rectangle r0,r1(a1,b1),r2(a2);
    int temp=0;
    cout<<"The area of the first constructor is: "<<r0.area(r0)<<endl;
    cout<<"The area of the first constructor is: "<<r1.area(r1)<<endl;
    cout<<"The area of the first constructor is: "<<r2.area(r2)<<endl;
    

}