#include <iostream>
using namespace std;
int *minCol_wise(int **mat, int row, int col)
{
    int *temp = new int[row];
    for (int i = 0, k = 0; i < col && k < row; i++, k++)
    {
        int min = mat[0][i];
        {
            for (int j = 0; j < row; j++)
            {
                if (mat[j][i] < min)
                    min = mat[j][i];
            }
        }
        temp[k] = min;
    }
    return temp;
}
int main()
{
    int row;
    int col;
    cout << "enter number of rows : ";
    cin >> row;
    cout << "enter number of columns : ";
    cin >> col;
    cout << "the elements of matrix are : ";
    int **mat;
    mat = new int *[row];
    for (int i = 0; i < row; i++)
    {
        mat[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << "given matrix is : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    int *temp = minCol_wise(mat, row, col);
    cout << "The minimum element matrix is: " << endl;
    for (int i = 0; i < row; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}