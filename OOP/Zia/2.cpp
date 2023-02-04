#include <iostream>
using namespace std;
int *max_in_each_row(int **arr, int r, int c)
{
    int *new_array = new int[r];
    for (int j = 0; j < r; j++)
    {
        int max = arr[j][0];
        for (int k = 0; k < c; k++)
        {
            if (max <= arr[j][k])
                max = arr[j][k];
        }
        new_array[j] = max;
    }
    return new_array;
}
int main()
{
    int **arr, r, c;
    int *max_array;
    cout << "Please enter the data for the 1st 2-D array: " << endl;
    cout << "Enter Rows: ";
    cin >> r;
    cout << "Enter Columns: ";
    cin >> c;
    arr = new int *[r];
    cout << "Enter the values: ";
    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    max_array = max_in_each_row(arr, r, c);
    cout << "The maximum value in each row is: " << endl;
    for (int i = 0; i < r; i++)
    {
        cout << max_array[i] << endl;
        delete[] arr[i];
    }
    delete []arr;
    delete []max_array;

}