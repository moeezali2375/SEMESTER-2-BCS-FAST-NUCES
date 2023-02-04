#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
time_t now = time(0);

using namespace std;
class file
{
    friend class file_system;
    string file_name;
    string path;
    string content;
    string creation_date;
    string recent_date;

public:
    file()
    {
        ;
    }
    file(string n, string p)
    {
        file_name = n;
        path = p;
        creation_date = ctime(&now);
        recent_date = ctime(&now);
    }
    void set_content(string a)
    {
        content = a;
    }
};
class folder
{
    friend class file_system;
    string folder_name;
    string path;
    string creation_date;
    string recent_date;
    folder **ptr;
    int folder_capacity;
    int folder_used;
    file **files;
    int files_capacity;
    int files_used;

public:
    folder()
    {
        folder_name = "root";
        ptr = new folder *[2];
        files = new file *[2];
        folder_capacity = 2;
        folder_used = 0;
        files_capacity = 2;
        files_used = 0;
        creation_date = ctime(&now);
        recent_date = ctime(&now);
    }
    folder(string n, string p)
    {
        folder_name = n;
        path = p;
        ptr = new folder *[2];
        files = new file *[2];
        folder_capacity = 2;
        folder_used = 0;
        files_capacity = 2;
        files_used = 0;
        creation_date = ctime(&now);
        recent_date = ctime(&now);
    }
    void grow_folder()
    {
        folder **temp;
        temp = new folder *[folder_capacity];
        for (int i = 0; i < folder_capacity / 2; i++)
        {
            temp[i] = this->ptr[i];
        }
        delete[] ptr;
        ptr = temp;
    }
    void grow_files()
    {
        file **temp;
        temp = new file *[files_capacity];
        for (int i = 0; i < files_capacity; i++)
        {
            temp[i] = this->files[i];
        }
        delete[] files;
        files = temp;
    }
    void display_folder()
    {
        cout << "Name is: " << folder_name << endl;
        cout << "Creation date is: " << creation_date;
    }
    ~folder()
    {
        for (int i = 0; i < files_used; i++)
            delete files[i];
        delete[] files;
        for (int i = 0; i < folder_used; i++)
            delete ptr[i];
        delete[] ptr;
    }
};

class file_system
{
    folder root;
    file txt;

public:
    file_system()
    {
        folder();
        file();
    }

