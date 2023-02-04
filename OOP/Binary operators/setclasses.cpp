#include <iostream>
using namespace std;

class set
{
private:
    int size;
    int *ele;
    const int a;
    const int b;

public:
    set();
    set(int s, int a_val, int b_val) : a(a_val), b(b_val)
    {
        ;
    }
    set(int *s, int n);
    set unions(set s);
    void output();
    void remove();
    set() : a(0), b(1)
    {
        size = 0;
        ele = nullptr;
    }
    set &operator=(set &right)
    {
        if (this != &right)
        {
            if (size > 0)
                delete[] ele;
            size = right.size;
            ele = new int[size];
            for (int i = 0; i < size; i++)
            {
                ele[i] = right.ele[i];
            }
        }
        return *this;
    }
};
set::set()
{
    size = 0;
    ele = nullptr;
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
void set::remove()
{
    if (size > 0)
    {
        delete[] ele;
    }
    size = 0;
    ele = nullptr;
}
void set::output()
{
    cout << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ele[i];
    }
    cout << endl;
}
set set::unions(set s)
{
    int length = size + s.size;
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < s.size; j++)
        {
            if (ele[i] == s.ele[j])
            {
                k++;
                break;
            }
        }
    }
    length -= k;
    set temp(length);
    k = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < s.size; j++)
        {
            if (ele[i] == s.ele[j])
            {
                temp.ele[k] = ele[i];
                k++;
                break;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        int flag = 0;
        for (int j = 0; j < s.size; j++)
        {
            if (ele[i] == s.ele[j])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            temp.ele[k] = ele[i];
            k++;
        }
    }
    for (int i = 0; i < s.size; i++)
    {
        int flag = 0;
        for (int j = 0; j < size; j++)
        {
            if (ele[j] == s.ele[i])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            temp.ele[k] = s.ele[i];
            k++;
        }
    }
    return temp;
}
