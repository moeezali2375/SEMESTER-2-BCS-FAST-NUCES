#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;
class file
{
private:
    char *name;
    char *content;
    char *creation_time;

protected:
    char *last_access_date;
    char *location;

public:
    file()
    {
        name = nullptr;
        content = nullptr;
        creation_time = nullptr;
        last_access_date = nullptr;
        location = nullptr;
    }

    file(char n[], char con[], char time[], char date[], char loc[])
    {
        name = new char[strlen(n) + 1];
        int i = 0;
        for (; i < strlen(n); i++)
            name[i] = n[i];
        name[strlen(n)] = 0;
        content = new char[strlen(con) + 1];
        i = 0;
        for (; i < strlen(con); i++)
            content[i] = con[i];
        content[strlen(con)] = 0;
        creation_time = new char[strlen(time) + 1];
        i = 0;
        for (; i < strlen(time); i++)
            creation_time[i] = time[i];
        creation_time[strlen(time)] = 0;
        location = new char[strlen(loc) + 1];
        i = 0;
        for (; i < strlen(loc); i++)
            location[i] = loc[i];
        location[strlen(loc)] = 0;
        last_access_date = new char[strlen(date) + 1];
        i = 0;
        for (; i < strlen(date); i++)
            last_access_date[i] = date[i];
        last_access_date[strlen(date)] = 0;
    }

    ~file()
    {
        delete[] location;
        delete[] name;
        delete[] last_access_date;
        delete[] creation_time;
        delete[] content;
    }

    file(file &a)
    {
        name = new char[strlen(a.name) + 1];
        int i = 0;
        for (; i < strlen(a.name); i++)
            name[i] = a.name[i];
        name[strlen(a.name)] = 0;
        content = new char[strlen(a.content) + 1];
        i = 0;
        for (; i < strlen(a.content); i++)
            content[i] = a.content[i];
        content[strlen(a.content)] = 0;
        creation_time = new char[strlen(a.creation_time) + 1];
        i = 0;
        for (; i < strlen(a.creation_time); i++)
            creation_time[i] = a.creation_time[i];
        creation_time[strlen(a.creation_time)] = 0;
        location = new char[strlen(a.location) + 1];
        i = 0;
        for (; i < strlen(a.location); i++)
            location[i] = a.location[i];
        location[strlen(a.location)] = 0;
        last_access_date = new char[strlen(a.last_access_date) + 1];
        i = 0;
        for (; i < strlen(a.last_access_date); i++)
            last_access_date[i] = a.last_access_date[i];
        last_access_date[strlen(a.last_access_date)] = 0;
    }

    file operator=(file a)
    {
        int i = 0;
        name = new char[strlen(a.name) + 1];
        for (i = 0; i < strlen(a.name); i++)
            name[i] = a.name[i];
        name[strlen(a.name)] = 0;
        content = new char[strlen(a.content) + 1];
        for (i = 0; i < strlen(a.content); i++)
            content[i] = a.content[i];
        content[strlen(a.content)] = 0;
        creation_time = new char[strlen(a.creation_time) + 1];
        for (i = 0; i < strlen(a.creation_time); i++)
            creation_time[i] = a.creation_time[i];
        creation_time[strlen(a.creation_time)] = 0;
        location = new char[strlen(a.location) + 1];
        for (i = 0; i < strlen(a.location); i++)
            location[i] = a.location[i];
        location[strlen(a.location)] = 0;
        last_access_date = new char[strlen(a.last_access_date) + 1];
        for (i = 0; i < strlen(a.last_access_date); i++)
            last_access_date[i] = a.last_access_date[i];
        last_access_date[strlen(a.last_access_date)] = 0;
        return *this;
    }

