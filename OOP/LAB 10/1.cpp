#include <iostream>
using namespace std;
class Account
{
protected:
    int num;
    float balance;

public:
    Account()
    {
        num = 0;
        balance = 0;
    }
    Account(int num, float b)
    {
        this->num = num;
        balance = b;
    }
    virtual void print()
    {
        cout << "Account Number is: " << num << endl;
        cout << "Account Balance is: " << balance << endl;
    }
    virtual void debit(float a)
    {
        balance -= a;
    }
    virtual void credit(float a)
    {
        balance += a;
    }
};
class currentaccount : public Account
{
    float service_charges;
    float minimum_balance;

public:
    currentaccount()
    {
        service_charges = 0;
        minimum_balance = 0;
    }
    currentaccount(float c, float b, int num, float ba) : Account(num, ba)
    {
        service_charges = c;
        minimum_balance = b;
    }
    void print()
    {
        Account::print();
        cout << "Minimum Balance required is: " << minimum_balance << endl;
        cout << "Service charges are: " << service_charges << endl;
    }
    void credit(float a)
    {
        Account::credit(a);
    }
    void debit(float a)
    {
        int flag = 0;
        if (a < balance)
        {
            Account::debit(a);
            if (balance < minimum_balance)
                flag = 1;
            if (flag == 1)
            {
                Account::debit(service_charges);
            }
        }
        else
            cout << "Insufficient balance!" << endl;
    }
};
class savingaccount : public Account
{
    float rate;

public:
    savingaccount() : Account()
    {
        rate = 0;
    }
    savingaccount(float r, int num, float b) : Account(num, b)
    {
        rate = r;
    }
    void print()
    {
        Account::print();
        cout << "The interest rate is: " << rate << endl;
    }
    void credit(float a)
    {
        Account::credit(a);
    }
    void debit(float a)
    {
        if (a < balance)
        {
            Account::debit(a);
        }
        else
            cout << "Insufficient amount!" << endl;
    }
};
int main()
{
    Account *a[2];
    float service;
    float minimum;
    int num;
    float total;
    cout << "Enter the service charges: ";
    cin >> service;
    cout << "Enter the minimum balance of account: ";
    cin >> minimum;
    cout << "Enter the account number: ";
    cin >> num;
    cout << "Enter the total balance of the account: ";
    cin >> total;
    a[0] = new currentaccount(service, minimum, num, total);
    cout << "THE INFO OF ACC IS: " << endl;
    a[0]->print();
    {
        float cr1;
        cout << "Enter the amount you want to credit: ";
        cin >> cr1;
        a[0]->credit(cr1);
        float db1;
        cout << "Enter the amount you want to debit: ";
        cin >> db1;
        a[0]->debit(db1);
        a[0]->print();
    }
    float rate;
    float num2;
    float total2;
    cout << "Enter the interest rate: ";
    cin >> rate;
    cout << "Enter the account number: ";
    cin >> num;
    cout << "Enter the total balance of the account: ";
    cin >> total;
    a[1] = new savingaccount(rate, num, total);
    cout << "THE INFO OF ACC IS: " << endl;
    a[1]->print();
    {
        float cr1;
        cout << "Enter the amount you want to credit: ";
        cin >> cr1;
        a[1]->credit(cr1);
        float db1;
        cout << "Enter the amount you want to debit: ";
        cin >> db1;
        a[1]->debit(db1);
        a[1]->print();
    }
}