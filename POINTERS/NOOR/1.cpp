#include <iostream>
using namespace std;

int main()
{
    int consonants = 0;
    int total_vowels = 0;
    char *str = new char[1000];
    char *vowels = new char[6];
    vowels[0] = 'a';
    vowels[1] = 'e';
    vowels[2] = 'i';
    vowels[3] = 'o';
    vowels[4] = 'u';
    int *vowels_counter = new int[6];
    for (int  i=0;i<5;i++)
    {
        vowels_counter[i]=0;
    }
    cout << "Please enter the string: " << endl;
    cin.getline(str, 1000);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a'||str[i]=='A')
        {
            vowels_counter[0]++;
            total_vowels++;
        }
        else if (str[i] == 'e'||str[i]=='E')
        {
            vowels_counter[1]++;
            total_vowels++;
        }
        else if (str[i] == 'i'||str[i]=='I')
        {
            vowels_counter[2]++;
            total_vowels++;
        }
        else if (str[i] == 'o'||str[i]=='O')
        {
            vowels_counter[3]++;
            total_vowels++;
        }
        else if (str[i] == 'u'||str[i]=='U')
        {
            vowels_counter[4]++;
            total_vowels++;
        }
        else if (str[i]>='a'||str[i]>='A'&&str[i]=='z'||str[i]=='Z')
            consonants++;
    }
    int max2 = 4;
    for (int i = 0; i <= 4; i++)
    {
        int min = 0;
        for (int j = 0; j <= max2; j++)
        {
            if (vowels_counter[min] >vowels_counter[j])
            {
                min = j;
            }
        }
        swap(vowels_counter[max2], vowels_counter[min]);
        swap(vowels[max2], vowels[min]);
        max2--;
    }
    cout << "Total consonants: " << consonants << endl;
    cout << "Total vowels: " << total_vowels << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Total '" << vowels[i] << "': " << vowels_counter[i] << endl;
    }
}