    void create_file()
    {
        char d[100];
        cout << "Input the file name  :  ";
        gets_s(d);
        int i = 0;
        if (d[0] != 0)
        {
            name = new char[strlen(d) + 1];
            for (; i < strlen(d); i++)
                name[i] = d[i];
            name[strlen(d)] = 0;
        }
        cout << "Input the content of file" << endl;
        gets_s(d);
        if (d[0] != 0)
        {
            content = new char[strlen(d) + 1];
            for (i = 0; i < strlen(d); i++)
                content[i] = d[i];
            content[strlen(d)] = 0;
        }

        time_t curr_time = time(NULL);
        size_t size = 30;
        char tm[30];
        ctime_s(tm, size, &curr_time);
        char date[50] = {'1'};
        char time[50] = {'1'};
        for (int i = 0, j = 0, k = 0; tm[i] != 0; i++)
        {
            if (i <= 10)
            {
                date[k] = tm[i];
                k++;
            }
            else if (i > 10 && i <= 19)
            {
                time[j] = tm[i];
                j++;
            }
            else
            {
                if (i == 20)
                    time[j] = 0;
                date[k] = tm[i];
                k++;
                if (tm[i + 1] == 0)
                    date[k] = 0;
            }
        }
        if (time[0] != 0)
        {
            creation_time = new char[strlen(time) + 1];
            for (i = 0; i < strlen(time); i++)
                creation_time[i] = time[i];
            creation_time[strlen(time)] = 0;
        }
        if (date[0] != 0)
        {
            last_access_date = new char[strlen(date) + 1];
            for (i = 0; i < strlen(date); i++)
                last_access_date[i] = date[i];
            last_access_date[strlen(date)] = 0;
        }
    }

    void remove_file()
    {
        this->~file();
    }

    void display()
    {
        cout << "Name is :  " << name << endl;
        cout << "content is  : " << content << endl;
        cout << "creation time is  :  " << creation_time << endl;
        cout << "Last access date is  :  " << last_access_date << endl;
    }

