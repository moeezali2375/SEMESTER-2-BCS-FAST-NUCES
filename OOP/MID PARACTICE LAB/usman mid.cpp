#include<iostream>
using namespace std;
class Month {
	char* name;
	int monthcount;
public:
	Month()
	{
		name = new char[50];
		name="January";
        name[8]='\0';
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