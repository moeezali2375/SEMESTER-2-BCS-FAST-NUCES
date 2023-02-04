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
    set(set &s);
    ~set();
    void input();
    void output();
    void remove();
    set* intersecton(set s);
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
set::set(set &s) // DEEP COPY UIHUIHUIHUIHUIHUI
{
    size = s.size;
    ele =new int [size];
    for (int i = 0; i < s.size; i++)
    {
        ele[i] = s.ele[i];
    }
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
set::~set() // destructor
{
    remove();
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
void set::input()
{
    cout << "Enter the values for: ";
    for (int i = 0; i < size; i++)
    {
        cin >> ele[i];
    }
}
// DEFAULT CONSTRUCTOR AND DESTRUCTOR IS CALLED AUTOMATICALLY AND IT IS NOT WRITTEN I.E. IT IS CALLED IMPLICITLY WHENEVE ele FUNCTION ENDS
set* set::intersecton(set s)
{
    int count = 0,k,i,j;
    for ( i = 0; i < size; i++)
    {
        for (j = 0; j < s.size; j++)
        {
            if (ele[i] == s.ele[j])
            {
                count++;
                break;
            }
        }
    }
    set *sptr=nullptr;
    sptr = new set(count);
    k = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < s.size; j++)
        {
            if (ele[i] == s.ele[j])
            {
                sptr->ele[k++] = ele[i];
                break;
            }
        }
    }
    return sptr;
}

int main()
{
    set s1, s2(3), s3(2);
    set *sp=&s1;
    s2.input();
    s3.input();
    s2.output();
    s3.output();
    sp=s2.intersecton(s3);
    cout<<"The intersection is as follows: "<<endl;
    sp->output();
}