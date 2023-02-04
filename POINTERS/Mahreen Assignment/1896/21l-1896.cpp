#include <iostream>
#include <fstream>
using namespace std;

void DATAENTRY(int **&MATRIX, int **&HEHE, int &R1, int &C1, int **&MATRIX2, int **&HEHE2, int &R2, int &C2)
{
    char NAAM[100];
    int n = 0;
    ifstream fin("MAHI.txt");
    fin >> n;
    R1 = n;
    fin >> n;
    C1 = n;
    HEHE = new int *[R1];
    MATRIX = new int *[R1];
    for (int q = 0; q < R1; q++)
    {
        fin >> n;
        HEHE[q] = new int[n + 1];
        MATRIX[q] = new int[n];
        HEHE[q][0] = n;
        for (int o = 0, p = 1, y = 0, m = n; o < m * 2; o++)
        {
            fin >> n;
            if (o % 2 == 0)
            {
                HEHE[q][p] = n;
                p++;
            }
            else if (o % 2 == 1)
            {
                MATRIX[q][y] = n;
                y++;
            }
        }
    }
    cout << R2 << endl;
    cout << C2;
    fin >> n;
    R2 = n;
    fin >> n;
    C2 = n;
    HEHE2 = new int *[R2];
    MATRIX2 = new int *[R2];
    for (int q = 0; q < R2; q++)
    {
        fin >> n;
        HEHE2[q] = new int[n + 1];
        MATRIX2[q] = new int[n];
        HEHE2[q][0] = n;
        for (int o = 0, p = 1, y = 0, m = n; o < m * 2; o++)
        {
            fin >> n;
            if (o % 2 == 0)
            {
                HEHE2[q][p] = n;
                p++;
            }
            else if (o % 2 == 1)
            {
                MATRIX2[q][y] = n;
                y++;
            }
        }
    }
}

void DATACOUT(int **MATRIX, int R1, int C1, int **HEHE)
{

    for (int q = 0; q < R1; q++)
    {
        for (int o = 0, p = 1; o < C1; o++)
        {
            if (HEHE[q][p] == o)
            {
                cout << MATRIX[q][p - 1] << "  ";
                p++;
            }
            else
                cout << 0 << "  ";
        }
        cout << endl;
    }
}

int **addition(int **mat1, int row1, int col1, int **HEHE1, int **MATRIX2, int R2, int C2, int **HEHE2, int **&HEHE3)
{
    int **ANSWER = nullptr;
    int counter = 0, flag = 0, flag2 = 0;
    if (row1 == R2 && col1 == C2)
    {
        HEHE3 = new int *[row1];
        ANSWER = new int *[row1];
        for (int q = 0; q < row1; q++)
        {
            counter = HEHE1[q][0] + HEHE2[q][0];
            for (int o = 1; o <= HEHE1[q][0]; o++)
            {
                for (int k = 1; k <= HEHE2[q][0]; k++)
                {
                    if (HEHE1[q][o] == HEHE2[q][k])
                        counter--;
                }
            }
            HEHE3[q] = new int[counter + 1];
            ANSWER[q] = new int[counter];
            HEHE3[q][0] = counter;
        }
        for (int q = 0; q < row1; q++)
        {
            for (int o = 0, l = 0, y = 1, p = 1, bump = 1; o < col1; o++)
            {
                if (HEHE1[q][p] == o && HEHE2[q][y] == o)
                {
                    HEHE3[q][bump] = o;
                    ANSWER[q][l] = mat1[q][p - 1] + MATRIX2[q][y - 1];
                    p++;
                    l++;
                    HEHE3[q][bump] = o;
                    y++;
                    bump++;
                }
                else if (HEHE1[q][p] == o)
                {
                    HEHE3[q][bump] = o;
                    ANSWER[q][l] = mat1[q][p - 1];
                    p++;
                    bump++;
                    l++;
                }
                else if (HEHE2[q][y] == o)
                {
                    ANSWER[q][l] = MATRIX2[q][y - 1];
                    HEHE3[q][bump] = o;
                    bump++;
                    y++;
                    l++;
                }
            }
        }
    }
    return ANSWER;
}

int main()
{

    int check = 0, **ANSWER = nullptr, **HEHE3 = nullptr;
    int **MATRIX = nullptr, **HEHE = nullptr, R1 = 0, C1 = 0;
    int **MATRIX2 = nullptr, **HEHE2 = nullptr, R2 = 0, C2 = 0;
    DATAENTRY(MATRIX, HEHE, R1, C1, MATRIX2, HEHE2, R2, C2);
    cout << "Matrix 1 is as follows: " << endl;
    DATACOUT(MATRIX, R1, C1, HEHE);
    cout << endl;
    cout << "Matrix 2 is as follows: " << endl;
    DATACOUT(MATRIX2, R2, C2, HEHE2);
    cout << endl;
    cout << "The addition of the matrices is: " << endl;
    ANSWER = addition(MATRIX, R1, C1, HEHE, MATRIX2, R2, C2, HEHE2, HEHE3);
    DATACOUT(ANSWER, R1, C1, HEHE3);

    return 0;
}