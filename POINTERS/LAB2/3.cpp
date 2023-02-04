#include<iostream>
using namespace std;


int main()
{
	float a;
	cout << "Enter the value for the integer : ";
	cin >> a;
	float const *aa = &a;
	cout << "the square of the integer is: " << *aa**aa<<endl;
	cout << "The cube of the integer is: " << *aa**aa**aa<<endl;
	cout << "the half of the integer is : " << *aa / 2 << endl;
	system("pause");
	return 0;
}
