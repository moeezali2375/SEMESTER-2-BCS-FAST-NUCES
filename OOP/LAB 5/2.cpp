#include <iostream>
using namespace std;
class bank
{
public:
    int getbalance()
    {
        return 0;
    }
};
class bankA : bank
{
public:
    int getbalance()
    {
        return 1000;
    }
};
class bankB : bank
{
public:
    int getbalance()
    {
        return 1500;
    }
};
class bankC : bank
{
public:
    int getbalance()
    {
        return 2000;
    }
};

int main()
{
    bankA balanceA;
    bankB balanceB;
    bankC balanceC;
    cout << "The balance in Bank ele is: " << balanceA.getbalance() << endl;
    cout << "The balance in Bank B is: " << balanceB.getbalance() << endl;
    cout << "The balance in Bank C is: " << balanceC.getbalance() << endl;
}