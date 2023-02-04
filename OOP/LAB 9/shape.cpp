#include<iostream>
using namespace std;
class shape 
{
    int l,w;
    public:
    shape ()
    {
        cout<<"Shape() called!"<<endl;
    }
    ~shape ()
    {
        cout<<"~Shape() called!"<<endl;
    }
    void set1(int a)
    {
        l=a;
    }
    void set2(int a)
    {
        w=a;
    }
    int get1()
    {
        return l;
    }
    int get2 ()
    {
        return w;
    }
};