#include <iostream>
using namespace std;
float retail(float item, float markup)
{
    markup += 100;
    float cost = item * markup / 100;
    return cost;
}
int main()
{
    float item;
    float markup;
    for (int i = 0; i < 1; i++)
    {
        cout << "Please enter the wholesale cost of item: ";

        cin >> item;
        if (item < 0)
        {
            cout << "Enter again: ";
            i--;
        }
    }

    for (int i = 0; i < 1; i++)
    {
        cout << "enter the markup percentage for it: ";
        cin >> markup;
        if (markup < 0)
        {
            i--;
            cout << "enter again: ";
        }
    }
    cout << "the retail price for this item is: " << retail(item, markup);
}
