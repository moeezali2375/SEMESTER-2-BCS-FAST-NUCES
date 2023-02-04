#include <iostream>
#include <string>
using namespace std;
class tornadoException
{
    string s;

public:
    tornadoException()
    {
        s = "Tornado: Take cover immediately!";
    }
    tornadoException(int m)
    {

        s = "Tornado: " + to_string(m) + " Miles away; and approaching.";
    }
    string what()
    {
        throw s;
    }
};
int main()

{
    // tornadoException a;
    try
    {
        int n;
        cin >> n;
        if (n < 0)
        {
            throw tornadoException();
        }
        if (n > 0)
            throw tornadoException(4);
    }
    catch (tornadoException a)
    {
        cout << "Exception\n";
        cout << a.what();
    }
    // catch (tornadoException a(int b))
    // {
    //     cout << "Exception\n";
    //     cout << a;
    // }
}
