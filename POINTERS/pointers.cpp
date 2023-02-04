#include<iostream>
using namespace std;
int main ()
{
    int *p={nullptr};
    int tobepointed={10};
    cout<<"Value: "<<tobepointed<<endl;
    p=&tobepointed;
    cout<<p;
    return 0;
}