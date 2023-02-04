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
    friend ostream &operator<<(ostream &out, Vector a);
    friend istream &operator>>(istream &in, Vector &a);

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
    Vector(const Vector &a)
    {
        d = a.d;
        v = new float[d];
        for (int i = 0; i < d; i++)
        {
            v[i] = a.v[i];
        }
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
    float &operator[](int i)
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

    ~Vector()
    {
        if (d > 0)
        {
            delete[] v;
        }
    }
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






int main()
{
    char test;
    while (96)
    {
        cout << "Press 1 to calculate unit vector." << endl;
        cout << "Press 2 to check assignment operator." << endl;
        cout << "Press 3 to calculate dot product of 2 vectors." << endl;
        cout << "Press 4 to check equality operator." << endl;
        cout << "Press 5 to check non-equality operator." << endl;
        cout << "Press 6 to to find the specifc element of the VECTOR." << endl;
        cout << "Press x to EXIT the program." << endl;
        for (int k = 0; k < 1; k++)
        {
            cin >> test;
            if (test == '1' || test == '2' || test == '3' || test == '4' || test == '5' || test == 'x'||test == '6')
                ;
            else
            {
                cout << "Invalid operation!" << endl
                     << "Enter again!" << endl;
                k--;
            }
        }
        int dimension;
        cout << "Please enter the dimension of the vector: ";
        cin >> dimension;
        if (test == 'x')
        {
            cout << "Program closed successfully!" << endl;
            break;
        }
        if (test == '1')
        {
            Vector a(dimension);
            Vector a1(dimension);
            cin >> a;
            cout << "Vector 1 is: " << endl;
            cout << a;
            cout << "Now enter the data for 2nd vector: " << endl;
            cin >> a1;
            cout << "Vector 2 is: " << endl
                 << a1;
            
            Vector unit;
            char check;
            for (int i = 0; i < 1; i++)
            {
                cout << "Press 1 to calculate unit vector of 1'st vector or press 2 to calculate unit vector of 2nd vector!";
                cin >> check;
                if (check == '1' || check == '2')
                    ;
                else
                {
                    cout << "Invalid entry!" << endl
                         << "Enter choice again!";
                    i--;
                }
            }
            cout << "The unit vector is: " << endl;
            if (check == '1')
            {
                unit = !a;
                cout << unit;
            }
            else
            {
                unit = !a1;
                cout << unit;
            }
        }

        
        else if (test == '2')
        {
            Vector assign(dimension);
            Vector assign1;
            Vector assign2;
            cin >> assign;
            cout << assign;
            cout << "Cascading: " << endl;
            assign2 = assign1 = assign;
            cout << "The first Vector is: " << assign2;
            cout << "The Second Vector is: " << assign1;
            cout << "The third Vector is: " << assign;
        }
    
        else if (test == '3')
        {
            Vector c(dimension), d(dimension);
            cin >> c;
            cin >> d;
            cout << "The dot product is: " << c * d << endl;
        }
        else if (test == '4')
        {
            Vector c(dimension), d(dimension);
            cin >> c;
            cin >> d;
            if (c == d)
            {
                cout << "The given vectors are equal!" << endl;
            }
            else
                cout << "The given vectors are not equal!" << endl;
        }
        else if (test == '5')
        {
            Vector c(dimension), d(dimension);
            cin >> c;
            cin >> d;
            if (c != d)
            {
                cout << "The given vectors are not equal!" << endl;
            }
            else
                cout << "The given vectors are equal!" << endl;
        }
        else if (test == '6')
        {
            Vector c(dimension);
            cin >> c;
            cout << "Enter the index number: ";
            int index;
            for (int i = 0; i < 1; i++)
            {
                cin>>index;
                if (index >= 0 && index < dimension)
                    ;
                else
                {
                    cout << "Invalid Index!" << endl;
                    cout << "Please enter again: ";
                    i--;
                }
            }
            cout<<"The "<<index<<"'th element of Vector is: "<<c[index]<<endl;
        }
    }
}

