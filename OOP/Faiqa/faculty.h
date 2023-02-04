
#include <iostream>
using namespace std;
class faculty
{
private:
    char *name;
    char *department;
    int *experience;
    int *salary;
    int *faculty_code;

public:
    int get_experience()
    {
        return *experience;
    }
    faculty()
    {
        name = nullptr;
        faculty_code = nullptr;
        department = nullptr;
        experience = nullptr;
        salary = nullptr;
    }
    faculty(faculty &f)
    {
        cout<<"Copy constructor called"<<endl;
        name = new char[15];
        department = new char[15];
        faculty_code = new int;
        salary = new int;
        experience = new int;
        for (int i = 0; i < 15; i++)
        {
            name[i] = f.name[i];
        }
        for (int i = 0; i < 15; i++)
        {
            department[i] = f.department[i];
        }
        salary = f.salary;
        experience = f.experience;
        faculty_code = f.faculty_code;
    }
    void operator=(const faculty &f)
    {
        if (name != nullptr)
            delete[] name;
        name = new char[15];
        if (department != nullptr)
            delete[] department;
        department = new char[15];
        if (faculty_code != nullptr)
            delete faculty_code;
        faculty_code = new int;
        if (salary != nullptr)
            delete salary;
        salary = new int;
        if (experience != nullptr)
            delete experience;
        experience = new int;
        for (int i = 0; i < 15; i++)
        {
            name[i] = f.name[i];
        }
        for (int i = 0; i < 15; i++)
        {
            department[i] = f.department[i];
        }
        salary = f.salary;
        experience = f.experience;
        faculty_code = f.faculty_code;
    }
    friend istream &operator>>(istream &in, faculty &f1)
    {
        f1.name = new char[15];
        f1.department = new char[15];
        f1.faculty_code = new int;
        f1.salary = new int;
        f1.experience = new int;
        cout << "Enter name :" << endl;
        in >> f1.name;
        cout << "Enter department :" << endl;
        in >> f1.department;
        cout << "Enter experience :" << endl;
        in >> *f1.experience;
        cout << "Enter faculty code :" << endl;
        in >> *f1.faculty_code;
        cout << "Enter salary :" << endl;
        in >> *f1.salary;
        return in;
    }
    friend ostream &operator<<(ostream &out, const faculty &f1)
    {
        out << "Name " << endl;
        out << f1.name << endl;
        out << "Department " << endl;
        out << f1.department << endl;
        out << " experience " << endl;
        out << *f1.experience << endl;
        out << "salary" << endl;
        out << *f1.salary << endl;
        out << "faculty_code" << endl;
        out << *f1.faculty_code << endl;
        return out;
    }
};