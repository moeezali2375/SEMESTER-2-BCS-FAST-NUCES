#include <iostream>
using namespace std;
class text_msg
{
    char *msg;

public:
    text_msg()
    {
        msg = NULL;
    }
    void add(char array[])
    {
        int l = strlen(array);
        if (msg != NULL)
        {
            int t_l = strlen(msg);
            char *new_array = new char[strlen(msg) + l];
            for (int i = 0; i < t_l; i++)
                new_array[i] = msg[i];
            for (int i = 0; i < l; i++)
                new_array[t_l++] = array[i];
            delete[] msg;
            msg = new_array;
        }
        else
        {
            msg = new char[l];
            strcpy(msg, array);
        }
    }
    void display_msg()
    {
        cout << msg << endl;
    }
};

class video_msg
{
    char *filename;
    int duration;

public:
    video_msg()
    {
        filename = NULL;
    }
    void add(char array[], int d)
    {
        duration = d;
        if (filename == NULL)
            filename = new char[strlen(array)];
        else
            delete[] filename;
        strcpy(filename, array);
    }
};
int main()
{
}