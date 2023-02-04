#include <iostream>
using namespace std;
class car
{
    char color[100];
    char name[100];
    int cubic, seats, year, engine, frame;
public:
    car ();
    car (car&);
    void set1(char name[]);
    void set2(char name[]);
    void set3(int a);
    void set4(int a);
    void set5(int a);
    void set6(int a);
    void set7(int a);
    char* get1()
    {
        return this->name;
    }
    char* get2()
    {
        return this->color;
    }
    int get3();
    int get4();
    int get5();
    int get6();
    int get7();
    void output();
};
car::car()
{
    cubic=0;
    seats=0;
    year=0;
    engine=0;
    frame=0;
    color[0]='\0';
    name[0]='\0';
}
car:: car(car& a)
{
    this->seats=a.seats;
    this->cubic=a.cubic;
    strcpy(this->color,a.color);
}
void car:: set1 (char name[])
{
    int i=0;
    for (i=0;name[i]!='\0';i++)
    {
        (this->name[i])=name[i];
    }
    this->name[i]='\0';
}
void car:: set2 (char name[])
{
    int i=0;
    for (i=0;name[i]!='\0';i++)
    {
        (this->color[i])=name[i];
    }
    this->color[i]='\0';
}
void car:: set3 (int a)
{
    this->cubic=a;
}
void car:: set4 (int a)
{
    this->seats=a;
}
void car:: set5 (int a)
{
    this->year=a;
}
void car:: set6 (int a)
{
    this->engine=a;
}
void car:: set7 (int a)
{
    this->frame=a;
}
int car::get3 ()
{
    return this->cubic;
}
int car::get4 ()
{
    return this->seats;
}
int car::get5 ()
{
    return this->year;
}
int car::get6 ()
{
    return this->engine;
}
int car::get7 ()
{
    return this->frame;
}

void car::output ()
{
    cout<<"The owner name is: "<<name<<endl;
    cout<<"The color name is: "<<color<<endl;
    cout<<"The cubic capacity is: "<<cubic<<endl;
    cout<<"The number of seats are: "<<seats<<endl;
    cout<<"The year of manufacture is: "<<year<<endl;
    cout<<"The engine number is: "<<engine<<endl;
    cout<<"The frame number is: "<<frame<<endl;
}
int main()
{
    car obj1;
    char name[100];
    char cname[100];
    int a;
    cout<<"Enter the name: ";
    cin.getline(name,100);
    obj1.set1(name);
    cout<<"Enter the color name: ";
    cin.getline(cname,100);
    obj1.set2(cname);
    cout<<"Enter the cubic capacity: ";
    cin>>a;
    obj1.set3(a);
    cout<<"Enter the number of seats: ";
    cin>>a;
    obj1.set4(a);
    cout<<"Enter the year of manufacture: ";
    cin>>a;
    obj1.set5(a);
    cout<<"Enter the engine number: ";
    cin>>a;
    obj1.set6(a);
    cout<<"Enter the frame number: ";
    cin>>a;
    obj1.set7(a);
    cout<<"Information about Obj1"<<endl;
    obj1.output();
    cout<<"Enter the information about 2nd car: "<<endl;
    car obj2(obj1);
    cout<<"Enter the name: ";cin.ignore();
    cin.getline(name,100);
    obj2.set1(name);
    cout<<"Enter the engine number: ";
    cin>>a;
    obj2.set6(a);
    cout<<"Enter the frame number: ";
    cin>>a;
    obj2.set7(a);
    cout<<"Enter the year of manufacture: ";
    cin>>a;
    obj2.set5(a);
    cout<<"The information about the 2nd car is: "<<endl;
    obj2.output();



}
