#include <iostream>
using namespace std;
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
    int word_counter = spaces-1;
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
int main()
{
    char array[] = "I am a student of OOP in FAST-NU";
    int count;
    char **ptr;
    ptr = inverse_string_tokens(array, count);
    for (int i = 0; i < count; i++)
    {
        cout << ptr[i] << endl;
    }
}