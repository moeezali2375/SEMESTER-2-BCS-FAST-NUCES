#include <iostream>
using namespace std;
class student
{
    int *array;

public:
    student();
    student (student & s)
    {
        this->array=new int [5];
        for (int i=0;i<5;i++)
        {
            this->array[i]=s.array[i];
        }
    }
    ~student()
    {
        delete []array;
    }

    void setter(int marks, int index);
    void output();
};
student::student()
{
    this->array = new int[5];
    for (int i = 0; i < 5; i++)
    {
        array[i] = 0;
    }
}
void student::setter(int marks, int index)
{
    array[index] = marks;
}
void student::output()
{
    for (int i = 0; i < 5; i++)
    {
        cout<<"Info about subject "<<i+1<<endl;
        cout<<"Data:: "<<array[i];
        cout<<endl;
    }
}

int main()
{
    student student1;
    for (int i=0;i<5;i++)
    {
        int marks;
        cout<<"Enter the marks for "<<i+1<<" subject!"<<endl;
        cin>>marks;
        student1.setter(marks,i);
    }
    cout<<"Info about student 1 is: "<<endl;
    student1.output();
    // student student2;
    // cout<<"Info about student 2 is: "<<endl;
    // student2=student1;
    // student2.output();
    student student2(student1);
    cout<<"Info about student 2 is: "<<endl;
    student2.output();
}
