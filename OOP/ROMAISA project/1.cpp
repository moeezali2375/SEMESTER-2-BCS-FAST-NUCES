#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
void expose_zero_cells(int x, int c, int rows, int cols, int r[][9], int b[][9])
{
    if (x < rows && x >= 0 && c < cols && c >= 0 && b[x][c] != -1&&r[x][c]==9)
    {
        r[x][c] = b[x][c];
        if (b[x][c] == 0)
        {
            expose_zero_cells(x + 1, c, rows, cols, r, b);
            expose_zero_cells(x - 1, c, rows, cols, r, b);
            expose_zero_cells(x, c + 1, rows, cols, r, b);
            expose_zero_cells(x, c - 1, rows, cols, r, b);
            expose_zero_cells(x + 1, c + 1, rows, cols, r, b);
            expose_zero_cells(x - 1, c - 1, rows, cols, r, b);
            expose_zero_cells(x + 1, c - 1, rows, cols, r, b);
            expose_zero_cells(x - 1, c + 1, rows, cols, r, b);
        }
    }
}
class game
{
public:
    virtual void print()
    {
    }
    virtual void allocatemines()
    {
    }
};
class easy : public game
{
    int b[9][9];
    int r[9][9];
    int rows;
    int cols;

public:
    easy()
    {
        rows = 9;
        cols = 9;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                b[i][j] = r[i][j] = 9;
            }
        }
        Allocatemines();
        Allocatenumbers();
    }
    void Allocatemines()
    {
        srand(time(0));
        for (int j = 0; j < 10; j++)
        {
            b[rand() % (rows - 1)][rand() % (cols - 1)] = -1;
        }
    }
    void Allocatenumbers()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (b[i][j] != -1)
                {
                    b[i][j] = findnum(i, j);
                }
            }
        }
    }
    int findnum(int r, int c)
    {
        int count = 0;

        if (r < rows - 1 && b[r + 1][c] == -1)
            count++;
        if (r > 0 && b[r - 1][c] == -1)
            count++;
        if (c < cols - 1 && b[r][c + 1] == -1)
            count++;
        if (c > 0 && b[r][c - 1] == -1)
            count++;
        if (c < cols - 1 && r < rows - 1 && b[r + 1][c + 1] == -1)
            count++;
        if (c > 0 && r > 0 && b[r - 1][c - 1] == -1)
            count++;
        if (r > 0 && c < cols - 1 && b[r - 1][c + 1] == -1)
            count++;
        if (c > 0 && r < rows - 1 && b[r + 1][c - 1] == -1)
            count++;

        return count;
    }
    void printboard()
    {
        system("cls");

        cout << '\t';
        for (int i = 0; i < cols; i++)
        {
            cout << i + 1 << '\t';
        }
        cout << endl;
        for (int i = 0; i < rows; i++)
        {
            cout << i + 1 << '\t';
            for (int j = 0; j < cols; j++)
            {
                if (r[i][j] == -2)
                    cout << "F" << '\t';
                else if (r[i][j] == 9)
                    cout << "X" << '\t';
                else
                    cout << r[i][j] << '\t';
            }
            cout << endl;
        }
    }

    void updateboard(int x, int y, bool l, bool &c)
    {
        // left click l=0, right click l=1
        if (l == 0)
        {
            if (r[x][y] == -2)
            {
                r[x][y] = 9;
            }
            if (b[x][y] == -1)
            {
                r[x][y] = -1;
                printboard();
                system("cls");
                c = 0;
                cout << "-------GAME OVER-------";
            }
            else if (r[x][y] == 9)
            {
                // r[x][y] = b[x][y];
                // printboard();
                // cout << "Blabla";
                // if (b[x][y] == 0)
                expose_zero_cells(x, y, rows, cols, r, b);
            }
        }
        else
        {
            r[x][y] = -2; //-2 for flagged cell
        }
    }
};
class medium : public game
{
    int b[16][16];
    int r[16][16];
    int rows;
    int cols;

public:
    medium()
    {
        rows = 16;
        cols = 16;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                b[i][j] = r[i][j] = 9;
            }
        }
        Allocatemines();
        Allocatenumbers();
    }
    void Allocatemines()
    {
        srand(time(0));
        for (int j = 0; j < 10; j++)
        {
            b[rand() % (rows - 1)][rand() % (cols - 1)] = -1;
        }
    }
    void Allocatenumbers()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (b[i][j] != -1)
                {
                    b[i][j] = findnum(i, j);
                }
            }
        }
    }
    int findnum(int r, int c)
    {
        int count = 0;

        if (r < rows - 1 && b[r + 1][c] == -1)
            count++;
        if (r > 0 && b[r - 1][c] == -1)
            count++;
        if (c < cols - 1 && b[r][c + 1] == -1)
            count++;
        if (c > 0 && b[r][c - 1] == -1)
            count++;
        if (c < cols - 1 && r < rows - 1 && b[r + 1][c + 1] == -1)
            count++;
        if (c > 0 && r > 0 && b[r - 1][c - 1] == -1)
            count++;
        if (r > 0 && c < cols - 1 && b[r - 1][c + 1] == -1)
            count++;
        if (c > 0 && r < rows - 1 && b[r + 1][c - 1] == -1)
            count++;

        return count;
    }
    void printboard()
    {
        system("cls");
        cout << '\t';
        for (int i = 0; i < cols; i++)
        {
            cout << i + 1 << '\t';
        }
        cout << endl;
        for (int i = 0; i < rows; i++)
        {
            cout << i + 1 << '\t';
            for (int j = 0; j < cols; j++)
            {
                /*if (r[i][j] == -2)
                    cout << "F" << '\t';
                else if (r[i][j] == 9)
                    cout << "X" << '\t';
                else*/
                cout << r[i][j] << '\t';
            }
            cout << endl;
        }
        // Sleep(2000); /
    }
    void expose_zero_cells(int r, int c)
    {

        if (r < rows - 1)
        {
            b[r + 1][c] = findnum(r + 1, c);
            // printboard(); /
            if (b[r + 1][c] == 0)
                expose_zero_cells(r + 1, c);
        }
        if (r > 0)
        {
            b[r - 1][c] = findnum(r - 1, c);
            // printboard(); /
            if (b[r - 1][c] == 0)
                expose_zero_cells(r - 1, c);
        }
        if (c < cols - 1)
        {
            b[r][c + 1] = findnum(r, c + 1);
            // printboard(); /
            if (b[r][c + 1] == 0)
                expose_zero_cells(r, c + 1);
        }
        if (c > 0)
        {
            b[r][c - 1] = findnum(r, c - 1);
            // printboard(); /
            if (b[r][c - 1] == 0)
                expose_zero_cells(r, c - 1);
        }
        if (c < cols - 1 && r < rows - 1)
        {
            b[r + 1][c + 1] = findnum(r + 1, c + 1);
            // printboard(); /
            if (b[r + 1][c + 1] == 0)
                expose_zero_cells(r + 1, c + 1);
        }
        if (c > 0 && r > 0)
        {
            b[r - 1][c - 1] = findnum(r - 1, c - 1);
            // printboard(); /
            if (b[r - 1][c - 1] == 0)
                expose_zero_cells(r - 1, c - 1);
        }
        if (r > 0 && c < cols - 1)
        {
            b[r - 1][c + 1] = findnum(r - 1, c + 1);
            // printboard(); /
            if (b[r - 1][c + 1] == 0)
                expose_zero_cells(r - 1, c + 1);
        }
        if (c > 0 && r < rows - 1)
        {
            b[r + 1][c - 1] = findnum(r + 1, c - 1);
            // printboard(); /
            if (b[r + 1][c - 1] == 0)
                expose_zero_cells(r + 1, c - 1);
        }
    }
    void updateboard(int x, int y, bool l, bool &c)
    {
        // left click l=0, right click l=1
        if (l == 0)
        {
            if (r[x][y] == -2)
            {
                r[x][y] = 9;
            }
            else if (b[x][y] == -1)
            {
                r[x][y] = -1;
                printboard();
                c = 0;
                cout << "-------GAME OVER-------";
            }
            else
            {
                r[x][y] = b[x][y];
                // if (b[x][y] == 0)
                // expose_zero_cells(x, y);
            }
        }
        else
        {
            r[x][y] = -2; //-2 for flagged cell
        }
    }
};
class difficult : public game
{
    int b[16][30];
    int r[16][30];
    int rows;
    int cols;

public:
    difficult()
    {
        rows = 16;
        cols = 30;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                b[i][j] = r[i][j] = 9;
            }
        }
        Allocatemines();
        Allocatenumbers();
    }
    void Allocatemines()
    {
        srand(time(0));
        for (int j = 0; j < 10; j++)
        {
            b[rand() % (rows - 1)][rand() % (cols - 1)] = -1;
        }
    }
    void Allocatenumbers()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (b[i][j] != -1)
                {
                    b[i][j] = findnum(i, j);
                }
            }
        }
    }
    int findnum(int r, int c)
    {
        int count = 0;

        if (r < rows - 1 && b[r + 1][c] == -1)
            count++;
        if (r > 0 && b[r - 1][c] == -1)
            count++;
        if (c < cols - 1 && b[r][c + 1] == -1)
            count++;
        if (c > 0 && b[r][c - 1] == -1)
            count++;
        if (c < cols - 1 && r < rows - 1 && b[r + 1][c + 1] == -1)
            count++;
        if (c > 0 && r > 0 && b[r - 1][c - 1] == -1)
            count++;
        if (r > 0 && c < cols - 1 && b[r - 1][c + 1] == -1)
            count++;
        if (c > 0 && r < rows - 1 && b[r + 1][c - 1] == -1)
            count++;

        return count;
    }
    void printboard()
    {
        system("cls");
        cout << '\t';
        for (int i = 0; i < cols; i++)
        {
            cout << i + 1 << '\t';
        }
        cout << endl;
        for (int i = 0; i < rows; i++)
        {
            cout << i + 1 << '\t';
            for (int j = 0; j < cols; j++)
            {
                /*if (r[i][j] == -2)
                    cout << "F" << '\t';
                else if (r[i][j] == 9)
                    cout << "X" << '\t';
                else*/
                cout << r[i][j] << '\t';
            }
            cout << endl;
        }
    }
    void expose_zero_cells(int r, int c)
    {

        if (r < rows - 1)
        {
            b[r + 1][c] = findnum(r + 1, c);
            // printboard(); /
            if (b[r + 1][c] == 0)
                expose_zero_cells(r + 1, c);
        }
        if (r > 0)
        {
            b[r - 1][c] = findnum(r - 1, c);
            // printboard(); /
            if (b[r - 1][c] == 0)
                expose_zero_cells(r - 1, c);
        }
        if (c < cols - 1)
        {
            b[r][c + 1] = findnum(r, c + 1);
            // printboard(); /
            if (b[r][c + 1] == 0)
                expose_zero_cells(r, c + 1);
        }
        if (c > 0)
        {
            b[r][c - 1] = findnum(r, c - 1);
            // printboard(); /
            if (b[r][c - 1] == 0)
                expose_zero_cells(r, c - 1);
        }
        if (c < cols - 1 && r < rows - 1)
        {
            b[r + 1][c + 1] = findnum(r + 1, c + 1);
            // printboard(); /
            if (b[r + 1][c + 1] == 0)
                expose_zero_cells(r + 1, c + 1);
        }
        if (c > 0 && r > 0)
        {
            b[r - 1][c - 1] = findnum(r - 1, c - 1);
            // printboard(); /
            if (b[r - 1][c - 1] == 0)
                expose_zero_cells(r - 1, c - 1);
        }
        if (r > 0 && c < cols - 1)
        {
            b[r - 1][c + 1] = findnum(r - 1, c + 1);
            // printboard(); /
            if (b[r - 1][c + 1] == 0)
                expose_zero_cells(r - 1, c + 1);
        }
        if (c > 0 && r < rows - 1)
        {
            b[r + 1][c - 1] = findnum(r + 1, c - 1);
            // printboard(); /
            if (b[r + 1][c - 1] == 0)
                expose_zero_cells(r + 1, c - 1);
        }
    }
    void updateboard(int x, int y, bool l, bool &c)
    {
        // left click l=0, right click l=1
        if (l == 0)
        {
            if (r[x][y] == -2)
            {
                r[x][y] = 9;
            }
            else if (b[x][y] == -1)
            {
                r[x][y] = -1;
                printboard();
                system("cls");
                c = 0;
                cout << "-------GAME OVER-------";
            }
            else if (r[x][y] == 9)
            {
                r[x][y] = b[x][y];
                cout << "blabla";
                // if (b[x][y] == 0)
                // expose_zero_cells(x, y);
            }
        }
        else
        {
            r[x][y] = -2; //-2 for flagged cell
        }
    }
};

class movement
{
    int x;
    int y;
    bool l;

public:
    movement()
    {
        x = 0;
        y = 0;
        l = 0;
    }
    void move(int x_axis, int y_axis, bool flag, easy &b, bool &c)
    {
        x = x_axis;
        y = y_axis;
        l = flag;
        b.easy::updateboard(x, y, l, c);
    }
};

int main()
{
    easy x;
    x.printboard();
    // x.revealboard();
    int a, b;
    char m;
    bool flag;
    movement mov;
    bool c = 1; // win checker

    while (c)
    {
        x.printboard();
        cout << "Enter coordinates you want to make a movement on" << endl;
        cout << "Enter row: ";
        cin >> a;
        cout << "Enter column: ";
        cin >> b;
        cout << "Enter l or r (l=expose cell and r=flag cell)";
        cin >> m;
        if (m == 'l')
        {
            flag = 0;
            mov.move(a - 1, b - 1, flag, x, c);
        }
        x.printboard();
    }

    return 0;
}