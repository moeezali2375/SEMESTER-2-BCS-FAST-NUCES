#include <iostream>
#include <string>
using namespace std;
////================================================================================================================================================================================================================================================================================================================================================================================================
//
//  ####      ###    ######  #####
//  ##  ##   ## ##     ##    ##
//  ##  ##  ##   ##    ##    #####
//  ##  ##  #######    ##    ##
//  ####    ##   ##    ##    #####
//
//================================================================================================================================================================================================================================================================================================================================================================================================

class date
{
    int day, month, year;

public:
    date()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    date(const int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    ~date()
    {
        ;
    }
    void display()
    {
        cout << "Date is: " << day << '/' << month << '/' << year ;
    }
};
////===========================================================================================================================================================================================================================================================================================================================================================================================
//
//  #####  ###    ###  #####
//  ##     ## #  # ##  ##  ##
//  #####  ##  ##  ##  #####
//  ##     ##      ##  ##
//  #####  ##      ##  ##
//
//===========================================================================================================================================================================================================================================================================================================================================================================================

class emp
{
    // We can use protected to give acccess from parent class to child class

    // protected:
    char *name;
    char *des;
    date DOJ;

public:
    void print()
    {
        cout << "Emp name: " << name<<" ";
        cout << "Emp Designation: " << name<<" ";
        cout << "Date of joining: ";
        DOJ.display();
        cout<<" ";
    }
    emp()
    {
        name = des = nullptr;
    }
    emp(char *n, char *d, date dat) : DOJ(dat) // Member initialser list
    {
        name = new char[strlen(n) + 1];
        des = new char[strlen(d) + 1];
        strcpy(name, n);
        strcpy(des, d);
    }
};
// SALARY
class salaried_emp : public emp
{
    int salary;

public:
    void print();
    salaried_emp(char *n, char *d, date dat, int s):emp(n,d,dat)
    {
        salary = s;

    }
};
void salaried_emp::print() // in main the print function to be called is determined by the collar object
{
    emp::print();
    cout << "Salary is: " << salary<<endl;
}
// HOURLY
class hourly_emp : public emp
{
    int hr;
    int rate;
};
// COMMISSIONED
class commissioned_emp : public emp
{
    int sales;
    float comm_rate;
};
int main()
{
    date d1 (5,5,2009);
    date d2 (3,12,2012);
    emp e1("ABC","Manager",d1);                     //13->17
    salaried_emp e2("DEF","Operator",d2,25000);    //17
    e1.print();
    e2.print();
    emp *eptr;
    salaried_emp *septr;
    eptr=&e1;
    septr=&e2;          //Everything is OK till now!
    eptr=&e2;           //Good here beacause we can assign address of child class to base class pointer and this will have only access to base members! 

    //septr=&e1;          //Not good here because we are assigning a child pointer to base's address
    eptr->print();
    //eptr->getsalary();      //NOT GOOD because the pointer has access to members of only base class
}

// Assignment operator, destructors, friends, constructors; are not inherited by default=