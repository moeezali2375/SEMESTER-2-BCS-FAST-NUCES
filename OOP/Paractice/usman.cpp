#include <iostream>
using namespace std;
class fraction
{
    int num, denum;
public:
    fraction(int num, int denum)
    {
        this->num = num;
        this->denum = denum;
    }
    void output()
    {
        cout<<num<<'/'<<denum<<endl;
    }
    fraction operator =(fraction f)
    {
        this->num=f.num;
        this->denum=f.denum;
        return *this;
    }
    fraction operator +(fraction f)
    {
        this->num+=f.num;
        this->denum+=f.denum;
        return *this;
    }
    friend ostream& operator<<(ostream& out,fraction f);
    
};
ostream& operator<<(ostream & out,fraction f)
{
    out<<f.num<<'/'<<f.denum<<endl;
    return out;
}

int main()
{
    fraction f1(2,3);
    fraction f2(3,8);
 //   f1.output();
    cout<<f1+f2;
}