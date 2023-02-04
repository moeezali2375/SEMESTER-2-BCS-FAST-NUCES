#include <iostream>
using namespace std;
void growarray(int *array, int s)
{
    int size;
    cout << "Enter the size of new array: ";
    cin >> size;
    if (size <= s)
    {
        cout << "The array already has the given size!" << endl;
    }
    else
    {
        int *new_array;
        new_array = new int[size];
        for (int i = 0; i < size; i++)
        {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        cout << "Size grown!";
    }
}
int main()
{
    char op;
    int size;
    cin >> size;
    int *array = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "Do u want to add more elements to the arrray? (Y/N):";
    for (int i = 0; i < 1; i++)
    {
        cin >> op;
        if (op == 'Y' | op == 'N')
            ;
        else
        {
            cout << "Wrong input!" << endl
                 << "Try again!";
            i--;
        }
    }
    if (op == 'Y')
    {
        growarray(array, size);
    }
}