    bool read_file(char path[])
    {
        int count = 0;
        for (int i = 0; path[i] != 0; i++)
            if (path[i] == '\\')
                count++;
        if (path[0] != 'r' && path[1] != 'o' && path[2] != 'o' && path[3] != 't' && path[4] != '\\')
        {
            cout << "Invalid path" << endl;
            goto out;
        }
        else
        {
            count--;
            for (int i = 0, j = 5; i < count; j++)
            {
                if (path[j] == '\\')
                    i++;
                else if (path[j] != location[j])
                {
                    cout << "Invalid path" << endl;
                    goto out;
                }
            }
        }
        return 1;
    out:
        return 0;
    }
};
class folder
{
private:
    char *fname;
    char *creation_date;
    char *f_creation_time;
    char *f_last_access_date;
    char *previous_folder_name;
    int total_number_of_files;
    int total_number_of_subfolders;
    int current_files;
    int current_subfolders;
    folder **fol;
    file **fil;

public:
    static int c;
    folder()
    {
        if (c == 0)
        {
            previous_folder_name = new char[5];
            previous_folder_name[0] = 'r';
            previous_folder_name[1] = 'o';
            previous_folder_name[2] = 'o';
            previous_folder_name[3] = 't';
            previous_folder_name[4] = 0;
        }
        else
            previous_folder_name = nullptr;
        fname = nullptr;
        creation_date = nullptr;
        f_creation_time = nullptr;
        f_last_access_date = nullptr;
        total_number_of_files = 2;
        total_number_of_subfolders = 2;
        current_files = 0;
        current_subfolders = 0;
        fol = new folder *[2];
        fil = new file *[2];
        c++;
    }
    //~folder()
    //{
    //	if (strlen(fname)>0);
    //	delete [] fname;
    //	if (strlen(f_last_access_date) > 0);
    //	delete [] f_last_access_date;
    //	if (strlen(creation_date) > 0);
    //	delete [] creation_date;
    //	if (strlen(previous_folder_name) > 0);
    //	delete [] previous_folder_name;
    //}
    bool find_path(char path[], folder &d, folder *&ptr, char *&prev, int &l)
    {
        folder *dum = nullptr;
        ptr = &d;
        prev = ptr->previous_folder_name;
        int ind = 0, flag = 1;
        for (int i = 0; path[i] != '\\' && path[i] != 0; i++, ind++)
        {
            if (path[i] != ptr->previous_folder_name[i])
            {
                return false;
            }
        }
        if (path[ind] == 0)
            return 1;
        ind += 1;
        int n = ind;
        for (int i = 0; path[i] != 0 && path[i] != '\\'; i++, n++)
        {
            if (ptr->fname[i] != path[n])
                return false;
        }
        prev = ptr->fname;
        //	ptr = d.fol[0];
        l = -1;
        ind = n;
        if (path[ind] == 0)
            return 1;
        ind = n + 1;
        //		ind += 2;
        l = 0;
        dum = ptr;
        flag = 1;
        ptr = d.fol[0];
        // ptr = ptr->fol[0];
    again:
        for (int i = 0; i < d.total_number_of_subfolders; i++)
        {
            if (path[ind] == ptr->fname[0])
            {
                flag = 1;
                for (int i = 0; ptr->fname[i] != 0; i++, ind++)
                {
                    if (path[ind] != ptr->fname[i])
                    {
                        flag = 0;
                        ptr = dum->fol[l + 1];
                        dum = ptr;
                        l++;
                        break;
                    }
                }
                if (flag == 1)
                {
                    prev = ptr->fname;
                    // ptr = dum->fol[l];
                    ptr = ptr->fol[0];
                    dum = ptr;
                    l = -1;
                    if (path[ind] != 0)
                        goto again;
                    else
                        goto out;
                    ind += 2;
                }
            }
            else
            {
                ptr++;
                dum = ptr;
            }
        }
    out:
        if (flag == 1)
        {
            return 1;
        }
        return 0;
    }
    void create_folder(char path[])
    {
        int l = 0;
        char *previous;
        folder *ptr = nullptr;
        if (find_path(path, *this, ptr, previous, l))
        {
            if (l == -1)
            {
                ptr = new folder;
                ptr->fol[0] = ptr;
                ptr = ptr->fol[0];
            }
            // if (ptr->total_number_of_subfolders < ptr->current_subfolders)
            //			{
            // ptr = ptr->fol[l];
            char name[50];
            int i = 0;
            folder *nptr = nullptr;
            nptr = ptr;
            cout << "Input name of folder  :  ";
            gets_s(name);
            if (strlen(name) > 0)
            {
                nptr->fname = new char[strlen(name) + 1];
                while (name[i] != 0)
                {
                    nptr->fname[i] = name[i];
                    i++;
                }
                nptr->fname[i] = 0;
            }
            i = 0;
            nptr->previous_folder_name = new char[strlen(previous) + 1];
            while (previous[i] != 0)
            {
                nptr->previous_folder_name[i] = previous[i];
                i++;
            }
            nptr->previous_folder_name[i] = 0;
            i = 0;
            time_t curr_time = time(NULL);
            size_t size = 30;
            char tm[30];
            ctime_s(tm, size, &curr_time);
            char date[50] = {'1'};
            char time[50] = {'1'};
            for (int i = 0, j = 0, k = 0; tm[i] != 0; i++)
            {
                if (i <= 10)
                {
                    date[k] = tm[i];
                    k++;
                }
                else if (i > 10 && i <= 19)
                {
                    time[j] = tm[i];
                    j++;
                }
                else
                {
                    if (i == 20)
                        time[j] = 0;
                    date[k] = tm[i];
                    k++;
                    if (tm[i + 1] == 0)
                        date[k] = 0;
                }
            }
            if (time[0] != 0)
            {
                nptr->f_creation_time = new char[strlen(time) + 1];
                for (i = 0; i < strlen(time); i++)
                    nptr->f_creation_time[i] = time[i];
                nptr->f_creation_time[strlen(time)] = 0;
            }
            if (date[0] != 0)
            {
                nptr->creation_date = new char[strlen(date) + 1];
                for (i = 0; i < strlen(date); i++)
                    nptr->creation_date[i] = date[i];
                nptr->creation_date[strlen(date)] = 0;

                nptr->f_last_access_date = new char[strlen(date) + 1];
                for (i = 0; i < strlen(date); i++)
                    nptr->f_last_access_date[i] = date[i];
                nptr->f_last_access_date[strlen(date)] = 0;
            }
        }
    }
    //}
    void display(char path[])
    {
        int l = 0;
        char *previous;
        folder *ptr = nullptr;
        if (find_path(path, *this, ptr, previous, l))
        {
            cout << "Folder name is  :  " << ptr->fname << endl;
            cout << "Previous folder name is  :  " << ptr->previous_folder_name << endl;
            cout << "creationo date is  :  " << ptr->creation_date;
            cout << "creatipon time is  :  " << ptr->f_creation_time << endl;
            cout << "last access date is  :  " << ptr->f_last_access_date << endl;
        }
    }
};
int folder::c = 0;
int main()
{
    /*file f;
    f.create_file();
    f.display();*/
    folder root;
    char path[50] = "root";
    root.create_folder(path);
    char path2[20] = "root\\name";
    root.create_folder(path2);
    char path3[60] = "root\\name\\assign";
    //	root.create_folder(path3);
    root.display(path);
    cout << endl;
    root.display(path2);
    cout << endl;
    //	root.display(path3);
    cout << endl;
    system("pause");
    return 0;
}