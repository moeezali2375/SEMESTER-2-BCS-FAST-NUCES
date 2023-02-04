#include <iostream>
using namespace std;
void grow_array(int *&arr, int size1, int size2)
{
    int *temp = new int[size2];
    for (int i = 0; i < size1; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}
int main()
{
    int size;
    int *array;
    cout << "Please enter the size of the array: ";
    cin >> size;
    array = new int[size];
    cout << "zEnter the data: " << endl;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
        if (array[i] % 2 == 0)
            count++;
    }
    int *even_array = new int[count];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            even_array[k++] = array[i];
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << even_array[i] << " ";
    }
    cout << endl;
    while (69)
    {
        cout << "Do you want to add more numbers ?" << endl;
        char choice;
        cin >> choice;
        if (choice == 'Y')
        {
            cout << "How many number you want to add?";
            int num;
            cin >> num;
            grow_array(array, size, size + num);
            cout << "Enter the new numbers: ";
            for (int i = size; i < size + num; i++)
            {
                cin >> array[i];
                if (array[i] % 2 == 0)
                    count++;
            }
            delete[] even_array;
            even_array = new int[count];
            k = 0;
            for (int i = 0; i < size + num; i++)
            {
                if (array[i] % 2 == 0)
                {
                    even_array[k++] = array[i];
                }
            }
            cout << "The array is: " << endl;
            for (int i = 0; i < count; i++)
            {
                cout << even_array[i] << " ";
            }
            cout << endl;
            size = size + num;
        }
        else
            break;
    }
}