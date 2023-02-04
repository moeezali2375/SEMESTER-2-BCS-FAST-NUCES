#include <iostream>
using namespace std;
class Foo
{
    static int x;
    static int count;
    int a;

public:
    static int Bar(int i)
    {
        return x * i * count + x * i + 1;
    }
};
int Foo::count = 10;
void display()
{
    cout<<"Static: "<<Foo::Bar(1);
}
int main()
{
    display();
}