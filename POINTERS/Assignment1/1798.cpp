#include <iostream>
using namespace std;
int *input(int &size)
{
    cout << "Input the size of the set: ";
    cin >> size;
    int *set = new int[size];
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < size; i++)
    {
        cin >> set[i];
    }
    return set;
}

void output(int *set, int size)
{
    cout << "The elements are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << set[i] << " ";
    }
    cout << endl;
    delete[] set;
}

bool iselement(int *set, int size, int x)
{
    int flag = 0;
    for (int i = 0; i < size && flag == 0; i++)
    {
        if (x == set[i])
            flag = 1;
    }
    if (flag == 1)
        return true;
    else
        return false;
}

int *inter(int *a, int *b, int *&c, int size1, int size2, int &size3)
{
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        int flag = 0;
        for (int j = 0; j < size2; j++)
        {
            if (a[i] == b[j])
            {
                // c[k] = a[i];
                // flag = 1;
                k++;
            }
        }
        // if (flag == 1)
        //     ; // size3++;
    }
    c=new int [k];
    size3 = k;
    return c;
}
int *Union(int *a, int *b, int *&c, int size1, int size2, int &size3)
{
    int *temp = inter(a, b, c, size1, size2, size3);
    int j = 0;
    for (int i = 0; i < size1; i++)
    {
        int flag = 0;
        for (int j = 0; j < size2; j++)
        {
            if (a[i] == b[j])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            c[j + size3] = a[i];
            j++;
        }
    }
    for (int i = 0; i < size2; i++)
    {
        int flag = 0;
        for (int j = 0; j < size1; j++)
        {
            if (b[i] == a[j])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            c[j + size3] = b[i];
            j++;
        }
    }
    size3 = size3 + j;
    return temp;
}

int *difference(int *a, int *b, int *&c, int size1, int size2, int &size3)
{
    for (int i = 0; i < size2; i++)
    {
        int flag = 0;
        for (int j = 0; j < size1; j++)
        {
            if (a[j] == b[i])
            {
                for (int ii = j; ii < size1; ii++)
                {
                    a[ii] = a[ii + 1];
                }
                size1--;
            }
        }
    }
    c = a;
    size3 = size1;
    return c;
}
int *complement(int *a, int *b, int *&c, int size1, int size2, int &size3)
{
    for (int i = 0; i < size2; i++)
    {
        int flag = 0;
        for (int j = 0; j < size1; j++)
        {
            if (a[j] == b[i])
            {
                for (int ii = j; ii < size1; ii++)
                {
                    a[ii] = a[ii + 1];
                }
                size1--;
            }
        }
    }
    c = a;
    size3 = size1;
    return c;
}

int main()
{
    char choice;
    int x;
    int size = 0;
    int size2 = 0;
    int size3 = 0;
    int *ptr = input(size);
    int *ptr2 = input(size2);
    int *ptr3 = nullptr;
    cout << "Enter the element you want to search: ";
    cin >> x;
    if (iselement(ptr, size, x) == 1 || iselement(ptr2, size2, x) == 1)
    {
        cout << "Element found!" << endl;
        while (96)
        {
            cout << "Choose any operation: " << endl
                 << "Press 2 for intersection of sets" << endl;
            cout << "Or press 3 for union of sets" << endl;
            cout << "Or press 4 for difference of sets" << endl;
            cout << "Or press 5 for complement of sets" << endl;
            cout << "Or press x to close th program!" << endl;

            cin >> choice;
            if (choice == '2')
            {
                int *ptr3 = new int[100];
                cout << "The intersection of the sets is: ";
                int *temp = inter(ptr, ptr2, ptr3, size, size2, size3);
                output(temp, size3);
            }
            if (choice == '3')
            {
                int *ptr3 = new int[100];
                cout << "The Union of the sets is: ";
                int *temp = Union(ptr, ptr2, ptr3, size, size2, size3);
                output(ptr3, size3);
            }
            if (choice == '4')
            {
                int *ptr3 = new int[100];
                cout << "The Difference of the sets is: ";
                int *temp = difference(ptr, ptr2, ptr3, size, size2, size3);
                output(ptr3, size3);
            }
            if (choice == '5')
            {
                int *ptr3 = new int[100];
                int *temp2 = Union(ptr, ptr2, ptr3, size, size2, size3);
                ptr2 = temp2;
                size2 = size3;
                int size3 = 0;
                cout << "The Complement of the sets is: ";
                int *temp = complement(ptr2, ptr, ptr3, size2, size, size3);
                output(ptr3, size3);
            }
            if (choice == 'x')
            {
                cout << "Program closed!";
                delete[] ptr;
                ptr = nullptr;
                delete[] ptr2;
                ptr2 = nullptr;
                delete[] ptr3;
                ptr3 = nullptr;
                break;
            }
        }
    }
    else
        cout << "No element found! Run the program again!" << endl;
}