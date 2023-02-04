#include <iostream>
using namespace std;
class String
{
    char *array;
    int size;

public:
    String()
    {
        array = NULL;
        size = 0;
    }
    String(int size)
    {
        array = NULL;
        this->size = size;
        array = new char[size];
    }
    String(String &a)
    {
        array = new char[a.size];
        for (int i = 0; i < a.size; i++)
        {
            array[i] = a.array[i];
        }
        size = a.size;
    }
    ~String()
    {
        if (size != 0)
        {
            delete[] array;
            size = 0;
        }
    }
    void set(int size)
    {
        this->size = size;
        delete[] array;
        array = new char[size];
    }
    void set1(int position, char a)
    {
        if (position >= 0 && position < size)
        {
            array[position] = a;
        }
    }
    void set_string(char string_copy[])
    {
        int i = 0;
        while (string_copy[i] != 0)
        {
            array[i] = string_copy[i];
            i++;
        }
    }
    char get_char(int position)
    {
        if (position >= 0 && position < size)
        {
            return array[position];
        }
        return 0;
    }
    char *get_array()
    {
        return array;
    }
    int get_size()
    {
        return size;
    }
    int str_length()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (array[i] == 0)
                break;
            count++;
        }
        return count;
    }
    // FUNCTIONS
};
int word_calculator(String &a, char **&words_array)
{
    char **words = new char *[100];
    for (int i = 0; i < 100; i++)
    {
        words[i] = new char[100];
    }

    int word_no = 0;
    char *copy = a.get_array();
    for (int i = 0; i < a.str_length(); i++)
    {
        if (copy[i] >= 'a' || copy[i] >= 'A' && copy[i] <= 'z' && copy[i] <= 'Z')
        {
            int j = i;
            // while (copy[j] >= 'a' || copy[j] >= 'A' && copy[j] <= 'z' && copy[j] <= 'Z')
            while (copy[j] != ' ' && copy[j] != 0)
                j++;
            int k = 0;
            while (j != i)
            {
                words[word_no][k] = copy[i++];
                k++;
            }
            words[word_no++][k] = 0;
        }
    }
    words_array = words;
    // // DISPLAY
    // for (int i = 0; i < word_no; i++)
    // {
    //     cout << "Word" << i + 1 << ": " << words[i] << endl;
    // }
    return word_no;
}

