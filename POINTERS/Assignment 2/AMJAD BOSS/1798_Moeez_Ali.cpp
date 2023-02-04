#include <iostream>
#include <fstream>
using namespace std;
void display(int **w, int **p, int row, int col);
void dataentry(int **&w, int **&p, int &row, int &col, int key);
int **transpose(int **w, int **p, int **&q, int row, int col);
int **addition(int **pp, int **w2, int **z1, int **p2, int **&z3, int row1, int row2, int col1, int col2);

int **addition(int **pp, int **w2, int **z1, int **p2, int **&z3, int row1, int row2, int col1, int col2)
{
	int **Answer = nullptr;
	int ctr = 0;

	if (col1 != col2 && row1 != row2)
	{
		cout << "Matrices not confirmable for addition..... Not Possible!!" << endl;
		return nullptr;
	}
	else
	{
		z3 = new int *[row1];
		Answer = new int *[row1];

		for (int a = 0; a < row1; a++)
		{
			ctr = z1[a][0] + p2[a][0];

			for (int b = 1; b <= z1[a][0]; b++)
			{
				int t = 1;
				while (t <= p2[a][0])
				{
					if (z1[a][b] == p2[a][t])
						ctr--;
					t++;
				}
			}
			z3[a] = new int[ctr + 1];
			Answer[a] = new int[ctr];
			z3[a][0] = ctr;
		}
		for (int a = 0; a < row1; a++)
		{
			int l = 0;
			int y = 1;
			int x = 1, z = 1;
			int b = 0;
			while (b < col1)
			{

				if (z1[a][x] == b && p2[a][y] == b)
				{
					z3[a][z] = b;
					Answer[a][l] = pp[a][x - 1] + w2[a][y - 1];
					z3[a][z] = b;
					x++;
					l++;
					y++;
					z++;
				}

				else if (z1[a][x] == b)
				{
					z3[a][z] = b;
					Answer[a][l] = pp[a][x - 1];
					x++;
					z++;
					l++;
				}

				else if (p2[a][y] == b)
				{
					z3[a][z] = b;
					Answer[a][l] = w2[a][y - 1];
					z++;
					y++;
					l++;
				}
				b++;
			}
		}
		return Answer;
	}
}

int **transpose(int **w, int **p, int **&q, int row, int col)
{

	int **Answer = new int *[row];
	int s = 0;
	int b = 0;
	int y = 1, z = 0;
	int ctr = 0;

	int a = 0;
	while (a < row)
	{
		s = s + p[a][0];
		a++;
	}
	int **transpose = new int *[s];
	int **transpose2 = new int *[s];
	a = 0;
	while (a < s)
	{
		transpose[a] = new int[3];
		transpose2[a] = new int[3];
		a++;
	}
	z = p[0][0];
	a = 0;
	while (a < s)
	{
		transpose[a][0] = b;
		transpose[a][1] = p[b][y];
		transpose[a][2] = w[b][y - 1];
		z--;
		y++;

		if (z == 0 && b < 4)
		{
			b++;
			y = 1;
			z = p[b][0];
		}
		a++;
	}

	int k = 0;
	a = 0;
	while (a < col)
	{
		b = 0;
		while (b < s)
		{
			if (transpose[b][1] == a)
			{
				transpose2[k][0] = transpose[k][1];
				transpose2[k][1] = transpose[k][0];
				transpose2[k][2] = transpose[k][2];
				k++;
			}
			b++;
		}
		a++;
	}
	q = new int *[row];
	a = 0;
	while (a < row)
	{
		ctr = 0;
		int b = 0;
		while (b < s)
		{
			if (transpose2[b][0] == a)
				ctr++;
			b++;
		}
		q[a] = new int[ctr + 1];
		Answer[a] = new int[ctr];
		q[a][0] = ctr;
		ctr = 0;
		a++;
	}
	a = 0;
	while (a < row)
	{
		int x = 1;
		b = 0;

		while (b < s)
		{
			if (transpose2[b][0] == a)
			{

				q[a][x] = transpose2[b][1];
				Answer[a][x - 1] = transpose2[b][2];
				x++;
			}
			b++;
		}
		a++;
	}
	a = 0;
	while (a < row)
	{
		delete[] transpose[a];
		delete[] transpose2[a];
		a++;
	}

	delete[] transpose;
	delete[] transpose2;

	return Answer;
}
void dataentry(int **&w, int **&p, int &row, int &col, int key)
{
	int nzc;
	ifstream fin("1798.txt");
	int num;

	if (key == 1)
	{
		fin >> row;
		fin >> col;
		w = new int *[row];
		p = new int *[row];
		int x = 0;
		while (x < row)
		{

			fin >> nzc;
			p[x] = new int[nzc + 1];
			w[x] = new int[nzc];
			p[x][0] = nzc;
			int m = nzc, b = 0;
			while (b < m)
			{
				fin >> p[x][b + 1];
				fin >> w[x][b];
				b++;
			}
			x++;
		}
	}
	else if (key == 2)
	{
		char temp[100];
		int skiprows = 0;
		fin >> skiprows;
		int x = 0;
		while (x <= skiprows)
		{
			fin.getline(temp, 99, '\n');
			x++;
		}
		fin >> row;
		fin >> col;
		w = new int *[row];
		p = new int *[row];
		x = 0;
		while (x < row)
		{

			fin >> nzc;
			p[x] = new int[nzc + 1];
			w[x] = new int[nzc];
			p[x][0] = nzc;
			int m = nzc, b = 0;
			while (b < m)
			{
				fin >> p[x][b + 1];
				fin >> w[x][b];
				b++;
			}
			x++;
		}
	}
}







