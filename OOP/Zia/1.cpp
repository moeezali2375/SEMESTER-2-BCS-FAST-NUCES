#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char substring[1000];
    cout << "Enter the substring: ";
    cin >> substring;
    int length_of_substring = strlen(substring);
    ifstream fin("input.txt");
    int r;
    fin >> r;
    char **data = new char *[r];
    char temp[1000];
    fin.getline(temp, 0);
    for (int i = 0; i < r; i++)
    {
        fin.getline(temp, 1000);
        int c = strlen(temp);
        data[i] = new char[c];
        strcpy(data[i], temp);
        for (int j = 0; j < c; j++)
        {
            if (substring[0] == data[i][j])
            {
                int flag = 0;
                int k;
                int o;
                for (k = j, o = 0; k < c && o < length_of_substring; k++, o++)
                {
                    if (data[i][k] != substring[o])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << "Found at Row " << i << " starting at column " << j << " and ending at col " << j + length_of_substring - 1 << endl;
                    break;
                }
            }
        }
    }
}