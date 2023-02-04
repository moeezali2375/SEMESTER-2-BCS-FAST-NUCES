#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Please enter the first number: ";
    cin >> a;
    cout << "Please enter the second number: ";
    cin >> b;
    cout << "Please enter the third number: ";
    cin >> c;
    int i=1,j=1;
    int *a1 = &a, *a2 = &b, *a3 = &c;
    int max=*a1;
    int min=*a2;
    if (max<=*a2)
    {
        max=*a2;
        i=2;
    }
    if (max<=*a3)
    {
        max=*a3;
        i=3;
    }
    if (min>=*a2)
    {
        min=*a2;
        j=2;

    }
    if (min>=*a3)
    {
        min=*a3;
        j=3;
    }

    cout<<i<<" is the largest number."<<endl;
    cout<<j<<" is the smallest number."<<endl;
        
}