void display(int **w, int **p, int row, int col)
{

	for (int x = 0; x < row; x++)
	{
		for (int y = 0, a = 1; y < col; y++)
		{
			if (p[x][a] == y)
			{
				cout << w[x][a - 1] << "  ";
				a++;
			}
			else
				cout << 0 << "  ";
		}
		cout << endl;
	}
}

int main()
{

	int **w = nullptr;
	int **q = nullptr;
	int check = 0;
	int **Answer = nullptr;
	int **p = nullptr;
	int key2 = 2;
	int choice = 0;
	int **w2 = nullptr;
	int row = 0, col = 0;
	int **p2 = nullptr;
	int row2 = 0, col2 = 0;
	int key1 = 1;
	dataentry(w, p, row, col, key1);
	cout << endl
		 << endl;
	cout << "Fetching Data from the file!" << endl
		 << "Matrix is: " << endl;
	display(w, p, row, col);

	cout << endl
		 << endl;
	dataentry(w2, p2, row2, col2, key2);
	cout<<"The second matrix is: "<<endl;
	display(w, p, row, col);

	cout << endl;
a:
	cout << "Enter the choice to find the respective operation:" << endl;
	cout << "1. The addition is {press 1}: " << endl;
	cout << "2. The transpose is: {press 2}: " << endl;
	cin >> choice;
	cout << endl;
	if (choice == 1)
	{
		cout << "Matrix 2" << endl;
		display(w2, p2, row2, col2);
		Answer = addition(w, w2, p, p2, q, row, row2, col, col2);
		if (Answer != nullptr)
		{
			cout << endl
				 << "The addition of the matrices is: " << endl;
			display(Answer, q, row, col);
		}
	}
	else if (choice == 2)
	{
		Answer = transpose(w, p, q, row, col);
		cout << endl
			 << "The transpose is: " << endl;
		display(Answer, q, row, col);
	}
	else
	{
		goto a;
	}
	delete[] Answer;
	delete[] q;
	delete[] w;
	delete[] p;
	delete[] w2;
	delete[] p2;

	Answer = nullptr;
	q = nullptr;
	w = nullptr;
	p = nullptr;
	w2 = nullptr;
	p2 = nullptr;
	cout << endl;
	return 0;
}