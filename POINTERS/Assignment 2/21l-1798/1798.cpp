#include <iostream>
#include <fstream>
using namespace std;
void **growarray(int **a, int &size)
{
    int *temp;
    temp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = a[i];
    }
    
    size++;
    a= temp;
}

void multiply(int r, int c, int r1, int c1, int **&a, int **b, int **w, int **w1, int *q, int *q1)
{
    int **temp;
    temp = new int *[r];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (q[i] == q1[i])
                a[i][j] *= b[i][j];
        }
    }
}
void add(int &r, int &c, int **&a, int **&w, int *&q, int **&aa, int size)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ; // a[i][j] += b[i][j];
        }
    }
}
void transpose(int &r, int &c, int **&a, int **&w, int *&q, int **&aa, int size)
{
    int **temp;
    temp = new int *[c];
    for (int i = 0; i < c; i++)
    {
        *(temp + i) = new int[r];
        temp[i][r] = 0;
    }
    for (int i = 0; i < 2; i++)
        ;
}
void output(int &r, int &c, int **&a, int **&w, int *&q, int **&aa, int size)
{
    int k = 0;
    for (int i = 0,k=0; i < r && k < size; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == aa[k][0] && j == aa[k][1])
            {
                // if (aa[i][2] < 9)
                {
                    cout << aa[k][2] << "    ";
                    k++;
                }
                // else if (aa[i][2] > 9 && aa[i][2] < 100)
                // {
                //     cout << aa[i][2] << "   ";
                //     k++;
                // }
                // else if (aa[i][2] > 99 && aa[i][2] < 1000)
                // {
                //     cout << aa[i][2] << "  ";
                //     k++;
                // }
                // else if (aa[i][k] > 999 && aa[i][k] < 10000)
                // {
                //     cout << aa[i][2] << " ";
                //     k++;
                // }
            }
            // else
            //     cout << "0"
            //          << "    ";
        }
        cout << endl;
        k++;
    }
}

void input(int &r, int &c, int **&a, int **&w, int *&q, int **&aa, int size)
{
    int test, test2, test3;
    ifstream fin("input.txt");
    fin >> r >> c;
    a = new int *[r];

    q = new int[r];
    w = new int *[r];
    for (int i = 0; i < r; i++)
    {
        fin >> q[i];
        *(a + i) = new int[q[i]];
        *(w + i) = new int[q[i]];
        for (int j = 0; j < q[i]; j++)
        {
            fin >> w[i][j];
            fin >> a[i][j];
        }
    }
    size = 0;
    for (int i = 0; i < r; i++)
        size += q[i];
    ////===============================================================================================================================================================================================================================================================================================================================================================================================================
    //
    //   ####  #####     ###    #####     ####  #####
    //  ##     ##  ##   ## ##   ##  ##   ##     ##
    //   ###   #####   ##   ##  #####     ###   #####
    //     ##  ##      #######  ##  ##      ##  ##
    //  ####   ##      ##   ##  ##   ##  ####   #####
    //
    //===============================================================================================================================================================================================================================================================================================================================================================================================================
    aa = new int *[size];
    for (int i = 0; i < size; i++)
    {
        *(aa + i) = new int[3];
    }
    int t = 0, jj = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < q[i]; j++)
        {
            aa[jj][0] = t;
            // cout<<t<<"\t";
            jj++;
        }
        t++;
    }
    jj = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < q[i]; j++)
        {
            aa[jj][1] = w[i][j];
            jj++;
        }
    }
    jj = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < q[i]; j++)
        {
            aa[jj][2] = a[i][j];
            jj++;
        }
    }
    a = aa;
    ////==========================================================================================================================================================================================================================================================================================================================================================================================================================================================================================
    //
    //   ####  #####   #####    #####  #####   #####    #####   ####  ##     ##  ######    ###    ######  ##   #####   ##     ##
    //  ##     ##  ##  ##  ##   ##     ##  ##  ##  ##   ##     ##     ####   ##    ##     ## ##     ##    ##  ##   ##  ####   ##
    //   ###   #####   #####    #####  #####   #####    #####   ###   ##  ## ##    ##    ##   ##    ##    ##  ##   ##  ##  ## ##
    //     ##  ##      ##  ##   ##     ##      ##  ##   ##        ##  ##    ###    ##    #######    ##    ##  ##   ##  ##    ###
    //  ####   ##      ##   ##  #####  ##      ##   ##  #####  ####   ##     ##    ##    ##   ##    ##    ##   #####   ##     ##
    //
    //==========================================================================================================================================================================================================================================================================================================================================================================================================================================================================================

    cout << "The sparse matrix is: " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << aa[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    ifstream fin("input.txt");
    int r, r1, c, c1;
    int **a;
    int **b;
    int *q;
    int **w;
    char opt;
    int *q1;
    int **w1;
    int **aa;
    int size;
    cout << "Enter the size of rows and columns respectively: " << endl;
    input(r, c, a, w, q, aa, size);
    cout << "Your matrix is: " << endl;
    output(r, c, a, w, q, aa, size);
    while (9696)
    {
        cout << "Select an option to perform a calculation!" << endl;
        cout << "Hit 1 to calculate transpose of the given matrix." << endl;
        cout << "Or hit 2 to add it to other matrix. " << endl;
        cout << "Or hit 3 to multiply it to another matrix: " << endl;
        cout << "Or hit 4 to close the program." << endl;
        cin >> opt;
        if (opt == '4')
        {
            cout << "Program closed successfully!";
            delete[] a;
            delete[] b;
            delete[] q;
            delete[] q1;
            delete[] w;
            delete[] w1;
            a = nullptr;
            b = nullptr;
            w = nullptr;
            w1 = nullptr;
            q = nullptr;
            q1 = nullptr;
            break;
        }
        if (opt == '1')
        {
            cout << "The transpose of the given matrix is: " << endl;
            // transpose(r, c, a, w, q);
            // output(r, c, a, w, q);
        }
        if (opt == '2')
        {
            cout << "Fetching data for the 2nd matrix from the file...." << endl;
            // input(r1, c1, b, w1, q1);
            cout << "Your 2nd matrix is: " << endl;
            // output(r1, c1, b, w1, q1);
            if (r1 != r || c1 != c)
            {
                cout << "The given matrices are incompatible for addition!" << endl;
            }
            else
            {
                // add(r, c, r1, c1, a, b, w, w1, q, q1);
                cout << "The addition of the matrices is: " << endl;
                // output(r, c, a, w, q);
            }
        }
        if (opt == '3')
        {
            cout << "Fetching data for the 2nd matrix from the file...." << endl;
            // input(r1, c1, b, w1, q1);
            cout << "Your 2nd matrix is: " << endl;
            // output(r1, c1, b, w1, q1);
            if (r != c1)
            {
                cout << "The given matrices are incompatible for multiplication!" << endl;
            }
            else
            {
                //     multiply(r, c, r1, c1, a, b, w, w1, q, q1);
                //     cout << "The multiplication of the matrices is: " << endl;
                //     output(r, c, a, w, q);
            }
        }
    }
}
