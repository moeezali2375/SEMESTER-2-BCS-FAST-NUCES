#include <iostream>
#include <string.h>
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
    // cout << temp << endl;
    str1 = temp;
}
char **inverse_string_tokens(char *array, int &count)
{
    int spaces = 0;
    for (int i = 0; i < strlen(array); i++)
    {
        if (array[i] == ' ')
            spaces++;
    }
    spaces++;
    count = spaces;
    char **words = new char *[spaces];
    int start = 0;
    int end = 0;
    int word_counter = spaces - 1;
    for (int i = 0; i < strlen(array) + 1; i++)
    {
        if (array[i] == ' ' || array[i] == 0)
        {
            end = i; //! start to be updated
            words[word_counter] = new char[end - start];
            int word_iterator = 0;
            for (int j = start; j < end; j++)
            {
                words[word_counter][word_iterator++] = array[j];
            }
            words[word_counter--][word_iterator] = 0;
            start = end + 1;
        }
    }
    return words;
}
char *merger(char **str, char *array, int count)
{
    char *temp = str[0];
    char array2[] = " ";
    for (int i = 1; i < count; i++)
    {
        string_concatenate(temp, array2);
        string_concatenate(temp, str[i]);
    }
    cout << temp;
    return temp;
}
int main()
{
    char array[] = "I am Pakistani";
    int count;
    char **ptr;
    ptr = inverse_string_tokens(array, count);

    merger(ptr, array, count);
}