#include <iostream>
using namespace std;

template <typename T>
class set
{
private:
    T *ele;
    int size;

public:
    set()
    {
        // ele = nullptr;
        size = 0;
    }
    set(int s)
    {
        ele = new T[s];
        size = s;
    }
    set(T arr[], int s)
    {
        size = s;
        ele = new T[s];
        for (int i = 0; i < s; i++)
        {
            ele[i] = arr[i];
        }
    }
    set(set &s)
    {
        ele = new T[s.size];
        for (int i = 0; i < s.size; i++)
        {
            ele[i] = s.ele[i];
        }
        size = s.size;
    }
    set<T> *intersection(set<T> &A)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < A.size; j++)
            {
                if (ele[i] == A.ele[i])
                {
                    count++;
                }
            }
        }
        set<T> *s = new set<T>(count);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0, k = 0; j < A.size; j++)
            {
                if (ele[i] == A.ele[i])
                {
                    s->ele[k] = ele[i];
                    k++;
                }
            }
        }
        return s;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << ele[i] << " ";
        }
        cout << endl;
    }
    ~set()
    {
        if (size > 0)
            delete[] ele;
    }
};
int main()
{
    int a[5] = {2, 3, 4, 5, 6};
    char b[3] = {'a', 'b', 'c'};
    set<int> s1(a, 5);
    set<char> s2(b, 3);
    s2.print();
    // set<int> s2(b, 5);
    // set<int> *sptr;
    // sptr = s1.intersection(s2);
}
