#include <iostream>
using namespace std;

void function_B(int *&p, int *q)
{
    q = new int;
    *q = *p - 100;
    *p = *q - 100;
    delete q;
}
void function_A(int *p, int *&q)
{
    p = new int;
    *p = *q + 100;
    *q = *p + 100; //q=800
    function_B(p, q);
    delete p;
}
int main()
{
    int x = 1000;
    int *ptr1 = &x;
    int *ptr2 = new int[0];
    *ptr2 = 600;
    
    cout << *ptr1 << " " << *ptr2 << endl;
    function_A(ptr1, ptr2);
    cout << *ptr1 << " " << *ptr2 << endl;
    function_B(ptr1, ptr2);
    cout << *ptr1 << " " << *ptr2;
    delete ptr2;
    return 0;
}