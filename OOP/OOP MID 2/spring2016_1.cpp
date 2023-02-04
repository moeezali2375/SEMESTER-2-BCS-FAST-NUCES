#include <iostream>
using namespace std;
class employee
{
private:
    int *id;
    int idlen;
    int salary;

public:
    employee()
    {
        id = nullptr;
        idlen = 0;
        salary = 0;
    }
    ~employee()
    {
        if (idlen == 0)
            ;
        else
            delete[] id;
    }
    employee(int *ii, int len, int sal)
    {
        idlen = len;
        salary = sal;
        id = new int[idlen];
        for (int i = 0; i < idlen; i++)
        {
            id[i] = ii[i];
        }
    }
    employee(employee &s)
    {

        id = new int[s.idlen];
        idlen = s.idlen;
        salary = s.salary;
        for (int i = 0; i < idlen; i++)
        {
            id[i] = s.id[i];
        }
    }
    employee &operator=(employee s)
    {
        if (idlen != 0)
            delete[] id;
        id = new int[s.idlen];
        idlen = s.idlen;
        salary = s.salary;
        for (int i = 0; i < idlen; i++)
        {
            id[i] = s.id[i];
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, employee s);
    employee &operator*(int a)
    {
        employee *temp;
        temp = new employee(*this);
        temp->salary *= a;
        for (int i = 0; i < idlen; i++)
        {
            temp->id[i] *= a;
        }
        return *temp;
    }
    employee &operator+(employee s)
    {
        employee *temp;
        temp = new employee(*this);
        temp->salary += s.salary;
        return *temp;
    }
};
ostream &operator<<(ostream &out, employee s)
{
    out << "Id is: ";
    for (int i = 0; i < s.idlen; i++)
    {
        out << s.id[i] << " ";
    }
    out << endl;
    out << "Salary: " << s.salary << endl;
    return out;
}
int main()
{
    int id1[] = {3, 4, 5, 7, 9};
    int id2[] = {2, 5, 1};

    employee ali(id1, 5, 10000);  // should make a deep copy of id1 in ali's id and salary=10000
    employee omar(ali);           // should make an identical object to ali, making a deep copy of id.
    employee anum(id2, 3, 20000); // should makeanum's id=[2,5,1] and salary=20000
    employee saira;               // should initialize all object's members to zero
    saira = ali * 10;             // should make saira's salary = 10*ali's salary.
    cout << "ali:" << endl
         << ali << "omar:" << endl
         << omar;
    cout << "saira:" << endl
         << saira << endl;
    cout << "anum+omar:" << endl
         << anum + omar;
    // adding anum+omar means creating a new object with id = id digits of anum
    // concatenated with id digits of omar and
    // salary of new object = salary of 2 anum+omar

    saira = ali = omar; // should make saira and ali equal to omar
    cout << "saira:" << endl;
    cout << saira;
    return 0;
}
