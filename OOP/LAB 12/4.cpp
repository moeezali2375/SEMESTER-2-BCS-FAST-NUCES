#include <iostream>
using namespace std;
float f2(int x, int y);
float f3(int x, int y);
float f1(int x, int y)
{
    cout << "Function 1 Start" << endl;
    float res = f2(x, y);
    cout << "Function 1 End " << endl;
    return res;
}
float f2(int x, int y)
{
    cout << "Function 2 Start" << endl;
    float res = f3(x, y);
    cout << "Function 2 End " << endl;
    return res;
}
float f3(int x, int y)
{
    string s = "hi";
    float res = 0;
    cout << "Function 3 Start" << endl;
    res = (float)x / y;
    if (y == 0)
        throw y;
    cout << "Function 3 End " << endl;
    return res;
}

int main()
{
    cout << "Main Start" << endl;
    int x, y;
    cin >> x >> y;
    int res;
    try
    {
        // if (y == 0)
        //     throw y;
        throw f1(x, y);
    }
    catch (int num)
    {
        cout << "2nd Number is 0" << endl;
    }
    catch (float div)
    {
        cout << "Result is " << res << endl;
    }
    // catch (string s)
    // {
    //     cout << "2nd Number is 0" << endl;
    // }
    cout << "Main End" << endl;
}
