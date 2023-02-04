#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int total = 100;
    int array[3];
    int penalty = 0;
    cout << "welcome to the guessing game!" << endl;
    cout << "You have to guess the card postion of the QUEEN!" << endl;
    cout << "If you guess it correct your penalty will be increased 3 times!" << endl;
    cout << "If not your penalty will be deducted from your total which is 100$!" << endl;
    while (96)
    {
        cout << "Hit 0 to close the game or ";
        cout << "Enter the penalty: ";
        cin >> penalty;
        if (penalty == 0)
            break;
        cout << "Now enter the queen's card number: ";
        int test;
        for (int i = 0; i < 1; i++)
        {
            cin >> test;
            if (test >= 1 && test <= 3)
                ;
            else
            {
                cout << "Invalid choice!"
                     << " Enter again!" << endl;
                i--;
            }
        }
        cout << "The card placement is as follows: ";
        for (int i = 0; i < 3; i++)
        {
            array[i] = 1 + (rand() % 3);
        }
        /*for (int i = 0; i < 3;i++)
        {
        if (i == 1)
        {*/
        while (96)
        {
            if (array[1] == array[0]) // || array[1] == array[2])
            {
                array[1] =1 + (rand() % 3);
            }
            else
                cout << "oho";
            break;
        }

    /*if (i == 2)
    {
    if (array[i] == array[1])
    {
    array[i] == 1 + (rand() % 3); i--;
    }
    else if (array[i] == array[0]){
    array[i] == 1 + (rand() % 3);
    i--;
    }
    }*/
    }
}
