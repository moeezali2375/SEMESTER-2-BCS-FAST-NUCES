#include<iostream>
using namespace std;
int main ()
{
    int *array;
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    array=new int [size];
    for (int i=0;i<size;i++)
    {
        cin>>array[i];
    }
    for (int i=0;i<size;i++)
    {
        cout<<array[i]<<endl;
    }
    delete []array;
    cout<<"Hello mf: ";
}
