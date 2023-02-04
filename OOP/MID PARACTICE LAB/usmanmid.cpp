#include<iostream>
using namespace std;
class Month {
	char* name;
	int monthcount;
public:
	Month()
	{
		name = new char[50];
        strcpy(name,"January");
		monthcount = 1;
	}
    void output()
    {
        cout<<"Month is: "<<name<<endl;
        cout<<"Month count is: "<<monthcount<<endl;
    }

};
int main ()
{
    Month a;
    a.output();

}