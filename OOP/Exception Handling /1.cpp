#include <iostream>
using namespace std;
int main()
{
    int a, b;
    float res;
    string s = "Invalid Input";
    try
    {
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter divisor: ";
        cin >> b;
        if (!cin)
            throw s;
        if (b == 0)
            throw b;
        res = (float)a / b;
        cout << "Answer is: " << res << endl;
    }
    catch (int x)
    {
        cout << "Divide by " << x;
    }
    catch (string s)
    {
        cout << s << endl;
    }
}
