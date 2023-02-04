#include <iostream>
using namespace std;
class A
{
    static int *ptr;
    int data;

public:
    A()
    {
        data = 10;
        ptr = 0;
    }
    static void Print()
    {
        if (ptr != 0)
            cout << "*ptr	=	" << *ptr << endl;
    }
    static void remove_memory()
    {
        delete[] ptr;
    }
};
int *A::ptr = new int(10);
void main()
{
    A::Print();
    A obj2;
    A::Print();
    A::remove_memory();
}