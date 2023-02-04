#include <iostream>
using namespace std;
class XYZ
{
private:
    int x;

public:
    XYZ()
    {
        cout << " XYZ()";
    }
    ~XYZ()
    {
        cout << " ~XYZ()";
    }
};

class ABC
{
private:
    int abc;
    XYZ a;
public:
    ABC()
    {
        cout << "AABC()" << endl;
    }
    ~ABC()
    {
        cout << "~AABC()" << endl;

    }
};
int main()
{
    ABC hello;
}