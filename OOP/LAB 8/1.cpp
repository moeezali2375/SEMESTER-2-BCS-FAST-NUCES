#include <iostream>
using namespace std;
class poly
{
    int total;
    int *coeff;
    int *exp;

public:
    poly()
    {
        total = 0;
        coeff = nullptr;
        exp = nullptr;
    }
    poly(int size, int a[], int b[])
    {
        total = size;
        coeff = new int[size];
        exp = new int[size];
        for (int i = 0; i < size; i++)
        {
            coeff[i] = a[i];
            exp[i] = b[i];
        }
    }
    poly(const poly &s)
    {
        // if (this->total > 0)
        // {
        //     delete[] coeff;
        //     delete[] exp;
        // }
        this->total = s.total;
        this->coeff = new int[total];
        this->exp = new int[total];
        for (int i = 0; i < total; i++)
        {
            this->coeff[i] = s.coeff[i];
            this->exp[i] = s.exp[i];
        }
    }
    friend ostream &operator<<(ostream &out, poly);
    bool operator!()
    {
        if (this->total == 1 && coeff[0] && exp[0] == 0)
        {
            return true;
        }
        else
            return false;
    }
    bool operator!=(poly aa)
    {
        if (total == aa.total)
        {
            for (int i = 0; i < total; i++)
            {
                if (coeff[i] != aa.coeff[i] || exp[i] != aa.exp[i])
                {
                    return true;
                }
            }
            return false;
        }
        return true;
    }
    poly &operator++()
    {
        for (int i = 0; i < total; i++)
            this->coeff[i] = this->coeff[i] + 1;
        return *this;
    }
    poly operator++(int)
    {
        poly temp = *this;
        for (int i = 0; i < total; i++)
            this->coeff[i] = this->coeff[i] + 1;
        return temp;
    }
    poly operator+(poly aa)
    {
        int common = 0;
        for (int i = 0; i < aa.total; i++)
        {
            for (int j = 0; j < this->total; j++)
            {
                if (exp[j] == aa.exp[i])
                    common++;
            }
        }
        int common1 = common;
        for (int i = 0; i < aa.total; i++)
        {
            int flag = 0;
            for (int j = 0; j < this->total; j++)
            {
                if (exp[j] == aa.exp[i])
                    flag = 1;
            }
            if (flag == 0)
                common++;
        }
        for (int i = 0; i < this->total; i++)
        {
            int flag = 0;
            for (int j = 0; j < aa.total; j++)
            {
                if (exp[i] == aa.exp[j])
                    flag = 1;
            }
            if (flag == 0)
                common++;
        }
        int *a;
        int *b;
        poly temp(common, a, b);
        int k = 0;
        for (int i = 0; i < aa.total; i++)
        {
            for (int j = 0; j < this->total; j++)
            {
                if (this->exp[j] == aa.exp[i])
                {
                    temp.exp[k] = aa.exp[i];
                    temp.coeff[k] = this->coeff[j] + aa.coeff[i];
                    k++;
                }
            }
        }
        for (int i = 0; i < aa.total; i++)
        {
            int flag = 0;
            for (int j = 0; j < this->total; j++)
            {
                if (exp[j] == aa.exp[i])
                    flag = 1;
            }
            if (flag == 0)
            {
                temp.coeff[k] = aa.coeff[i];
                temp.exp[k] = aa.exp[i];
                k++;
            }
        }
        for (int i = 0; i < this->total; i++)
        {
            int flag = 0;
            for (int j = 0; j < aa.total; j++)
            {
                if (exp[i] == aa.exp[j])
                    flag = 1;
            }
            if (flag == 0)
            {
                temp.coeff[k] = this->coeff[i];
                temp.exp[k] = this->exp[i];
                k++;
            }
        }
        ////=========================================================================================================================================================================================================================================================================================================================================================================================================================
        //
        //   ####   #####   #####    ######  ##  ##     ##   ####
        //  ##     ##   ##  ##  ##     ##    ##  ####   ##  ##
        //   ###   ##   ##  #####      ##    ##  ##  ## ##  ##  ###
        //     ##  ##   ##  ##  ##     ##    ##  ##    ###  ##   ##
        //  ####    #####   ##   ##    ##    ##  ##     ##   ####
        //
        //=========================================================================================================================================================================================================================================================================================================================================================================================================================
        k = temp.total;
        for (int i = 0; i < temp.total; i++)
        {
            int max = 0;
            int flag = 0;
            for (int j = 0; j < k; j++)
            {
                if (temp.exp[max] >= temp.exp[j])
                {
                    max = j;
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                swap(temp.exp[k - 1], temp.exp[max]);
                swap(temp.coeff[k - 1], temp.coeff[max]);
            }
            k--;
        }
        return temp;
    }
    poly &operator=(poly s)
    {
        poly temp;
        if (this->total > 0)
        {
            delete[] coeff;
            delete[] exp;
        }
        this->total = s.total;
        this->coeff = new int[total];
        this->exp = new int[total];
        for (int i = 0; i < total; i++)
        {
            this->coeff[i] = s.coeff[i];
            this->exp[i] = s.exp[i];
        }
        return *this;
    }
    poly operator+(int aa)
    {
        int a[1];
        int b[1];
        a[0] = aa;
        b[0] = 0;
        poly temp(1, a, b);
        temp = temp + *this;
        return temp;
    }
    
};
poly operator+(int aa,poly A)
    {
        int a[1];
        int b[1];
        a[0] = aa;
        b[0] = 0;
        poly temp(1, a, b);
        temp = temp + A;
        return temp;
    }
ostream &operator<<(ostream &out, poly aa)
{
    for (int i = 0; i < aa.total; i++)
    {
        out << aa.coeff[i];
        if (aa.exp[i] == 0)
            ;
        else
            out << "x^" << aa.exp[i];
        if (i == aa.total - 1)
            ;
        else
            out << '+';
    }
    return out;
}
int main()
{
    // poly p5;
    // poly p = p5;
    // p = p5;
    // int coeff_P1[] = {1, 2, 5};
    // int exp_P1[] = {4, 2, 0};
    // // Coefficients for poly P1
    // // Exponents for poly P1
    // int coeff_P2[] = {4, 3};      // Coefficients for poly P2
    // int exp_P2[] = {6, 2};        // Exponents for poly P2
    // poly P1(3, coeff_P1, exp_P1); // Creates P1 with 3 terms (P1 = 1x^4 + 2x^2 +
    // // 5x^0 )
    // poly P2(2, coeff_P2, exp_P2);  // Creates P2 with 2 terms (P2 µ= 4x^6 + 3x^2)
    // cout << "P1 = " << P1 << endl; // Prints P1 = x^4+2x^2+5
    // cout << "P2 = " << P2 << endl; // Prints P2 = 4x^6+3x^2

    // if (!P1)
    //     cout << "P1 is zero" << endl; /*if polynomial has only 1 term and its coeff and exp are zero. i.e.
    //     if p1 = 0.*/
    // if (P1 != P2)
    //     cout << "P1 is Not Equal to P2" << endl;
    // cout << ++P1 << endl; // adds 1 in all the coefficient.
    // cout << P1 << endl;
    // cout << P1++ << endl; // adds 1 in all the coefficient.
    // cout << P1 << endl;
    // poly P3 = P1 + P2;
    // cout << P3<<endl;
    int coeff_P1[] = {1, 2, 5};
    int coeff_P2[] = {6};
    int exp_P1[] = {4, 2, 0};
    int exp_P2[] = {0};
    poly P3, P1(3, coeff_P1, exp_P1), P2(1, coeff_P2, exp_P2);
    cout << P1 << endl;
    cout << P2 << endl;
    P3 = 2+P1;
    cout << P3;
}