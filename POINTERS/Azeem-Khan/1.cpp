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
void string_concatenate(char *&str1, char *str2)
{
    int length = my_strlen(str1) + my_strlen(str2);
    char *temp = new char(length);
    int i = 0;
    while (i < my_strlen(str1))
    {
        temp[i] = str1[i];
        i++;
    }
    int k = 0;
    while (i < length)
    {
        temp[i] = str2[k];
        k++;
        i++;
    }
    // delete[] str1;
    str1 = temp;
}
int main()
{
    char str1[] = "My";
    char str2[] = " name is: &";
    char *ptr1 = str1;
    char *ptr2 = str2;
    string_concatenate(ptr1, ptr2);
    cout << ptr1;
}