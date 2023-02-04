#include<iostream>
using namespace std;
int main ()
{
    int a=10;
    int b=20;
    int *p=&a,*q=&b;
    cout<<*p<<" "<<*q<<endl;
    int temp=*p;
    *p=*q;
    *q=temp;
    cout<<*p<<" "<<*q<<endl;


}
