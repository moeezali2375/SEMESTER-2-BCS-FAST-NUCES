#include <iostream>
using namespace std;
class bus
{
    bool status;
    float miles;
    float gas;

public:
    bus()
    {
        status = 0;
        miles = 0;
        gas = 0;
    }
    bus(float a, float b)
    {
        miles = b;
        gas = a;
    }
    bool start_and_drive(float a)
};
int main()
{
    bus *m_bus = new bus(20, 1200);

}