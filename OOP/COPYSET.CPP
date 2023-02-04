// THIS WILL DEEP COPY THE ELEMENTS OF THE ARRAY INTO ele NEW ARRAY I.E IT HAS ele NEW ADDRESS
// PROBLEM: PROBLEM IS WHENEVER ele FUNCTION ENDS THE CLASS IS DELETED AND THE ARRAY HAS ITS ADRESS PASSED TO ANOTHER ARRAY, SO DELETION OF THE PARENT ARRAY DELETE THE WHOLE ARRAY!
// SOLUTION://WHILE COPYING ELEMENTS WE HAVE 2 WYS EITHER WE CAN PASS BY REFERENCE OR WE CAN USE ele NEW IMPLICIT FUNCTION I.E. SET(SET &S)
// 2.SIMPLE CREATE ele  NEW ARRAY (CLASS ) AND USE THE NEWADDRESS SO THE VALUES CAN NOT BE DELETED
#include <iostream>
using namespace std;
class set
{
private:
    int size;
    int *ele;

public:
    set();
    set(int s);
    set(int *s, int n);
    ~set();
    set(set &s);
    void input();
    void output();
    void remove();
    set &operator +(set s);
    set &operator=(set s)
    {
        cout << "Assignment operator called!" << endl;
        if (size != s.size)
            delete[] ele;
        size = s.size;
        ele =new int [size];
        for (int i = 0; i < s.size; i++)
        {
            ele[i] = s.ele[i];
        }
        return *this;
    }
};
set::set()
{
    size = 0;
    ele = nullptr;
}
set::set(int s) // overloaded constructor
{
    size = s;
    ele = new int[size];
}
set::set(int *s, int n)
{
    size = n;
    ele = new int[size];
    for (int i = 0; i < size; i++)
    {
        ele[i] = s[i];
    }
}
void set::output()
{
    cout << "The size is: " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ele[i] << "\t";
    }
    cout << endl;
}

void set::remove()
{
    if (size > 0)
    {
        delete[] ele;
        size = 0;
        ele = nullptr;
    }
}
set::set(set &s) // DEEP COPY UIHUIHUIHUIHUIHUI
{
    cout << "Copy constructor called!" << endl;
    size = s.size;
    ele =new int [size];
    for (int i = 0; i < s.size; i++)
    {
        ele[i] = s.ele[i];
    }
}
set &set:: operator+ (set s)
{
    for (int i=0;i<size;i++)
    {
        ele[i]+=s.ele[i];
    }
    return *this;
}
set::~set() // destructor
{
    remove();
}
void set::input()
{
    cout << "Enter the values for: ";
    for (int i = 0; i < size; i++)
    {
        cin >> ele[i];
    }
}
// DEFAULT CONSTRUCTOR AND DESTRUCTOR IS CALLED AUTOMATICALLY AND IT IS NOT WRITTEN I.E. IT IS CALLED IMPLICITLY WHENEVE ele FUNCTION ENDS
int main()
{
    set s1(2);
    s1.input();
    set s2;
    s1.output();
    s2=s1;
    set s3;
    s3=s2+s1;
}