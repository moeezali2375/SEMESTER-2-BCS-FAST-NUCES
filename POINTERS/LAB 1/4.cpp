#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cout << "Please enter the first number: ";cin>>a;
    cout << "Please enter the second number: ";cin>>b;
    int *a1=&a,*a2=&b;
    cout<<"The sum of the numbers is: "<<*a1+*a2<<endl;
    cout<<"The subtraction of the numbers is: "<<*a1-*a2<<endl;
    cout<<"The product of the numbers is: "<<*a1**a2<<endl;
    cout<<"The square of the numbers is: "<<*a1**a1<<","<<*a2**a2<<endl;

}
