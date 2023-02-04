#include <iostream>
using namespace std;
int *grow(int *array, int &size)
{
    int *temp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = array[i];
    }
    delete[] array;
    size++;
    return temp;
}
int * shrink(int *array, int &size)
{
    int *temp = new int[size--];
    for (int i = 0; i < size; i++)
    {
        temp[i] = array[i];
    }
    delete[] array;
    return temp;
}
int main()
{
    cout << "HEllo wolrd";
}