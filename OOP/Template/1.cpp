#include <iostream>
#include "jbh.cpp"
using namespace std;
template <typename T>
T swapp(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
    return 0;
}

int main()
{
    fraction f1(3, 2), f2(5, 9), f3(7, 4);
    // fraction far[3] = {f1, f2, f3};
    // double darr[5] = {2.3, 4.8, 12.3, 7.0, 9.2};
    float a = 10;
    float b = 20;
    cout << "a" << a << " "
         << "b" << b << endl;
    swapp(a, b);
    cout << "a" << a << " "
         << "b" << b << endl;
        
}
