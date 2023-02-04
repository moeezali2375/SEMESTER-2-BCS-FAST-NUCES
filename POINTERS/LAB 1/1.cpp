#include <iostream>
using namespace std;
int main()
{
    cout << "please enter the amount of food eaten by the monkeys: " << endl;
    int array[3][5];
    int total=0;
    for (int i = 0; i < 3; i++)
    {
        cout << "Please enter the amount of food eaten by the monkey " << i + 1 << ": " << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "food eaten on " << j+1 << "'th day: ";
            cin >> array[i][j];
            if (array[i][j]<0)
            j--;
            else 
            {   
                ;
            }
        }
    }
    int minfood=array[0][0],maxfood=array[0][0];

    for (int i=0;i<3;i++)
    {
        for (int j=0;j<5;j++)
        {
            total+=array[i][j];
                if(minfood>array[i][j])
                minfood=array[i][j];
                if (maxfood<array[i][j])
                maxfood=array[i][j];
        }
    }

    cout<<"The total amount of food eaten by the whole family of monkeys is: "<<total/5<<endl;
    cout<<"The minimum amount of food eaten by any one monkey is: "<<minfood<<endl;
    cout<<"The maximum amount of food eaten by any one monkey is: "<<maxfood<<endl;


}