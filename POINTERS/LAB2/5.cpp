#include<iostream>
using namespace std;
void copy(int *a, int*b, int size)
{
	for (int i = 0; i < size; i++)
	{
		b[i] = a[i];
	}
}
int reducearray(int *a, int * &b, int size)
{
	int sizee = size;
	for (int i = 0; i < size; i++)
	{
		int index=0;
		int max = a[0];
		int j;
		for (j = 0; j < size; j++)
		{
			if (max <= b[j])
			{
				max = b[j];
				index = j;
			}
		}
		int temp = b[size-1];
		b[size-1] = b[index];
		b[index] = temp;
		size--;
	}
	for (int i = 0; i < sizee - 1; i++)
	{
		if (b[i] == b[i + 1])
		{
			for (int j = i; j < sizee - 1; j++)
			{
				b[j] = b[j + 1];
			}
			sizee--;
			i--;
		}
	}
	return sizee;
	

}


int main()
{
	int size;
	cin >> size;
	int *a;
	int *b;
	b = new int[size];
	a = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	copy(a, b, size);
	int hello= reducearray(a, b, size);
	for (int i = 0; i <hello; i++)
		cout << b[i];
	system("pause");
	return 0;
}