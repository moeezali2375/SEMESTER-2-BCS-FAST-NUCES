#include <iostream>
using namespace std;
class person
{
    string fullname;
    int height;

public:
    person()
    {
        ;
    }
    person(string name, int height)
    {
        fullname = name;
        this->height = height;
    }
    virtual void printinfo()
    {
        cout << "The fullname is: " << fullname << endl;
        cout << "The height is: " << height << endl;
    }
    ~person()
    {
        cout << "Person destructor called!" << endl;
    }
};
class employee : public person
{
    string department;
    int id;

public:
    employee(string name, int height, string department, int id) : person(name, height)
    {
        this->department = department;
        this->id = id;
    }
    void printinfo()
    {
        person::printinfo();
        cout << "Department is: " << department << endl;
        cout << "ID is: " << id << endl;
    }
    ~employee()
    {
        cout << "Employee destructor called!" << endl;
    }
};
class student : public person
{
    string schoolname;

public:
    student(string name, int height, string schoolname) : person(name, height)
    {
        this->schoolname = schoolname;
    }
    void printinfo()
    {

        person::printinfo();
        cout << "The school name is: " << schoolname << endl;
    }
};
int main()
{
    person *a[2];
    a[0] = new employee("moeez", 5, "CS", 1798);
    a[1] = new student("moeez", 5, "LPS");
    for (int i = 0; i < 2; i++)
    {
        a[i]->printinfo();
        delete a[i];
    }
    
}