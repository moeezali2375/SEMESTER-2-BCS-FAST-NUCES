#include <iostream>
using namespace std;
void token(char *data, char ** listtokens, char delimiter)
{

    int count = 0;
    int n = strlen(data);
    for (int i = 0; i < n; i++)
    {
        if (delimiter == data[i])
            count++;
    }
    int temp[count + 1];
    listtokens = new char *[count + 1];
    int j=0;
    for (int i = 0; i < count + 1; i++)
    {
        int flag=0;
        for (int k=0; j<n; j++,k++)
        {
            if (data[j] == delimiter)
            {
                temp[i]=k;
                flag=1;
                break;
            }
            if (j==n-1)
            {
                temp[i]=k+1;
                flag=1;
                break;
            }
        }
        if (flag==1)
        j++;
        
        
    }
    int q=0;
    for (int i=0;i<count+1;i++)
    {
        *(listtokens+i)=new char[temp[i]];
        for (int l=0;l<temp[i];l++,q++)
        {
            listtokens[i][l]=data[q];
        }
        q++;
        listtokens[i][temp[i]]='\0';
        cout<<listtokens[i]<<endl;
    }

}
int main()
{
    // cin.ignore();
    char *data;
    data = new char[100];

    cout << "Enter the data: ";
    cin.getline(data, 100);
    

    char **listtokens;
    char delimiter;
    cout << "What is the delimiter?" << endl;
    cin >> delimiter;
    cin.ignore();
    token(data, listtokens, delimiter);
}
