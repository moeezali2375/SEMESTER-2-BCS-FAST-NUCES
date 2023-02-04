#include <iostream>
using namespace std;
class date 
{
    int day,month,year;
    public:
    date()
    {
        ;
    }
    date(const int d,int m,int y)
    {
        day=d;
        month=m;
        year=y;
        cout<<"date bazi";
    }
    ~date()
    {
        cout<<"DOB destructor called!"<<endl;
    }
    void display()
    {
        cout<<"Date is: "<<day<<'/'<<month<<'/'<<year<<endl;
    }
};
class student
{
    char *name;
    float cgpa;
    long rollnum;
    date DOB;

public:
    student()
    {
        name=nullptr;
        cgpa=0;
        rollnum=0;
    }
    student(const char n[], float c, long r, date d) : DOB(d)
    {   
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        cgpa = c;
        rollnum = r;
    }
    ~student()
    {
        cout<<"Student destructor called!"<<endl;
        if (name!=nullptr)
        {
            delete []name;
        }
        
    }
};
// class course
// {
//     char *name;
//     int code;
//     int size;
//     student **list;

// public:
//     course(int s)
//     {
//         list=new student *[s];
//         size=s;
//     }
//     course ()
//     {
//         if (size>0)
//         delete[]list;
//         cout<<"Course destructor called!"<<endl;
//     }
// };
date a (1,2,3);
int main()
{
    //cout<<"HELLO"<<endl;
    // student st;
    // date d(1,15,2005);
    // student *s;
    // s=&st;
    // date *d1=new date (1,2,4);
    // // // s=new student ("ABC",30,123,*d1);
    // // // delete s;
    // // d1->display();
    // delete d1;

}
//deletion order: First of all main function objects will be deleted in reverse order i.e objects in the last will be delete first!
//if there is a bigger class then bigger class will be deleted first then the smaller class will delete.
