#include<iostream>
using namespace std;
int main ()
{
    int r,c;
    cin>>r>>c;
    int**m;
    m=new int*[r];
    cout<<"chala ja";
    for (int i=0;i<c;i++)
    {
        *(m+i)=new int [c];
    }
    //INITIALIZES AN ARRAY
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            cin>>m[i][j];
            //cin>>*(*(m+i)+j);
        }
    }
    //INPUTS DATA
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            cout<<m[i][j];
            //cin>>*(*(m+i)+j);
        }
        cout<<endl;
    }
    //PRINTS DATA


}