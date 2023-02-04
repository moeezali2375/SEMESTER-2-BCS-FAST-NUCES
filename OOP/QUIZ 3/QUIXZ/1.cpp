#include <iostream>
#include <string>
using namespace std;
class Students
{
protected:
    string name;
    string idNumber;
    int yearAdmitted;

public:
    Students()
    {
        yearAdmitted = 0;
    }
    Students(string n, string id, int year)
    {
        set(n, id, year);
    }
    void set(string n, string id, int year)
    {
        name = n;
        idNumber = id;
        yearAdmitted = year;
    }
    string getname()
    {
        return name;
    }
    string getid()
    {
        return idNumber;
    }
    int getyear()
    {
        return yearAdmitted;
    }
    virtual int getRemaininghours()
    {
        return 0;
    }
};
class CsStudent : public Students
{
    int mathHours;
    int csHours;
    int genEdHours;

public:
    CsStudent() : Students()
    {
        mathHours = 0;
        csHours = 0;
        genEdHours = 0;
    }
    CsStudent(string n, string id, int year) : Students(n, id, year)
    {
        mathHours = 0;
        csHours = 0;
        genEdHours = 0;
    }
    void set_math(int h)
    {
        mathHours = h;
    }
    void set_cs(int h)
    {
        csHours = h;
    }
    void set_gen(int h)
    {
        genEdHours = h;
    }
    int get_math()
    {
        return mathHours;
    }
    int get_cs()
    {
        return csHours;
    }
    int get_gen()
    {
        return genEdHours;
    }
    virtual int getRemaininghours()
    {
        return 20 - get_math() + 40 - get_cs() + 60 - get_gen();
    }
};
int main()
{
    CsStudent student("Jennifer Haynes", "167W98337", 2006);
    student.set_math(12);
    student.set_cs(20);
    student.set_gen(40);
    cout << "The student " << student.getname() << " needs to take " << student.getRemaininghours() << " more hours to graduate\n";

    return 0;
}