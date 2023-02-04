// C++ program to explain
// Single inheritance
#include <iostream>
using namespace std;

// base class
class Vehicle
{
protected:
    int a, b, d;

public:
    Vehicle()
    {
        cout << " parent : This is a Vehicle\n";
    }
    Vehicle(int r, int t, int v)
    {
        cout << " parent : This is a Vehicle Constructor Partemeterized\n";
        this->a = r;
        this->b = t;
        this->d = v;
    }
    ~Vehicle()
    {
        cout << "parent destroyed" << endl;
    }
};

// sub class derived from a single base classes
class Car : public Vehicle
{
    int c;

public:
    Car()
    {
        cout << " child :  Im car " << endl;
    }
    // Important
    /* Car(int a ,int b ,int c,int e)
     {
         Vehicle(a, b ,e);
         this->c = c;
     }*/
    Car(int c)
    {

        cout << " child :  Im car parameterized " << endl;
        this->c = c;
    }
    ~Car()
    {
        cout << " child destructor destroyed" << endl;
    }
    /*   void display()
       {
          // display_V();
           cout << " c is  " << c << endl;
       }*/
};

// main function
int main()
{
    // Creating object of sub class will
    // invoke the constructor of base classes
    Vehicle v(1, 2, 3);
    Car c(6);
    //     Car obj(2,3,7,4);
    //   c.display();
    return 0;
}