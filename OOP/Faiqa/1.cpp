#include <iostream>
using namespace std;
int **factor(int *factors, int size)
{
    int **matrixx = new int *[size];
    /*for (int i = 0; i < size; i++)
    {
    matrix[i] = new int[size];
    }*/
    int count = 0;
    for (int i = 0; i < size; i++)
    {

        count = 0;
        for (int j = 2; j < factors[j]; j++)
        {

            if (factors[i] % j == 0)
            {
                count++;
            }
        }
        matrixx[i] = new int[count + 1];
        matrixx[i][0] = factors[i];
        matrixx[i][count] = -1;

        for (int j = 2, k = 1; j < factors[i]; j++)
        {
            if (factors[i] % j == 0)
            {
                matrixx[i][k] = j;
                k++;
            }
        }
    }
    return matrixx;
}
int main()
{
    int size;
    cout << " enter how many num u wanto enter " << endl;
    cin >> size;
    int *factors = new int[size];
    cout << "enter  " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> factors[i];
        if (factors[i] == -1)
        {
            break;
        }
        if (factors[i] < 6 || factors[i] > 100)
        {
            cout << " enter valid " << endl;
            i--;
        }
    }

    cout << " factors are " << endl;

    int **matrix = factor(factors, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < factors[i]; j++)
        {
            if (matrix[i][j] == -1)
            {
                cout << matrix[i][j] << " ";
                break;
            }
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}