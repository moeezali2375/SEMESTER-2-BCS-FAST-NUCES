#include <iostream>
using namespace std;
class sparsematrix
{
    int r, c, **m;
public:
    sparsematrix()
    {
        r = 0;
        c = 0;
        m = nullptr;
    }
    sparsematrix(int rows, int col, int **array)
    {
        r = rows;
        c = col;
        int *nonzero = new int[r];
        for (int i = 0; i < r; i++)
        {
            nonzero[i] = 0;
            for (int j = 0; j < c; j++)
            {
                if (array[i][j] != 0)
                {
                    nonzero[i]++;
                }
            }
        }
        m = new int *[r];
        for (int i = 0; i < r; i++)
        {
            *(m + i) = new int[(nonzero[i] * 2) + 1];
            m[i][0] = nonzero[i];
            for (int j = 1, jj = 0; j < (nonzero[i] * 2) + 1; jj++)
            {
                if (array[i][jj] != 0)
                {
                    m[i][j] = jj;
                    m[i][j + 1] = array[i][jj];
                    j++;
                    j++;
                }
            }
        }
    }
    friend ostream &operator<<(ostream &out, sparsematrix a);

    ////=============================================================================================================================================================================================================================================================================================================================================================================================================================
    //
    //  ##  ##     ##   ####  #####    #####    ###     ####  #####
    //  ##  ####   ##  ##     ##  ##   ##      ## ##   ##     ##
    //  ##  ##  ## ##  ##     #####    #####  ##   ##   ###   #####
    //  ##  ##    ###  ##     ##  ##   ##     #######     ##  ##
    //  ##  ##     ##   ####  ##   ##  #####  ##   ##  ####   #####
    //
    //=============================================================================================================================================================================================================================================================================================================================================================================================================================
    sparsematrix &operator++()
    {
        cout << "SPARSE MATRIX >EXE";
        for (int i = 0; i < r; i++)
        {
            int flag = 0;
            for (int j = 1; j < m[i][0] * 2 + 1; j++)
            {
                if (i == m[i][j])
                {
                    this->m[i][j + 1] += 1;
                    flag = 1;
                    break;
                }
                j++;
            }
            if (flag == 0)
            {
                cout<<"Rows:"<<i;
                growarray(m,i);
                //sortarray(m,i); 
            }
        }
        return *this;
    }
    void growarray(int **m, int i)
    {
        int *temp;
        temp = new int[(m[i][0] * 2) + 3];
        temp[0]=m[i][0]+1;
        int j;
        for (j = 1; j < (m[i][0] * 2) + 1; j++)
        {
            temp[j]=m[i][j];
        }
        temp[j]=i;
        temp[++j]=1;
        delete[]m[i];
        m[i]=temp;
        
        
    }
    void sortarray(int **m,int i)
    {
        for (int i=0;i<r;i++)
        {
            int max=1;
            int l=2*m[i][0]+1;
            for (int j=1;j<l;j++)
            {
                if (m[i][j]>m[i][max])
                {
                    max=j;
                }
                j++;
                swap(m[i][max],m[i][l-1]);
                swap(m[i][max+1],m[i][l]);
                l--;
                l--;
            }
        }
    }
};
ostream &operator<<(ostream &out, sparsematrix a)
{
    out << "The sparse matrix is: " << endl;
    for (int i = 0; i < a.r; i++)
    {
        out << a.m[i][0] << " ";
        for (int j = 1; j < a.m[i][0] * 2 + 1; j++)
        {
            out << a.m[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

void displaymatrix(int rows, int col, int **mat)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int rows, col;
    cout << "Enter the rows and columns respectively: ";
    cin >> rows;
    cin >> col;
    int **mat;
    mat = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        *(mat + i) = new int[col];
    }
    cout << "Enter the values for the matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << "The first matrix is: " << endl;
    displaymatrix(rows, col, mat);
    sparsematrix m1(rows, col, mat);
    cout << m1;
    cout << "After incrementing: " << endl;
    ++m1;
    cout << m1;
}
