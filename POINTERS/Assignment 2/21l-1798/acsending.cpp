#include <iostream>
using namespace std;
int main()
{
    int a[5] = {0, 4, 9, 2, 7};
    int check;
    int size = 5;
    for (int i = 0; i < 5; i++)
    {
        int max = a[0];
        for (int j = 0; j < size; j++)
        {
            if (max <= a[j])
            {
                max = a[j];
                check = j;
            }
        }
        swap(a[size - 1], a[check]);
        size--;
    }

    for (int i = 0; i < 5; i++)
        cout << a[i] << "\t";
}
