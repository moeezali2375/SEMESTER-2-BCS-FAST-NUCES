#include <iostream>
using namespace std;
class BinaryNum
{
    int *binNum;  // integer array to save binary number
    int noOfBits; // total number of bits
public:
    BinaryNum()
    {
        binNum = nullptr;
        noOfBits = 0;
    }
    BinaryNum(BinaryNum &s)
    {
        this->noOfBits = s.noOfBits;
        binNum = new int[noOfBits];
        for (int i = 0; i < noOfBits; i++)
        {
            this->binNum[i] = s.binNum[i];
        }
    }
    BinaryNum(char *num);
    void Print()
    {
        if (binNum != 0)
        {
            for (int i = 0; i < noOfBits; i++)
            {
                cout << binNum[i];
                cout << endl;
            }
        }
    }
    friend ostream &operator<<(ostream &out, BinaryNum a);
    BinaryNum &operator=(BinaryNum a)
    {
        if (noOfBits != 0)
        {
            delete[] binNum;
        }
        noOfBits = a.noOfBits;
        binNum = new int[noOfBits];
        for (int i = 0; i < noOfBits; i++)
        {
            binNum[i] = a.binNum[i];
        }
        return *this;
    }
    void grow()
    {
        BinaryNum a;
        a.noOfBits = this->noOfBits + 1;
        a.binNum = new int[a.noOfBits];
        a.binNum[0] = 1;
        for (int i = 0, k = 1; i < noOfBits; i++)
        {
            a.binNum[k] = binNum[i];
            k++;
        }
        delete[] this->binNum;
        binNum = a.binNum;
        noOfBits = a.noOfBits;
        *this = a;
        //*this=a;
    }
    BinaryNum operator++(int)
    {
        BinaryNum a = *this;
        int count = noOfBits - 1;
        int flag = 0;
        if (this->binNum[count] == 0)
        {
            this->binNum[count] = 1;
        }
        else if (this->binNum[count] == 1)
        {
            flag = 1;
            this->binNum[count] = 0;
            count--;
        }
        if (flag == 1)
        {
            for (int i = 0; this->binNum[count] != 0; i++)
            {
                this->binNum[count] = 0;
                count--;
            }
            if (count == -1)
            {
                this->grow();
            }
            else
                this->binNum[count + 1] = 1;
        }
        return a;
    }
    int operator[](int i)
    {
        return this->binNum[i];
    }
};
ostream &operator<<(ostream &out, BinaryNum a)
{
    if (a.noOfBits == 0)
        cout << endl;
    else
    {
        out << "{";
        for (int i = 0; i < a.noOfBits; i++)
        {
            out << a.binNum[i];
            if (i == a.noOfBits - 1)
            {
                out << "}";
            }
            else
                out << ",";
        }
        out << endl;
    }
    return out;
}
BinaryNum::BinaryNum(char *num)
{
    noOfBits = strlen(num);
    binNum = new int[noOfBits];
    for (int i = 0; i < noOfBits; i++)
    {
        if (num[i] == '1')
        {
            binNum[i] = 1;
        }
        else if (num[i] == '0')
        {
            binNum[i] = 0;
        }
    }
}

int main()
{
    BinaryNum b1;
    BinaryNum b2("101");
    BinaryNum b3("1111");
    cout << "b1= " << b1;
    cout << "b2= " << b2;
    b1 = b2;
    cout << "b1= " << b1;
    b1 = b3;
    b3++;
    cout << "b1= " << b1; 
    cout << "b3= " << b3;
    cout << "b3[0]= " << b3[0]<<endl;
    cout << "b3[3]= " << b3[3]<<endl;
}
