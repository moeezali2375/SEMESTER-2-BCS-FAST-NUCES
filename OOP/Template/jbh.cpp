#include <iostream>
using namespace std;
class fraction
{
private:
    int num; // DATA MEMBERS
    int denum;

public: // ACCESS SPECIFIERS
    fraction()
    {
        ;
    }
    fraction(int a, int b)
    {
        num = a;
        num = b;
    }
    void inputfraction() // MEMBER FUNCTIONS
    {
        cin >> num;
        cin >> denum;
    }
    void outputfraction()
    {
        cout << num << "/" << denum << endl;
    }
    fraction add(fraction f)
    {
        fraction res;
        res.denum = denum * f.denum;
        res.num = num * f.denum + f.num * denum;
        return res;
    }
    int gcd(int ele, int b)
    {
        int gcd;
        if (ele < b)
        {
            for (int i = 1; i <= ele; i++)
            {
                if (ele % i == 0 && b % i == 0)
                    gcd = i;
            }
        }

        if (b <= ele)
        {
            for (int i = 1; i <= b; i++)
            {
                if (ele % i == 0 && b % i == 0)
                    gcd = i;
            }
        }

        return gcd;
    }
    void simplify()
    {
        // fraction rs;
        int ele = gcd(num, denum);
        denum = denum / ele;
        num = num / ele;
    }
};
