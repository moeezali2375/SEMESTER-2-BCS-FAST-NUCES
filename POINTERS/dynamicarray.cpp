#include <iostream>
using namespace std;
int * input1(int &size)
{
    cout<<"phli array ka size dalyo: ";
    cin>>size;
    int *set=new int[size];
    for (int i =0;i<size;i++)
    {
        cin>>set[i];
    }
    return set;
}
int main()
{
    int *set1, *set2;
    int s1,s2;
    set1 = input1(s1);
    set2 = input1(s2);
}