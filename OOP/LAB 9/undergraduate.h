#include<iostream>
#include"person.h"
using namespace std;
class student:public person 
{
    protected: 
    float cgpa;
    long rollnum;
};
class undergraduate:public student 
{
    
    char fypname [50];
    char s_name[50];
    public: 
    int getage()
    {
        return age;
    }
    void setcgpa (float a)
    {
        cgpa=a;
    }
    float getcgpa()
    {
        return cgpa;
    }
    char *getfypname()
    {
        return fypname;
    }
    void setfypname (char * a)
    {
        strcpy(fypname,a);
    }
    long getrollnum ()
    {
        return rollnum;
    }
    void setrollnum (long a)
    {
        rollnum =a;
    }
    char *super_name()
    {
        return s_name;
    }
    void sets_name (char * a)
    {
        strcpy(s_name,a);
    }


};
class graduate :public student 
{
    char theisistopic[50];
    char s_name[50];
    public:
    int getage()
    {
        return age;
    }
    void setcgpa (float a)
    {
        cgpa=a;
    }
    float getcgpa()
    {
        return cgpa;
    }
    char* gettheisistopic()
    {
        return theisistopic; 
    }
    void settheisistopic(char *a)
    {
        strcpy(theisistopic,a);
    }
    long getrollnum ()
    {
        return rollnum;
    }
    void setrollnum (long a)
    {
        rollnum =a;
    }
    char *super_name()
    {
        return s_name;
    }
    void sets_name (char * a)
    {
        strcpy(s_name,a);
    }
};