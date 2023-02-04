#include<iostream>
using namespace std;
void output(char * a, int size)
{
	for (int i = 0; i<size; i++)
		cout << a[i];
}

void reverse(char* a, int size)

{
	int b = size-1;
	for (int i = 0; i < size/2; i++)
	{
		char temp = a[i];
		a[i] = a[b];
		a[b] = temp;
		b--;
	}
}

void input(char* &arr, int &size)
{
	int i = 0;
	for (i = 0; 1; i++)
	{
		cin >> arr[i];
		if (arr[i] == 'q'){
			i--;
			break;
		}
		if (i == size)
		{
			size *= 2;
		}
		
	}
	size = i + 1;

}
int main()
{
	int size = 5;
	char *a=nullptr;
	a = new char[size];
	input(a, size);
	reverse(a, size);
	output(a, size);
	delete[]a;
	a=nullptr;
	return 0;
}
