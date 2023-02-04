#include<iostream>
using namespace std;
int ** allocatemem(int &r,int &c)
{
    cin>>r>>c;
    int**m;
    m=new int*[r];
    for (int i=0;i<c;i++)
    {
        
        *(m+i)=new int [c];
    }
    return m;
}
void inputmatrix (int ** m,int r,int c)
{
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            cin>>m[i][j];
        }
    }
}
void deallocate(int **m,int r,int c)
{
    for (int i=0;i<r;i++)
    delete []m[i];
    delete []m;
}
int main ()
{
    int **m1,r,c;
    m1=allocatemem(r,c);
    inputmatrix(m1,r,c);
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            cout<<m1[i][j];
            //cin>>*(*(m+i)+j);
        }
        cout<<endl;
    }
    deallocate (m1,r,c);


}