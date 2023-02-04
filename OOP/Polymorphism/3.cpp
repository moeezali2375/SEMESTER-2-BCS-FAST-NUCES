#include <iostream>
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
        cout << "Date is: " << day << '/' << month << '/' << year;
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
    virtual void print() // VIRTUAL KEYWORD WILL ALLOW THE BASE POINTER TO  CALL SALARIED PRINT FUNCTION
    {
        cout << "Emp name: " << name << " ";
        cout << "Emp Designation: " << name << " ";
        cout << "Date of joining: ";
        DOJ.display();
        cout << " ";
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
    salaried_emp(char *n, char *d, date dat, int s) : emp(n, d, dat)
    {
        salary = s;
    }
};
void salaried_emp::print() // in main the print function to be called is determined by the collar object
{
    emp::print();
    cout << "Salary is: " << salary << endl;
}
// HOURLY
class hourly_emp : public emp
{
    int hr;
    int rate;

public:
    void print()
    {
        cout << "Hourly Employee: " << endl;
        emp::print();
        cout << "Hours worked: " << hr << " ";
        cout << "Per Hour Rate: " << rate << endl;
    }
    hourly_emp(char *n, char *d, date dat,int h,int r):emp (n,d, dat)
    {
        hr=h;
        rate=r;
    }
};
// COMMISSIONED
class commissioned_emp : public emp
{
    int sales;
    float comm_rate;
};
int main()
{
    date d1(5, 5, 2009);
    date d2(3, 12, 2012);
    emp e1("ABC", "Manager", d1);
    salaried_emp e2("DEF", "Operator", d2, 25000);
    emp *employees[5];
    employees[0]=new salaried_emp("A","hui",d2,10);
    employees[1]=new hourly_emp ( "B","Hui",d1,6,9);
    employees[2]=new salaried_emp("A","hui",d2,100);
    employees[3]=new salaried_emp("A","hui",d2,1000);
    employees[4]=new hourly_emp("B","Hui",d1,9,6);
    for (int i=0;i<5;i++)
    {
        employees[i]->print ();            //As we have made the print function virtual! now the print function will be called according to the pointer at which is pointing 
    }
}

// Assignment operator, destructors, friends, constructors; are not inherited by default=