#include <iostream>
#include <math.h>
using namespace std;
class Vector
{
    int d;
    float *v;

public:
    Vector()
    {
        d = 0;
        v = nullptr;
    }
    Vector(int d)
    {
        this->d = d;
        v = new float[d];
    }
    ~Vector()
    {
        if (v!=nullptr)
        {
            delete[] v;
        }
        v=nullptr;
    }
    Vector(const Vector &a)
    {
        d = a.d;
        v = new float[d];
        for (int i = 0; i < d; i++)
        {
            v[i] = a.v[i];
        }
    }
    Vector &operator!()
    {
        Vector res(d);
        float sum = 0;
        for (int i = 0; i < d; i++)
        {
            res.v[i] = v[i];
            sum = sum + v[i] * v[i];
        }
        sum = sqrt(sum);
        for (int i = 0; i < d; i++)
        {
            res.v[i] /= sum;
        }
        (*this) = res;
        return *this;
        // cout << "The Unit Vector is: " << res;
    }
    float operator*(Vector a)
    {
        int check = 0;
        for (int i = 0; i < a.d; i++)
        {
            check += this->v[i] * a.v[i];
        }
        return check;
    }
    bool operator==(Vector a)
    {
        if (this->d == a.d)
        {
            for (int i = 0; i < d; i++)
            {
                if (this->v[i] != a.v[i])
                    return false;
            }
            return true;
        }
        return false;
    }
    bool operator!=(Vector a)
    {
        if (this->d != a.d)
        {
            for (int i = 0; i < d; i++)
            {
                if (this->v[i] == a.v[i])
                    return true;
            }
            return false;
        }
        return true;
    }
    float& operator[](int i)
    {
        return this->v[i];
    }

    Vector &operator=(Vector a)
    {
        if (d > 0)
            delete[] v;
        v = new float[a.d];
        d = a.d;
        for (int i = 0; i < d; i++)
        {
            v[i] = a.v[i];
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, Vector a);
    friend istream &operator>>(istream &in, Vector &a);
};
ostream &operator<<(ostream &out, Vector a)
{
    out << "VECTOR: ";
    out << '<';
    for (int i = 0; i < a.d; i++)
    {
        out << a.v[i];
        if (i == a.d - 1)
            ;
        else
            out << ' ';
    }
    out << '>';
    out << endl;
    return out;
}
istream &operator>>(istream &in, Vector &a)
{
    cout << "Please enter the components of vector: ";
    for (int i = 0; i < a.d; i++)
    {
        cout << "Enter " << i + 1 << "'th value: ";
        in >> a.v[i];
    }
    return in;
}
