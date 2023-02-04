#include <iostream>
using namespace std;
int main()
{
    int a=10,b=15,c=12;
    int *a1=&a,*a2=&b,*a3=&c;
    cout<<"the mean of given integers is:  "<<(*a1+*a2+*a3)/3;
}