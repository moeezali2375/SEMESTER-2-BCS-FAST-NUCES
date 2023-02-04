#include <iostream>
using namespace std;
class fraction
{
private:
    int num;
    int denum;

public:
    void outputfraction()
    {
        cout << num << "/" << denum << endl;
    }
    fraction();
    fraction(int, int);
    int gcd(int ele, int b);
    void simplify();
    fraction operator+(fraction f);
    fraction& operator++();
    fraction operator++(int);
    fraction operator+(int a);
    void operator+=(fraction f);
    bool operator<=(fraction f);
};
fraction::fraction()
{
    num = 0;
    denum = 1;
}
fraction::fraction(int a, int b)
{
    num = a;
    denum = b;
}
fraction fraction::operator+(fraction f)
{
    fraction res;
    res.denum = denum * f.denum;
    res.num = num * f.denum + denum * f.num;
    return res;
}
fraction fraction ::operator+(int a)
{
    fraction f(a, 1);
    return (*this) + f;
}
void fraction ::operator+=(fraction f)
{
    // fraction res;
    // res=(*this)+f;
    // (*this)=res;
    (*this) = (*this) + f;
}
bool fraction:: operator<=(fraction f)
{
    float a=num;
    float b=denum;
    float temp=a/b;
    float c=f.num;
    float d=f.denum;
    float temp2=a/b;
    if (temp<=temp2)
    return true;
    else return false;
}

int fraction :: gcd(int ele, int b)
{
    int gcd;
    if (ele < b)
    {
        for (int i = 1; i <= ele; i++)
        {
            if (ele % i == 0 && b % i == 0)
                gcd = i;
        }
    }

    if (b <= ele)
    {
        for (int i = 1; i <= b; i++)
        {
            if (ele % i == 0 && b % i == 0)
                gcd = i;
        }
    }

    return gcd;
}
void fraction::simplify()
{
    // fraction rs;
    int ele = gcd(num, denum);
    denum = denum / ele;
    num = num / ele;
}
fraction fraction ::operator++(int) // POST INCREMENT
{
    fraction temp = (*this);    //This copies original value to a temporary variable
    *this = *this + 1;          //This increases the original value
    return temp;                // This returns the non increased value to the current variable
}
fraction& fraction ::operator++() //& changes the value for original collar object while returning only defines value for current variable
{
    *this = *this + 1;
    return *this;
}
int main()
{
    fraction f1, f2(2, 3), f3(6, 9);
    f2.outputfraction();
    f1=++f2;
    f1.outputfraction();
    f2.outputfraction();
    // f1 = f2 + f3;
    // f1.outputfraction();
    // f3 += f2;
    // f3.outputfraction();
    // f3 = (f1++) + f2;
    // f3.outputfraction();
    // f3 = (++f1) + f2;
    // f3.outputfraction();
    // f1=f2.operator+(f3);
    // bool a;
    // a=f3<=f2;
    // cout<<a;
}