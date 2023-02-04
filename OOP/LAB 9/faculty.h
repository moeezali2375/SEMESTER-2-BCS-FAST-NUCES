#include<iostream>
#include"person.h"
using namespace std;
class faculty:public person
{
    int count;
    char num[4];
    public:
    int getage()
    {
        return age;
    }
    int getcount()
    {
        return count;
    }
    char* getnum()
    {
        return num;
    }
    void setcount(int a)
    {
        count =a;
    }
    void setnum(char *a)
    {
        strcpy(num,a);
    }              


};