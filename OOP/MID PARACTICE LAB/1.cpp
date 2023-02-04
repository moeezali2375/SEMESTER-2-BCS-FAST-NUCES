#include<iostream>
using namespace std;
class mybigint
{
    char *bigint;
    int length;
    public: 
    mybigint ()
    {
        length=0;
        bigint=nullptr;
    }
    mybigint(char *s)
    {
        // if (length>0)
        // delete[]bigint;
        length=strlen(s);
        bigint=new char [length];
        for (int i=0;i<length;i++)
        {
            bigint[i]=s[i];
        }
        bigint[length]='\0';
    }
    char& operator [](int a)
    {
        if (a>=0&&a<=length)
        {
            return bigint[a];
        }
        return bigint[0];
    }
    
    friend ostream& operator<<(ostream& ,mybigint a);
};
ostream& operator<<(ostream& out,mybigint a)
{
    out<<a.bigint<<endl;
    return out;
}

int main ()
{
    char s[]={"123456789"};
    mybigint bigint(s);
    bigint[3]='9';
    cout<<bigint;
}