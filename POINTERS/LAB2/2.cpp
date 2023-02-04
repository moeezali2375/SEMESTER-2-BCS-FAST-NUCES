#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a, b;
	cout << "Enter the values for the integers : ";
	cin >> a >> b;
	swap(&a, &b);
	cout << a << endl << b;
	system("pause");
	return 0;
}
