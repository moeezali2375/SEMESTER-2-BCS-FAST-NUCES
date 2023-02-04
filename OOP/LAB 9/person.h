#include<iostream>
using namespace std;
class person 
{
    char firstname[50];
    char lastname[50];
    protected: 
    int age;
    public: 
    void setfname(char *a)
    {
        strcpy(firstname,a);
    }
    void setlname(char *a)
    {
        strcpy(lastname,a);
    }
    void setage (int a)
    {
        age=a;
    }
    void displayperson()
    {
        cout<<"The first name is: "<<firstname<<endl;
        cout<<"The last name is: "<<lastname<<endl;
        cout<<"The age is: "<<age<<endl;
    }
};