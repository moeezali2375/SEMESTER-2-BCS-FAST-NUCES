// #include <iostream>

// using namespace std;

// void input(int *set, int size)
// {
//     cout << "Please input numbers \n";
//     for (int i = 0; i < size; i++)
//     {
//         cin >> set[i];
//     }
// }

// int **intersection(int **result, int *set1, int *set2, int size, int &idx)
// {
//     int count = 0;
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < size; j++)
//         {
//             if (set1[i] == set2[j])
//             {
//                 count++;
//             }
//         }
//     }

//     for (int i = 0; i < count; i++)
//     {
//         for (int j = 0; j < size; j++)
//         {
//             result[idx][i] = set1[j];
//         }
//         for (int a = 0; a < size; a++)
//         {
//             if (set2[a] != set1[a])
//             {
//                 result[idx][i] = set2[a];
//             }
//         }
//     }
//     idx++;
//     return result;
// }
// void output(int **resultant)
// {
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             cout << resultant[i][j] << "  ";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int size;
//     int idx = 0;

//     cout << "What is the size of your sets? \n";
//     cin >> size;

//     int *a = new int[size];
//     int *b = new int[size];
//     int *c = new int[size];

//     int **resultant = new int *[3];

//     input(a, size);
//     input(b, size);
//     input(c, size);

//     intersection(resultant, a, b, size, idx);
//     intersection(resultant, b, c, size, idx);
//     intersection(resultant, a, c, size, idx);

//     output(resultant);

//     delete[] a, b, c, resultant;
//     return 0;
// }

#include <iostream>
#include <string>

using namespace std;

class Books
{
    public:

    string Book_Title;
    string Book_Author;
    int No_of_book;
    int Book_id;

public:
    Books()
    {
    }

    Books(string title, string author, int no, int id)
    {
        Book_Title = title;
        Book_Author = author;
        No_of_book = no;
        Book_id = id;
    }

    void set_Book_Title(string title)
    {
        Book_Title = title;
    }

    void set_Book_Author(string author)
    {
        Book_Author = author;
    }

    void set_No_of_book(int number)
    {
        No_of_book = number;
    }

    void set_book_id(int id)
    {
        Book_id = id;
    }

    string get_Book_Title()
    {
        string a = Book_Title;
        return a;
    }

    string get_Book_Author()
    {
        string a = Book_Author;
        return a;
    }

    int get_Book_Number()
    {
        int a = No_of_book;
        return a;
    }

    int get_Book_id()
    {
        int a = Book_id;
        return a;
    }

    ~Books()
    {
    }
};

class student
{
    string first_name;
    string last_name;
    int roll_number;
    int No_of_book_issue;

public:
    student()
    {
    }

    student(string f, string l, int rn, int b_i)
    {
        first_name = f;
        last_name = l;
        roll_number = rn;
        No_of_book_issue = b_i;
    }

    void set_first_name(string f_name)
    {
        first_name = f_name;
    }

    void set_last_name(string l_name)
    {
        last_name = l_name;
    }

    void set_roll_no(int r_nu)
    {
        roll_number = r_nu;
    }

    void set_No_of_book_issue(int issue)
    {
        No_of_book_issue = issue;
    }

    string get_f_name()
    {
        string a = first_name;
        return a;
    }

    string get_l_name()
    {
        string a = last_name;
        return a;
    }
    int get_Roll_Number()
    {
        int a = roll_number;
        return a;
    }

    int get_Book_issue()
    {
        int a = No_of_book_issue;
        return a;
    }

    ~student()
    {
    }
};

class library : public Books
{
private:
   // friend Books;
    Books *book;
    student Student;

public:
    library(int index, string Book_title, string Book_author, int No_of_book, int Book_id, string First_name, string Last_name, int Roll_no, int No_of_book_issue)
    {
        Books(Book_title, Book_author, No_of_book, Book_id);
        student(First_name, Last_name, Roll_no, No_of_book_issue);
    }

    void Issue_Books()
    {
        cout << book;
        if (Book_id == No_of_book)
        {
            cout << "Book issued.";
        }
        else
        {
            cout << "Book are not available. ";
        }
    }

    ~library()
    {
        delete[] book, Student;
    }
};

int main()
{
    Books obj1;
    string title;
    cout << " enter book name: ";
    cin >> title;
    obj1.set_Book_Title(title);
    cout << obj1.get_Book_Title() << endl;

    system("pause");
    return 0;   
}