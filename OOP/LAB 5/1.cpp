#include <iostream>
using namespace std;
void rotate(int **ele, int n)
{
    int hehe;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    hehe = ele[0][0];
                    ele[i][j] = ele[i][j + 1];
                }
                else if (j == n - 1)
                {
                    ele[i][j] = ele[i + 1][j];
                }
                else
                    ele[i][j] = ele[i][j + 1];
            }
            else if (i == n - 1)
            {
                swap(ele[i][j], hehe);
            }
            
            else if (j == n - 1)
            {
                swap(ele[i][j], ele[i + 1][j]);
            }
            else if (j == 0)
            {
                swap(ele[i][j], hehe);
            }
            
        }
    }
}
int main()
{
    int **ele;
    cout << "Enter the size of square of matrix: ";
    int n;
    cin >> n;
    ele = new int *[n];
    for (int i = 0; i < n; i++)
    {
        *(ele + i) = new int[n];
        cout << "Enter the values for " << i + 1 << "th row of matrix: " << endl;
        for (int j = 0; j < n; j++)
        {
            cin >> ele[i][j];
        }
    }
    cout << "The matrix is: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ele[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The matrix after inversion is: " << endl;
    ;
    rotate(ele, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ele[i][j] << " ";
        }
        cout << endl;
    }
}