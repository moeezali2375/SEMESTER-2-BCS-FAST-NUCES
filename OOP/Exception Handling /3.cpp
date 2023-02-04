#include <iostream>
using namespace std;
class divbyzero
{
    string msg;

public:
    divbyzero()
    {
        msg = "Divide by zero";
    }
    divbyzero(string s)
    {
        msg = s;
    }
    string what()
    {
        return msg;
    }
};
int main()
{
    int dividend, divisor;
    float res;
    try
    {
        cin >> dividend >> divisor;
        if (divisor == 0)
            throw divbyzero("division by zero in main function");
        res = (float)dividend / divisor;
    }
    catch (divbyzero e)
    {
        cout << "Exception occurred" << endl;
        cout << e.what() << '\n';
    }
}
