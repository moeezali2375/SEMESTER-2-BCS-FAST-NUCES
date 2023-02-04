#include<iostream>
using namespace std;
int main ()
{
    int array[3]={1,2,3};
    int *ptr =array;

    cout<<"The elements of array are : ";

    for (int i=0;i<3;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;

    cout<<"The address of array is: "<<array<<endl;
    cout<<"The address of array from pointer is: "<<ptr<<endl;
    cout<<"the first element of array is: (subscript) "<<array[0]<<endl;
    cout<<"the first element of array is: (offset) "<<*array+0<<endl;

}