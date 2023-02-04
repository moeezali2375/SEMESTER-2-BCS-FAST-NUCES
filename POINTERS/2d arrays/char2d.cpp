#include<iostream>
using namespace std;
int main ()
{
    int csize;
    cout<<"enter size: ";
    cin>>csize;
    char **name,**fname,**lname;
    name=new char *[csize];
    fname=new char *[csize];
    lname=new char *[csize];
    
        cin.ignore();
    for (int i =0;i<csize;i++)
    {
        char temp[100]="Moeez Ali";
        cin.getline (temp,50);
        name[i]= new char(strlen(temp)+1);
        strcpy(name[i],temp);
    }


    //PRINTS FULL NAME
    cout<<"The full names are: ";
    for (int i=0;i<csize;i++)
    cout<<name[i]<<endl;
    
    
    
    //PRINTS FIRST NAME
    cout<<"The first names are: ";
    for (int i=0;i<csize;i++)
    {
        int j=0;
        for (;name[i][j]!=' ';j++)
        ;
        fname[i]=new char[j+1];
        for (int k=0;k<j;k++)
        {
            fname[i][k]=name[i][k];
        }
        fname[i][j]='\0';
        int len=strlen(name[i])-j;
        j++;
        lname[i]= new char [len];
        int ll=0;
        for (int m=j;name[i][m]!='\0';m++)
        {
            lname[i][ll]=name[i][m];
            ll++;
        }
        lname[i][ll]='\0';
    }

    for (int i=0;i<csize;i++)
    cout<<fname[i]<<endl;
    cout<<"The last names are: ";
    for (int i=0;i<csize;i++)
    cout<<lname[i]<<endl;
    
    





}

