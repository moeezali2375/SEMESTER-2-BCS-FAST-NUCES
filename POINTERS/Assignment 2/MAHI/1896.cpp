
#include <iostream>
#include <fstream>
using namespace std;

void Output(int **spmat, int **index, int row, int col)
{

    for (int x = 0; x < row; x++)
    {
        for (int y = 0, a = 1; y < col; y++)
        {
            if (index[x][a] == y)
            {
                cout << spmat[x][a - 1] << "  ";
                a++;
            }
            else
                cout << 0 << "  ";
        }
        cout << endl;
    }
}

void Input(int **&spmat, int **&index, int &row, int &col, int key)
{
    int nzc;
    ifstream fin("1896.txt");
    int num;

    if (key == 1)
    {
        fin >> row;
        fin >> col;
        spmat = new int *[row];
        index = new int *[row];
        int x = 0;
        while (x < row)
        {

            fin >> nzc;
            index[x] = new int[nzc + 1];
            spmat[x] = new int[nzc];
            index[x][0] = nzc;
            int m = nzc, b = 0;
            while (b < m)
            {
                fin >> index[x][b + 1];
                fin >> spmat[x][b];
                b++;
            }
            x++;
        }
    }
    else if (key == 2)
    {
        char temp[100];
        int skiprows = 0;
        fin >> skiprows;
        int x = 0;
        while (x <= skiprows)
        {
            fin.getline(temp, 99, '\n');
            x++;
        }
        fin >> row;
        fin >> col;
        spmat = new int *[row];
        index = new int *[row];
        x = 0;
        while (x < row)
        {

            fin >> nzc;
            index[x] = new int[nzc + 1];
            spmat[x] = new int[nzc];
            index[x][0] = nzc;
            int m = nzc, b = 0;
            while (b < m)
            {
                fin >> index[x][b + 1];
                fin >> spmat[x][b];
                b++;
            }
            x++;
        }
    }
}

int **Transpose(int **mat, int row, int col, int **index, int **&index_res, int check)
{
    int **result_transp = new int *[row];
    int size = 0, j = 0, y = 1, z = 0, count = 0;
    ;
    for (int i = 0; i < row; i++)
        size += index[i][0];
    int **transp = new int *[size];
    int **transp2 = new int *[size];
    for (int i = 0; i < size; i++)
    {
        transp[i] = new int[3];
        transp2[i] = new int[3];
    }
    z = index[0][0];
    y = 1;
    for (int i = 0; i < size; i++)
    {
    a:
        if (z == 0 && j < row)
        {

            j++;
            if (j >= row)
                goto out;
            y = 1;
            z = index[j][0];
            if (z == 0)
                goto a;
        }
        transp[i][0] = j;
        transp[i][1] = index[j][y];
        transp[i][2] = mat[j][y - 1];
        z--;
        y++;
    }
out:;

    int k = 0;
    for (int i = 0; i < col; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (transp[j][1] == i)
            {
                transp2[k][0] = transp[k][1];
                transp2[k][1] = transp[k][0];
                transp2[k][2] = transp[k][2];
                k++;
            }
        }
    }
    index_res = new int *[row];
    for (int i = 0; i < row; i++)
    {
        count = 0;
        for (int j = 0; j < size; j++)
        {
            if (transp2[j][0] == i)
                count++;
        }
        index_res[i] = new int[count + 1];
        result_transp[i] = new int[count];
        index_res[i][0] = count;
        count = 0;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0, x = 1; j < size; j++)
        {
            if (transp2[j][0] == i)
            {
                index_res[i][x] = transp2[j][1];
                result_transp[i][x - 1] = transp2[j][2];
                x++;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        delete[] transp[i];
        delete[] transp2[i];
    }
    delete[] transp;
    delete[] transp2;
    if (check == 1)
    {
        for (int i = 0; i < col; i++)
        {
            for (int l = 1; l < index_res[i][0] + 1; l++)
            {
                index_res[i][l] -= 1;
            }
            cout << endl;
        }
    }
    return result_transp;
}

int **Add(int **spmat1, int **spmat2, int **index1, int **index2, int **&index3, int row1, int row2, int col1, int col2)
{
    int **ans = nullptr;
    int ctr = 0;

    if (col1 != col2 || row1 != row2)
    {
        cout << "Not Possible As Rows and columns are not equal for both Matrix" << endl;
        return nullptr;
    }
    else
    {
        index3 = new int *[row1];
        ans = new int *[row1];

        for (int a = 0; a < row1; a++)
        {
            ctr = index1[a][0] + index2[a][0];

            for (int b = 1; b <= index1[a][0]; b++)
            {
                int t = 1;
                while (t <= index2[a][0])
                {
                    if (index1[a][b] == index2[a][t])
                        ctr--;
                    t++;
                }
            }
            index3[a] = new int[ctr + 1];
            ans[a] = new int[ctr];
            index3[a][0] = ctr;
        }
        for (int a = 0; a < row1; a++)
        {
            int l = 0;
            int y = 1;
            int x = 1, z = 1;
            int b = 0;
            while (b < col1)
            {

                if (index1[a][x] == b && index2[a][y] == b)
                {
                    index3[a][z] = b;
                    ans[a][l] = spmat1[a][x - 1] + spmat2[a][y - 1];
                    index3[a][z] = b;
                    x++;
                    l++;
                    y++;
                    z++;
                }

                else if (index1[a][x] == b)
                {
                    index3[a][z] = b;
                    ans[a][l] = spmat1[a][x - 1];
                    x++;
                    z++;
                    l++;
                }

                else if (index2[a][y] == b)
                {
                    index3[a][z] = b;
                    ans[a][l] = spmat2[a][y - 1];
                    z++;
                    y++;
                    l++;
                }
                b++;
            }
        }
        return ans;
    }
}

int main()
{

    int check = 0;
    int **ans = nullptr;
    int **residx = nullptr;
    int selection = 0;
    int **spmat = nullptr;
    int **index = nullptr;
    int row = 0, col = 0;
    int **spmat2 = nullptr;
    int **index2 = nullptr;
    int row2 = 0, col2 = 0;
    int key1 = 1;
    int key2 = 2;
    Input(spmat, index, row, col, key1);
    cout << "Matrix" << endl;
    Output(spmat, index, row, col);

    cout << endl
         << endl;
    Input(spmat2, index2, row2, col2, key2);

    cout << endl;
a:
    cout << "Enter:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Transpose" << endl;
    cin >> selection;
    cout << endl;
    if (selection == 1)
    {
        cout << "Matrix 2" << endl;
        Output(spmat2, index2, row2, col2);
        ans = Add(spmat, spmat2, index, index2, residx, row, row2, col, col2);
        if (ans != nullptr)
        {
            cout << endl
                 << "Answer is:" << endl;
            Output(ans, residx, row, col);
        }
    }
    else if (selection == 2)
    {
        ans = Transpose(spmat,row, col, index, residx,check);
        cout << endl
             << "The Transpose is: " << endl;
        Output(ans, residx, row, col);
    }
    else
    {
        goto a;
    }
    delete[] ans;
    delete[] residx;
    delete[] spmat;
    delete[] index;
    delete[] spmat2;
    delete[] index2;

    ans = nullptr;
    residx = nullptr;
    spmat = nullptr;
    index = nullptr;
    spmat2 = nullptr;
    index2 = nullptr;
    cout << endl;
    return 0;
}