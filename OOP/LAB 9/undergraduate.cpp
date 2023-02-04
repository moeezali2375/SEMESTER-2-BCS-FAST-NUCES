#include<iostream>
#include"person.h"
using namespace std;
class student:public person 
{
    float cgpa;
    long rollnum;
};
class undergraduate:public student 
{
    
    char fypname [50];
    char s_name[50];
};
class graduate :public student 
{
    char theisistopic[50];
    char s_name[50];
};