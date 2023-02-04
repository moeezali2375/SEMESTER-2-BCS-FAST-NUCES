#include<iostream>
using namespace std;
    class fraction 
    {
    private:
        int num;                                    //DATA MEMBERS
        int denum;
    public:                                            //ACCESS SPECIFIERS
        fraction ();
        void inputfraction()                        //MEMBER FUNCTIONS
        {
            cin>>num;
            cin>>denum;
        }
        void outputfraction ()
        {
            cout<<num<<"/"<<denum<<endl;
        }
        fraction add(fraction f)
        {
            fraction res;
            res.denum=denum*f.denum;
            res.num=num*f.denum+f.num*denum;
            res.simplify();
            return res;
        }
        int gcd (int ele,int b)
        {
            int gcd;
            if (ele<b)
            {
                for (int i=1;i<=ele;i++)
                {
                    if (ele%i==0&&b%i==0)
                    gcd=i;
                }
            }
            
            if (b<=ele)
            {
                for (int i=1;i<=b;i++)
                {
                    if (ele%i==0&&b%i==0)
                    gcd=i;
                }
            }



            return gcd;
        }
        void simplify ()
        {
            //fraction rs;
            int ele=gcd (num,denum);
            denum=denum/ele;
            num=num/ele;
        }
        int getnum ()
        {
            return num;
        }
        void setdenum (int ele)
        {
            denum=ele;
        }
    };
    fraction::fraction()                           //CONSTRUCTOR FUNCTION
    {
        num=0;
        denum=1;
    }
int main ()
{
    fraction f1,f2,f3,f4;                                    //OBJECTS
    f1.inputfraction();                             //f1=COLLAR OBJECT
    f2.inputfraction();                             //f1=COLLAR OBJECT
    f1.outputfraction();
    f2.outputfraction();

    f1.outputfraction();  
    f3=f1.add(f2);
    f3.outputfraction();
    cout<<"The numerator is: "<<f3.getnum();
    f3.setdenum(59);
    cout<<"The denominator is: ";f3.outputfraction();
    cout<<"The 4th function is: ";
    f4.outputfraction();                            //CONSTRUCTOR FUNCTION IS CALLED

}