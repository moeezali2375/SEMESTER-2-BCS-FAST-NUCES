#include <iostream>
using namespace std;
class student
{
private:
    int r;
    char name[100];
    long int c;
    char d[100];
    char ele[100];

public:
    void input()
    {
        cout << "Enter your roll number: ";
        cin >> r;
        cin.ignore();
        cout << "Enter your name: ";
        cin.getline(name, 100);
        cout << "Enter your CNIC: ";
        cin >> c;
        cin.ignore();
        cout << "Enter your Degree: ";
        cin.getline(d, 100);
        cout << "Enter your Address: ";
        cin.getline(ele, 100);
    }
    void print()
    {
        cout << "Your roll number is: " << r << endl;
        cout << "Your Name is: " << name << endl;
        cout << "Your CNIC is: " << c << endl;
        cout << "Your Degree is: " << d << endl;
        cout << "Your Address is: " << ele << endl;
    }
};
int main()
{
    student s1;
    s1.input();
    s1.print();
}