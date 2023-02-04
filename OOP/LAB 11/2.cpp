#include <iostream>
using namespace std;
template <typename T>
class calculator
{
    T num1, num2, num3, result;

public:
    calculator()
    {
        num1 = 0;
        num2 = 0;
        num3 = 0;
        result = 0;
    }
    calculator(T n, T b, T m, T c)
    {
        num1 = n,
        num2 = b;
        num3 = c;
        result = m;
    }
    void sum(T a, T b)
    {
        num1 = a;
        num2 = b;
        result = num1 + num2;
    }
    void sum(T a, T b, T c)
    {
        num1 = a;
        num2 = b;
        num3 = c;
        result = num1 + num2 + num3;
    }
    void subtract(T a, T b)
    {
        num1 = a;
        num2 = b;
        result = num1 - num2;
    }
    void subtract(T a, T b, T c)
    {
        num1 = a;
        num2 = b;
        num3 = c;
        result = num1 - num2 - num3;
    }
    void multiplication(T a, T b)
    {
        num1 = a;
        num2 = b;
        result = num1 * num2;
    }
    void multiplication(T a, T b, T c)
    {
        num1 = a;
        num2 = b;
        num3 = c;
        result = num1 * num2 * num3;
    }
    void division(T a, T b)
    {
        num1 = a;
        num2 = b;
        result = num1 / num2;
    }
    void division(T a, T b, T c)
    {
        num1 = a;
        num2 = b;
        num3 = c;
        result = num1 / num2 / num3;
    }
    void modulus(T a, T b)
    {
        num1 = a;
        num2 = b;
        result = num1 % num2;
    }
    void max(T a, T b)
    {
        num1 = a;
        num2 = b;
        T max = num1;
        if (max < num2)
            max = num2;
        result = max;
    }
    void min(T a, T b)
    {
        num1 = a;
        num2 = b;
        T max = num1;
        if (max > num2)
            max = num2;
        result = max;
    }
    void print()
    {
        cout << "Result is: " << result << endl;
    }
};
int main()
{
    calculator<float> a;
    a.modulus(5.0, 4.0);
    a.print();
}
