#include <iostream>
//#include <stdexcept>
using namespace std;
int main()
{
    int a, b;
    float res;
    string s = "Invalid Input";
    try
    {
        int *arr[100];
        for (int i = 0; i < 100; i++)
        {
            arr[i] = new int[10000000];
        }
        throw (5);
    }
    catch (bad_alloc bae)
    {
        cout << "Exception occurred!" << endl;
        cout << bae.what();
    }
    catch (...)
    {
        cout << "laal ae";
    }
}