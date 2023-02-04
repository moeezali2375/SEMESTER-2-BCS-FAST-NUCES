#include <iostream>
using namespace std;
class Student
{
    string first_name;
    string last_name;
    int roll_no;
    int num_of_books;

public:
    Student()
    {
        roll_no = 0;
        num_of_books = 0;
    }
    void setfname(string a )
    {
        first_name=a;
    }
    void setlname(string a )
    {
        last_name=a;
    }
    void setrollnum(int a)
    {
        roll_no=a;
    }
    void setissuebook(int a)
    {
        num_of_books=a;
    }
    
};
class books
{
    string book_title;
    string book_author;
    int num;
    int book_id;

public:
    books()
    {
        num = 0;
        book_id = 0;
        book_title = "NULL";
        book_author = "NULL";
    }
    books(string a, string b, int id, int n)
    {
        num = n;
        book_id = id;
        book_title = a;
        book_author = b;
    }
    ~books()
    {
        ;
    }
    string get_title()
    {
        return book_title;
    }
    string get_author()
    {
        return book_author;
    }
    int get_num()
    {
        return num;
    }
    int get_id()
    {
        return book_id;
    }
    void set_title(string a)
    {
        book_title = a;
    }
    void set_author(string a)
    {
        book_author = a;
    }
    void set_num(int n)
    {
        num = n;
    }
    void set_id(int n)
    {
        book_id = n;
    }
};
class library
{
    books *book;
    int numofbooks;
    Student student;

public:
    library() : student()
    {
        book = nullptr;
        numofbooks=0;
    }
    
    void add_books()
    {
        int a;
        cout<<"How many books you want to add?"<<endl;
        cin>>a;
        numofbooks+=a;

        book=new books [numofbooks];
        
        for (int i=0;i<a;i++)
        {
            string aa;
            cout<<"Enter the title of the book: ";
            cin>>aa;
            book[i].set_title(aa);
            string b;
            cout<<"Enter the name of the author: ";
            cin>>b;
            book[i].set_author(b);
            int q;
            // cout<<"Enter the number of this book: ";
            // cin>>q;
            book[i].set_num(i+1);
            int w;
            cout<<"Enter the id of the of the book: ";
            cin>>w;
            book[i].set_id(w);
        }
    }
    // void grow_books(int num,int a)
    // {
    //     if (book==nullptr)
    //     {
    //         book=new books[a];
    //     }
    //     else 
    //     {
    //         books *newbook;
    //         newbook=new books[num+a];
    //         for (int i=0;i<num;i++)
    //         {
    //             newbook[i].set_author(get_author());
    //         }


    // }
    void issue_books()
    {
        string f_name;
        string l_name;
        int roll_num;
        int issue;
        cout<<"Enter the full name: ";cin>>f_name;
        cout<<"Enter the last name: ";cin>>l_name;
        cout<<"Enter the Roll number: ";cin>>roll_num;
        cout<<"Enter the book issue number: ";cin>>issue;
        student.setfname(f_name);
        student.setlname(l_name);
        student.setrollnum(roll_num);
        student.setissuebook(issue);
        cout<<"The books are: "<<numofbooks;
        for (int i=0;i<numofbooks;i++)
        {
            cout<<"The book is : "<<book[i].get_title();
            cout<<"The author is : "<<book[i].get_author();
            cout<<"The num is : "<<book[i].get_num();
            cout<<"The id is : "<<book[i].get_id();
        }
        
        cout<<"Which book you want to borrow: ";

    }

};
int main()
{
}