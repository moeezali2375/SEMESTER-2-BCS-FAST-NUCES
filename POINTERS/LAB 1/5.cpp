#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cout << "Please enter the length of the rectangle: ";cin>>a;
    cout << "Please enter the width of the rectangle: ";cin>>b;
    int *a1=&a,*a2=&b;
    cout<<"the area is: "<<*a1**a2;
}

