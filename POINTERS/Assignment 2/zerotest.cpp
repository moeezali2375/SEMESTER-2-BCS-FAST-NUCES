#include<iostream>
using namespace std;
int main ()
{
    int *a;
    a=new int [5];
    for (int i =0;i<5;i++)
    {
        cout<<a[i];
    }
}