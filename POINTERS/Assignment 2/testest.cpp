#include<iostream>
using namespace std;
int *growarray(int *a,int &size)
{
    int *temp;
    temp=new int [size+1];
    for (int i=0;i<size;i++)
    {
        temp [i]=a[i];
    }
    delete []a;
    a=nullptr;
    size++;
    return temp;
}
int main ()
{
    int *a;
    int size=2;
    a=new int [2];
    a[0]=1;
    a[1]=2;
    a=growarray(a,size);
    cout<<size<<endl;
    
}
