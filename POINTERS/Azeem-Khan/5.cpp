#include <iostream>
using namespace std;
int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != 0)
    {
        i++;
    }
    return i;
}
void sort(char *str1)
{
    for (int i = 1; i < my_strlen(str1); i++)
    {
        int j = i;
        while (str1[j] < str1[j - 1])
        {
            swap(str1[j], str1[j - 1]);
            j--;
        }
    }
}
int compare_string(char *str1, char *str2)
{
    sort(str1);
    sort(str2);

    if (my_strlen(str1) == my_strlen(str2))
    {
        int flag = 0;
        for (int i = 0; i < my_strlen(str1); i++)
        {
            if (str1[i] != str2[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return flag;
    }
    if (my_strlen(str1) < my_strlen(str2))
        return -1;
    return 1;
}
int main()
{
    char str1[] = "hellomynameis";
    char str2[] = "ellomynameis";
    cout<<compare_string(str1, str2);
}