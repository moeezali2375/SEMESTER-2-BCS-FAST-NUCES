#include <iostream>
#include "header.h"
#include <ctime>
using namespace std;
int main()
{
    file_system a;
    cout << "\t\t\t\t\t\t\t\t\tWelcome to Macintosh HD" << endl;
    char choice = '0';
    while (96)
    {
        cout << endl;
        cout << "Select a choice!" << endl;
        cout << "To create a folder, press 1" << endl;
        cout << "To create a file, press 2" << endl;
        cout << "To display a folder and its contents, press 3" << endl;
        cout << "To display a file and its content, press 4" << endl;
        cout << "To delete a file , press 5" << endl;
        cout << "To delete a folder , press 6" << endl;
        cout << "To close , press x" << endl
             << endl;
        cin >> choice;
        if (choice == '1')
        {
            cout << endl;
            string folder_name;
            string folder_path;
            cout << "Please enter the name of the folder: ";
            cin >> folder_name;
            cout << "Please enter the path of the folder: ";
            cin >> folder_path;
            a.create_folder(folder_name, folder_path);
        }
        if (choice == '2')
        {
            string file_name;
            string file_path;
            string file_content;
            cout << "\nPlease enter the name of the file: ";
            cin >> file_name;
            cout << "Please enter the path of the file: ";
            cin >> file_path;
            cout << "Please enter some content in the file: ";
            cin >> file_content;
            a.create_file(file_name, file_path, file_content);
        }
        if (choice == '3')
        {
            string path;
            cout << "\nPlease enter the path of folder: ";
            cin >> path;
            a.display_folder(path);
        }
        if (choice == '4')
        {
            string path;
            cout << "Enter the path of the file : ";
            cin >> path;
            a.display_file(path);
        }
        if (choice == '5')
        {
            string path;
            cout << "Enter the path to remove file: ";
            cin >> path;
            a.remove_file(path);
        }
        if (choice == '6')
        {
            string path;
            cout << "Enter the path to delete folder: ";
            cin >> path;
            a.remove_folder(path);
        }
        if (choice == 'x')
        {
            break;
        }
    }
}
