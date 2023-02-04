#include <iostream>
#include <fstream>
using namespace std;
void display(int **matrix1, int **index, int row, int col);
void Dataentry(int **&matrix1, int **&index, int &row, int &col, int key);
int **Transpose(int **mat, int row, int col, int **index, int **&index_res, int bot);
int **Add(int **matrix1, int **matrix2, int **index1, int **index2, int **&index3, int row1, int row2, int col1, int col2);

int **Transpose(int **mat, int row, int col, int **index, int **&index_res, int bot)
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
    if (bot == 1)
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

void Dataentry(int **&matrix1, int **&index, int &row, int &col, int key)
{
    int nzc;
    ifstream fin("1798.txt");
    int num;

    if (key == 1)
    {
        fin >> row;
        fin >> col;
        matrix1 = new int *[row];
        index = new int *[row];
        int x = 0;
        while (x < row)
        {

            fin >> nzc;
            index[x] = new int[nzc + 1];
            matrix1[x] = new int[nzc];
            index[x][0] = nzc;
            int m = nzc, b = 0;
            while (b < m)
            {
                fin >> index[x][b + 1];
                fin >> matrix1[x][b];
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
        matrix1 = new int *[row];
        index = new int *[row];
        x = 0;
        while (x < row)
        {

            fin >> nzc;
            index[x] = new int[nzc + 1];
            matrix1[x] = new int[nzc];
            index[x][0] = nzc;
            int m = nzc, b = 0;
            while (b < m)
            {
                fin >> index[x][b + 1];
                fin >> matrix1[x][b];
                b++;
            }
            x++;
        }
    }
}

void display(int **matrix1, int **index, int row, int col)
{

    for (int x = 0; x < row; x++)
    {
        for (int y = 0, a = 1; y < col; y++)
        {
            if (index[x][a] == y)
            {
                cout << matrix1[x][a - 1] << "  ";
                a++;
            }
            else
                cout << 0 << "  ";
        }
        cout << endl;
    }
}

int **Add(int **matrix1, int **matrix2, int **index1, int **index2, int **&index3, int row1, int row2, int col1, int col2)
{
    int **answer = nullptr;
    int ctr = 0;

    if (col1 != col2 || row1 != row2)
    {
        cout << "Not Possible As Rows and columns are not equal for both Matrix" << endl;
        return nullptr;
    }
    else
    {
        index3 = new int *[row1];
        answer = new int *[row1];

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
            answer[a] = new int[ctr];
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
                    answer[a][l] = matrix1[a][x - 1] + matrix2[a][y - 1];
                    index3[a][z] = b;
                    x++;
                    l++;
                    y++;
                    z++;
                }

                else if (index1[a][x] == b)
                {
                    index3[a][z] = b;
                    answer[a][l] = matrix1[a][x - 1];
                    x++;
                    z++;
                    l++;
                }

                else if (index2[a][y] == b)
                {
                    index3[a][z] = b;
                    answer[a][l] = matrix2[a][y - 1];
                    z++;
                    y++;
                    l++;
                }
                b++;
            }
        }
        return answer;
    }
}

int main()
{

    int bot = 0;
    int **answer = nullptr;
    int **residx = nullptr;
    int selection = 0;
    int **matrix1 = nullptr;
    int **index = nullptr;
    int row = 0, col = 0;
    int **matrix2 = nullptr;
    int **index2 = nullptr;
    int row2 = 0, col2 = 0;
    int key1 = 1;
    int key2 = 2;
    Dataentry(matrix1, index, row, col, key1);
    cout << "Matrix" << endl;
    display(matrix1, index, row, col);

    cout << endl
         << endl;
    Dataentry(matrix2, index2, row2, col2, key2);

    cout << endl;
a:
    cout << "Please select a choice:" << endl;
    cout << "Press 1 for addition of the matrices!" << endl;
    cout << "Or Press 2 for transpose of the matrices!" << endl;
    cin >> selection;
    cout << endl;
    if (selection == 1)
    {
        cout<<"Fetching data for the 2nd matrix from the file....."<<endl;
        cout << "Matrix 2" << endl;
        display(matrix2, index2, row2, col2);
        answer = Add(matrix1, matrix2, index, index2, residx, row, row2, col, col2);
        if (answer != nullptr)
        {
            cout << endl
                 << "The addition of the matrices is: " << endl;
            display(answer, residx, row, col);
        }
    }
    else if (selection == 2)
    {
        answer = Transpose(matrix1, row, col, index, residx, bot);
        cout << endl
             << "The Transpose is: " << endl;
        display(answer, residx, row, col);
    }
    else
    {
        goto a;
    }
    delete[] answer;
    delete[] residx;
    delete[] matrix1;
    delete[] index;
    delete[] matrix2;
    delete[] index2;

    answer = nullptr;
    residx = nullptr;
    matrix1 = nullptr;
    index = nullptr;
    matrix2 = nullptr;
    index2 = nullptr;
    cout << endl;
    return 0;
}