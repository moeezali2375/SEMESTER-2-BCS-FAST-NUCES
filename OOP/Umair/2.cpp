#include <iostream>
#include <string>
using namespace std;
class base1
{
protected:
    int x;
    static int count;

public:
    base1()
    {
        x = 10;
        count++;
        cout << "Default Constructor base1 " << this->x << " count " << count << endl;
    }
    base1(int x)
    {
        this->x = x;
    }
    ~base1()
    {
        cout << "Destructor base1 " << this->x << " count " << count-- << endl;
    }
};
int base1::count = 0;
class base2 : public base1
{
public:
    int y;
    base2(int y) : base1(y)
    {
        base1::count++;
        this->y = y + 20;
        cout << "Parameterized base 2 " << this->y << " count " << count << endl;
    }
};
class base3 : public base1
{
public:
    int z;
    base1 b;
    base3(int z) : b(z), base1(10)
    {
        base1::count++;
        this->z = z + 10;
        cout << "Parameterized base 3 "
             << this->z << " count " << count << endl;
    }
};
class base4 : public base2, public base3
{
public:
    int w;
    base4(int w) : base3(w),
                   base2(w)
    {
        this->w = w + 5;
        cout << "parameterized Constructor of base 4 " << w << endl;
    }
};
int main()
{
    base4 b4(5);
}