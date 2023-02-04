#include <iostream>
using namespace std;
class mystring
{
    char *str;
    int length;

public:
    mystring()
    {
        ;
    }
    mystring(const char *a)
    {
        int i = 0;
        length = strlen(a);
        str = new char(length + 1);
        for (i = 0; i <= length; i++)
        {
            str[i] = a[i];
        }
        str[length + 1] = '\0';
    }
    mystring(const mystring &a)
    {
        if (length > 0)
            delete[] this->str;
        length = a.length;
        this->str = new char(length + 1);
        for (int i = 0; i < length; i++)
        {
            this->str[i] = a.str[i];
        }
        this->str[length + 1] = '\0';
    }
    int getlength()
    {
        return length;
    }
    ~mystring()
    {
        if (length > 0)
            delete[] str;
    }
    mystring operator++()
    {
        for (int i = 0; i < length; i++)
        {
            if (this->str[i] >= 'a' && this->str[i] <= 'z')
            {
                this->str[i] -= 32;
            }
        }
        return *this;
    }
    mystring operator = (mystring a)
    {
        if (this->length>0)
        delete[]str;
        length=a.length;
        str=new char [length+1];
        for (int i=0;i<=length;i++)
        {
            str[i]=a.str[i];
        }
        str[length+1]='\0';
        return *this;
    }
    char operator [](int i)
    {
        char a;
        if (i>=0&&i<=length)
        {
            a=str[i];
        }
        return a;
    }
    
    friend istream &operator>>(istream &in, mystring &a);
    friend ostream &operator<<(ostream &out, mystring a);

};
ostream &operator<<(ostream &out, mystring a)
{
    out << a.str << endl;
    return out;
}
istream &operator>>(istream &in, mystring &a)
{
    cout<<"Enter the string!"<<endl;
    char b[10000];
    cin.getline(b,10000);
    if (a.length>0)
    delete[]a.str;
    a.length =strlen(b);
    a.str=new char [a.length+1];
    for (int i=0;i<a.length+1;i++)
    {
        a.str[i]=b[i];
    }
    a.str[a.length+1]='\0';
    return in;
}

int main()
{
    char array[] = "My name is: ";
    mystring a(array);
    cout << "The given string is: " << a;
    ++a;
    cout << "The string after increment is: " << a;
    mystring b;
    cin>>b;
    cout<<"The input string is: ";
    cout<<b;
    b=a;
    cout<<"The string after copying by operator is: "<<b;
    b[1]='a';
}