#include <iostream>
#include<exception>
using namespace std;

void getTransType(char &a)
{
    cout << "Enter W for withdraw and D for deposit" << endl;
    cin >> a;
    if (a != 'W' && a != 'D')
        throw invalid_argument("Incorrect Transaction type");
}
void getAmount(int &amount)
{
    cout << "Enter the amount";
    cin >> amount;
    if (amount < 1)
        throw out_of_range("Enter positive number");
    if (amount > 5000)
        throw exception("Amount should be less than 5001");
}
int main()
{
    try
    {
        char a;
        getTransType(a);
        try
        {
            int amount;
            getAmount(amount);
            cout << "Successful transaction";
        }
        catch (exception e)
        {
            cout << e.what();
        }
    }
    catch (invalid_argument ia)
    {
        cout << ia.what();
    }
}