    bool folder_path_checker(string b, folder *&pointer)
    {
        int slashes = 0;
        int i, j, k, end;
        for (i = 0; b[i] != '\0'; i++)
        {
            if (b[i] == '/')
                slashes++;
        }
        slashes++;
        string *array = new string[slashes];
        int flag = 0;
        int start = 0;
        int subfolder = 0;
        int slash = 0;
        string temp;
        for (i = 0, slash = 0; i < b.length() + 1; i++)
        {
            flag = 0;
            if (b[i] == '/' || b[i] == '\0')
            {
                flag = 1;
                end = i - start;
            }
            if (flag == 1)
            {
                array[slash] = b.substr(start, end);
                // cout << "SIngle word is: " << array[slash] << endl;
                slash++;
                subfolder++;
                start = i + 1;
            }
        }
        folder *target = nullptr;
        if (array[0] == "root")
        {
            target = &root;
            pointer = target;
            int flag = 0;
            for (int i = 1; i < slashes; i++)
            {
                for (int j = 0; j < target->folder_used; j++)
                {
                    if (target->ptr[j]->folder_name == array[i])
                    {
                        target = target->ptr[j];
                        flag = 1;
                        pointer = target;
                        break;
                    }
                }
                if (flag == 0)
                    return false;
            }
            return true;
        }
        else
            return false;
        return true;
    }
    bool file_path_checker(string b, folder *&pointer, string &c)
    {
        int slashes = 0;
        int i, j, k, end;
        for (i = 0; b[i] != '\0'; i++)
        {
            if (b[i] == '/')
                slashes++;
        }
        slashes++;
        string *array = new string[slashes];
        int flag = 0;
        int start = 0;
        int subfolder = 0;
        int slash = 0;
        string temp;
        for (i = 0, slash = 0; i < b.length() + 1; i++)
        {
            flag = 0;
            if (b[i] == '/' || b[i] == '\0')
            {
                flag = 1;
                end = i - start;
            }
            if (flag == 1)
            {
                array[slash] = b.substr(start, end);
                // cout << "SIngle word is: " << array[slash] << endl;
                slash++;
                subfolder++;
                start = i + 1;
            }
        }
        c = array[slash - 1];
        folder *target = nullptr;
        if (array[0] == "root")
        {
            target = &root;
            pointer = target;
            int flag = 0;
            for (int i = 1; i < slashes - 1; i++)
            {
                for (int j = 0; j < target->folder_used; j++)
                {
                    if (target->ptr[j]->folder_name == array[i])
                    {
                        target = target->ptr[j];
                        flag = 1;
                        pointer = target;
                        break;
                    }
                }
                if (flag == 0)
                    return false;
            }
            return true;
        }
        else
            return false;
        return true;
    }
    void create_folder(string n, string p)
    {
        folder *pointer = nullptr;
        if (folder_path_checker(p, pointer) == 0)
            cout << "\nPath is incorrect!" << endl;
        else
        {
            if (folder_path_checker(p, pointer) == 1)
            {
                if (pointer->folder_capacity == pointer->folder_used)
                {
                    pointer->grow_folder();
                    cout << "Grow function called!" << endl;
                }
                pointer->ptr[pointer->folder_used] = new folder(n, p);
                pointer->folder_used++;
            }
        }
    }
    void create_file(string n, string p, string content)
    {
        folder *pointer = nullptr;
        if (folder_path_checker(p, pointer) == 0)
        {
            cout << "\nPath does not exists!" << endl;
        }
        else
        {
            if (folder_path_checker(p, pointer) == 1)
            {
                if (pointer->files_capacity == pointer->files_used)
                {
                    pointer->grow_files();
                }
                pointer->files[pointer->files_used] = new file(n, p);
                pointer->files[pointer->files_used]->set_content(content);
                pointer->files_used++;
            }
        }
    }
    void display_folder(string path)
    {
        folder *target = nullptr;
        if (folder_path_checker(path, target) == 1)
        {
            for (int i = 0; i < target->folder_used; i++)
            {
                cout << "The folder " << i + 1 << " is: ";
                cout << target->ptr[i]->folder_name << endl;
                cout << "The creation date is: ";
                cout << target->ptr[i]->creation_date << endl;
            }
            for (int i = 0; i < target->files_used; i++)
            {
                cout << "The file " << i + 1 << " is: ";
                cout << target->files[i]->file_name << endl;
                cout << "The creation date is: ";
                cout << target->files[i]->creation_date;
                cout << "The content of the file is: " << target->files[i]->content << endl;
                target->files[i]->recent_date = ctime(&now);
                cout << "The last modified date is: " << target->files[i]->recent_date;
            }
        }
        else
            cout << "\nInvalid path!" << endl;
    }
    void display_file(string path)
    {
        folder *target = nullptr;
        string c;
        if (file_path_checker(path, target, c) == 1)
        {
            for (int i = 0; i < target->files_used; i++)
            {
                if (target->files[i]->file_name == c)
                {
                    cout << "The file " << i + 1 << " is: ";
                    cout << target->files[i]->file_name << endl;
                    cout << "The creation date is: ";
                    cout << target->files[i]->creation_date;
                    cout << "The content of the file is: " << target->files[i]->content << endl;
                    target->files[i]->recent_date = ctime(&now);
                    cout << "The last modified date is: " << target->files[i]->recent_date;
                }
            }
        }
        else
            cout << "\nInvalid path!" << endl;
    }
    void remove_file(string path)
    {
        folder *target = nullptr;
        string c;
        if (file_path_checker(path, target, c) == 1)
        {
            for (int i = 0; i < target->files_used; i++)
            {
                if (target->files[i]->file_name == c)
                {
                    cout << "FILE DELETED SUCCESSFULLY!" << endl;
                    delete target->files[i];
                    target->files_used--;
                }
            }
        }
        else
            cout << "\nInvalid path!" << endl;
    }
    void remove_folder(string path)
    {
        folder *target = nullptr;
        int flag = 0;
        string c;
        if (file_path_checker(path, target, c) == 1)
        {
            int i;
            for (i = 0; i < target->folder_used; i++)
            {
                int flag = 0;
                if (target->ptr[i]->folder_name == c)
                {
                    cout << "Calling folder remover!" << endl;
                    delete target->ptr[i];
                    target->ptr[i] = nullptr;
                    for (int j = i; j < target->folder_used - 1; j++)
                    {
                        target->ptr[j] = target->ptr[j + 1];
                    }
                    target->folder_used--;
                    break;
                }
            }
        }
        else
            cout << "\nInvalid path!" << endl;
    }
};