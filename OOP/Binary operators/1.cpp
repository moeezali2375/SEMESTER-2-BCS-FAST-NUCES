#include <iostream>
#include"class.h"
using namespace std;
fraction operator+(int a,fraction f)
{
    fraction f1(a,1);
    return f1+f;
    //return f+a;
}
ostream & operator<<(ostream &out,fraction f)
{
    out<<f.num<<"/"<<f.denum;
    return out;
}
istream & operator>>(istream &in,fraction &f)           //Pass by reference so that the in can store the values
{
    char ch;
    in>>f.num;
    in>>ch;
    in>>f.denum;
    return in;
}
int main()
{
    fraction f1(2,3),f2;
    cout<<f1<<endl;                //Heavy ho gya
    cout<<"enter the the numerator and denominators: "<<endl;
    cin>>f2;
    cout<<"the fraction is: "<<endl;
    cout<<f2;
}