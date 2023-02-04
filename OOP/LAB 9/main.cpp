#include<iostream>
#include "undergraduate.h"
using namespace std;
int main ()
{
    graduate a;
    char fname[20];
    cout<<"Enter the first name: ";
    cin.getline(fname,20);
    a.setfname(fname);
    char lname[20];
    cout<<"Enter the last name: ";
    cin.getline(lname,20);
    a.setlname(lname);
    int aa;
    cout<< "Enter the age: ";
    cin>>aa;
    a.setage(aa);
    float g;
    cout<<"Enter the cgpa of the student: ";
    cin>>g;
    a.setcgpa(g);
    char topic [50];
    cout<<"Enter the theisis topic name: ";
    cin.getline(topic,50);
    a.settheisistopic(topic);
    char supervisor[50];
    cout<<"Enter the supervisor name: ";
    cin.getline(supervisor,50);
    a.sets_name
}