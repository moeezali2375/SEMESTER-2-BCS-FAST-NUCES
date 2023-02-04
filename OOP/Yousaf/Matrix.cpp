#include <iostream>
#include "Matrix.h"
using namespace std;
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
Matrix Matrix::operator+(Matrix a1)
{
	Matrix temp;
	temp.matrix1 = new int *[a1.matrix1row];
	for (int i = 0; i < a1.matrix1row; i++)
	{
		temp.matrix1[i] = new int[a1.matrix1col];
	}
	if (matrix1row != a1.matrix1row || matrix1col != a1.matrix1col)
	{
		cout << "matrix size must be same!";
	}
	else
	{
		for (int i = 0; i < a1.matrix1row; i++)
		{
			for (int j = 0; j < a1.matrix1row; j++)
			{
				temp.matrix1[i][j] = this->matrix1[i][j] + a1.matrix1[i][j];
			}
		}
	}
	return temp;
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
