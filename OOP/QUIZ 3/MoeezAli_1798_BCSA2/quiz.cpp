#include <iostream>
using namespace std;
void input(int *a, int *b, int *c, int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the values for the set A"
			 << ": ";
		cin >> a[i];
	}
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the values for the set B"
			 << ": ";
		cin >> b[i];
	}
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the values for the set C"
			 << ": ";
		cin >> c[i];
	}
}
int **resultant(int *&a, int *&b, int *&c, int size)
{
	int **temp = NULL;
	int *l;
	l = new int[3];
	temp = new int *[3];
	for (int i = 0; i < 3; i++)
	{
		l[i] = 0;
	}
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i] == b[j])
			{

				k++;
				break;
			}
		}
	}
	l[0] = k;

	k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (b[i] == c[j])
			{
				k++;
				break;
			}
		}
	}
	l[1] = k;

	k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (c[i] == a[j])
			{
				k++;
				break;
			}
		}
	}
	l[2] = k;

	for (int i = 0; i < 3; i++)
	{
		*(temp + i) = new int[l[i]];
	}

	for (int i = 0, k = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i] == b[j])
			{
				temp[0][k] = a[i];
				k++;
				break;
			}
		}
	}

	for (int i = 0, k = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (b[i] == c[j])
			{
				temp[1][k] = b[i];
				k++;
				break;
			}
		}
	}

	for (int i = 0, k = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (c[i] == a[j])
			{
				temp[2][k] = c[i];
				k++;
				break;
			}
		}
	}

	// OUTPUT

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < l[i]; j++)
		{
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}

	delete[] l;

	return temp;
}

int main()
{
	int *a, *b, *c, **result;
	int size = 0;
	cout << "Pease enter the size of the sets: ";
	cin >> size;
	a = new int[size];
	b = new int[size];
	c = new int[size];
	input(a, b, c, size);
	result = resultant(a, b, c, size);

	delete[] a;
	delete[] b;
	delete[] c;
	delete[] result;
	//	result=nullptr;
	//		a=nullptr;
	//		b=nullptr;
	//		c=nullptr;
	system("pause");
	return 0;
}
