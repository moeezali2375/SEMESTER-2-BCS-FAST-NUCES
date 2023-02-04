#include<iostream>
using namespace std;
int main()
{
	int array[10];
	int *a = array;
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < 10; i++)
	{
		cin >> *(a + i);
		*(a + i) += 5;
	}
}
