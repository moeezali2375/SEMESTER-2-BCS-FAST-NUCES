#include <iostream>
using namespace std;

class Matrix
{
private:
	int **matrix1;
	int matrix1row, matrix1col;

public:
	Matrix();
	Matrix(int **matrix, int row, int col);
	friend istream &operator>>(istream &in, Matrix &m1);
	friend ostream &operator<<(ostream &out, Matrix &m1);
	Matrix &operator+(const Matrix a1);
	Matrix(Matrix &m);
};

Matrix::Matrix()
{
	matrix1row = 0, matrix1col = 0;
	matrix1 = NULL;

	// cout << "Enter the numbr of rows:";
	// cin >> matrix1row;
	// cout << "Enter the numner of the coloumns";
	// cin >> matrix1col;
}
Matrix::Matrix(int **matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			this->matrix1[i][j] = matrix[i][j];
		}
	}
	this->matrix1row = row;
	this->matrix1col = col;
}
Matrix::Matrix(Matrix &m)
{
	cout << "Copy constructor works" << endl;
	this->matrix1 = new int *[m.matrix1row];
	for (int i = 0; i < m.matrix1row; i++)
	{
		this->matrix1[i] = new int[m.matrix1col];
	}
	for (int i = 0; i < m.matrix1row; i++)
	{
		for (int j = 0; j < m.matrix1col; j++)
		{
			this->matrix1[i][j] = m.matrix1[i][j];
		}
	}
	this->matrix1row = m.matrix1row;
	this->matrix1col = m.matrix1col;
}
Matrix &Matrix::operator+(Matrix a1)
{
	if (this->matrix1row == a1.matrix1row && this->matrix1col == a1.matrix1col)
	{
		for (int i = 0; i < this->matrix1row; i++)
		{
			for (int j = 0; j < this->matrix1col; j++)
			{
				this->matrix1[i][j] += a1.matrix1[i][j];
			}
		}
	}
	else
		cout << "Invalid size of matrix\n";
	return *this;
}
istream &operator>>(istream &in, Matrix &m1)
{
	cout << "Enter number of rows : ";
	cin >> m1.matrix1row;
	cout << "Enter number of columns : ";
	cin >> m1.matrix1col;

	m1.matrix1 = new int *[m1.matrix1row];
	for (int i = 0; i < m1.matrix1row; i++)
	{
		m1.matrix1[i] = new int[m1.matrix1col];
	}
	cout << endl
		 << "Enter elements of matrix : " << endl;
	for (int i = 0; i < m1.matrix1row; i++)
	{
		for (int j = 0; j < m1.matrix1col; j++)
		{
			in >> m1.matrix1[i][j];
		}
	}
	return in;
}
ostream &operator<<(ostream &out, Matrix &m1)
{

	cout << "Matrix is : " << endl;
	for (int i = 0; i < m1.matrix1row; i++)
	{
		for (int j = 0; j < m1.matrix1col; j++)
		{
			out << m1.matrix1[i][j] << " ";
		}
		cout << endl;
	}
	return out;
}