void uni_words(char **words_array, int &words, int &words3)
{
    words3 = words;
    char **bi;
    bi = new char *[100];
    for (int i = 0; i < 100; i++)
        bi[i] = new char[100];
    int k = 0;
    for (int i = 0; i < words; i++)
    {
        int counter = 0;

        for (int j = 0; j < words; j++)
        {
            if (words_array[i][j] == '-')
                counter++;
        }
        if (counter == 0)
        {
            strcpy(bi[k++], words_array[i]);
        }
        delete[] words_array[i];
    }
    delete words_array;
    words = k;
    words_array = bi;
    // FREQUENCY
    int *frequency = new int[words];
    for (int i = 0; i < words; i++)
    {
        frequency[i] = 0;
        for (int j = 0; j < words; j++)
        {
            if (strcmp(words_array[i], words_array[j]) == 0)
                frequency[i]++;
        }
    }
    // SORT
    int words2 = words;
    for (int i = 0; i < words; i++)
    {
        int max = 0;
        for (int j = 0; j < words2; j++)
        {
            if (frequency[max] < frequency[j])
                max = j;
        }
        swap(frequency[max], frequency[words2 - 1]);
        swap(words_array[max], words_array[words2 - 1]);
        words2--;
    }
    // DELETE DUPLICATES
    for (int i = 0; i < words; i++)
    {
        for (int j = i + 1; j < words; j++)
        {
            if (frequency[i] == frequency[j] && strcmp(words_array[i], words_array[j]) == 0)
            {
                for (int k = j; k < words - 1; k++)
                {
                    frequency[k] = frequency[k + 1];
                    strcpy(words_array[k], words_array[k + 1]);
                }
                words--;
                j--;
            }
        }
    }
    // DISPLAY
    for (int i = 0; i < words; i++)
    {
        cout << "Word" << i + 1 << ": " << words_array[i] << endl;
        cout << "Frequency: " << frequency[i] << endl;
    }
}
void bi_words(char **words_array, int &words)
{
    char **bi;
    bi = new char *[100];
    for (int i = 0; i < 100; i++)
        bi[i] = new char[100];
    int k = 0;
    for (int i = 0; i < words; i++)
    {
        int counter = 0;

        for (int j = 0; j < words; j++)
        {
            if (words_array[i][j] == '-')
                counter++;
        }
        if (counter == 1)
        {
            strcpy(bi[k++], words_array[i]);
        }
        delete[] words_array[i];
    }
    delete words_array;
    words = k;
    words_array = bi;
    // FREQUENCY
    int *frequency = new int[words];
    for (int i = 0; i < words; i++)
    {
        frequency[i] = 0;
        for (int j = 0; j < words; j++)
        {
            if (strcmp(words_array[i], words_array[j]) == 0)
                frequency[i]++;
        }
    }
    // SORT
    int words2 = words;
    for (int i = 0; i < words; i++)
    {
        int max = 0;
        for (int j = 0; j < words2; j++)
        {
            if (frequency[max] < frequency[j])
                max = j;
        }
        swap(frequency[max], frequency[words2 - 1]);
        swap(words_array[max], words_array[words2 - 1]);
        words2--;
    }
    // DELETE DUPLICATES
    for (int i = 0; i < words; i++)
    {
        for (int j = i + 1; j < words; j++)
        {
            if (frequency[i] == frequency[j] && strcmp(words_array[i], words_array[j]) == 0)
            {
                for (int k = j; k < words - 1; k++)
                {
                    frequency[k] = frequency[k + 1];
                    strcpy(words_array[k], words_array[k + 1]);
                }
                words--;
                j--;
            }
        }
    }
    // DISPLAY
    for (int i = 0; i < words; i++)
    {
        cout << "Word" << i + 1 << ": " << words_array[i] << endl;
        cout << "Frequency: " << frequency[i] << endl;
    }
}
void tri_words(char **words_array, int &words)
{
    char **bi;
    bi = new char *[100];
    for (int i = 0; i < 100; i++)
        bi[i] = new char[100];
    int k = 0;
    for (int i = 0; i < words; i++)
    {
        int counter = 0;

        for (int j = 0; j < words; j++)
        {
            if (words_array[i][j] == '-')
                counter++;
        }
        if (counter == 2)
        {
            strcpy(bi[k++], words_array[i]);
        }
        delete[] words_array[i];
    }
    delete words_array;
    words = k;
    words_array = bi;
    // FREQUENCY
    int *frequency = new int[words];
    for (int i = 0; i < words; i++)
    {
        frequency[i] = 0;
        for (int j = 0; j < words; j++)
        {
            if (strcmp(words_array[i], words_array[j]) == 0)
                frequency[i]++;
        }
    }
    // SORT
    int words2 = words;
    for (int i = 0; i < words; i++)
    {
        int max = 0;
        for (int j = 0; j < words2; j++)
        {
            if (frequency[max] < frequency[j])
                max = j;
        }
        swap(frequency[max], frequency[words2 - 1]);
        swap(words_array[max], words_array[words2 - 1]);
        words2--;
    }
    // DELETE DUPLICATES
    for (int i = 0; i < words; i++)
    {
        for (int j = i + 1; j < words; j++)
        {
            if (frequency[i] == frequency[j] && strcmp(words_array[i], words_array[j]) == 0)
            {
                for (int k = j; k < words - 1; k++)
                {
                    frequency[k] = frequency[k + 1];
                    strcpy(words_array[k], words_array[k + 1]);
                }
                words--;
                j--;
            }
        }
    }
    // DISPLAY
    for (int i = 0; i < words; i++)
    {
        cout << "Word" << i + 1 << ": " << words_array[i] << endl;
        cout << "Frequency: " << frequency[i] << endl;
    }
}

int main()
{
    String a(1000);
    char test[] = "my name is slim shady is slim shady fuck-you fuck-you oh-shit not-good oh-yeah-hui he-he-boi he-he-boi";
    a.set_string(test);
    cout << "The length of the string is: " << a.str_length() << endl;
    int total_words;
    char **words_array;
    cout << "The number of words are: " << endl;
    total_words = word_calculator(a, words_array);
    cout << total_words << endl;
    int choice = -1;
    {
        cout << "1.Uni words\n";
        cout << "2.Bi words\n";
        cout << "3.Tri words\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Bari meherbani" << endl;
            break;
        case 1:
            int unique;
            uni_words(words_array, total_words, unique);
            cout << "Unique words are: " << unique;
            break;
        case 2:
            bi_words(words_array, total_words);
            break;
        case 3:
            tri_words(words_array, total_words);
            break;
        default:
            cout << "Please enter the correct choice! " << endl;
            break;
        }
    }
}