#include<iostream>
#include<fstream>
using namespace std;
void Input(int**& mat, int**& index, int& row, int& col, int**& mat2, int**& index2, int& row2, int& col2)
{
	int n = 0;
	ifstream fin("matrix1.txt");
	fin >> row;
	fin >> col;
	index = new int* [row];
	mat = new int* [row];
	for (int i = 0; i < row; i++)
	{
		fin >> n;
		index[i] = new int[n + 1];
		mat[i] = new int[n];
		index[i][0] = n;
		for (int j = 0, x = 1, y = 0, m = n; j < m * 2; j++)
		{
			if (j % 2 == 0)
			{
				fin >> index[i][x];
				x++;
			}
			else if (j % 2 == 1)
			{
				fin >> mat[i][y];
				y++;
			}
		}
	}
	fin >> row2;
	fin >> col2;
	index2 = new int* [row2];
	mat2 = new int* [row2];
	for (int i = 0; i < row2; i++)
	{
		fin >> n;
		index2[i] = new int[n + 1];
		mat2[i] = new int[n];
		index2[i][0] = n;
		for (int j = 0, x = 1, y = 0, m = n; j < m * 2; j++)
		{
			if (j % 2 == 0)
			{
				fin >> index2[i][x];
				x++;
			}
			else if (j % 2 == 1)
			{
				fin >> mat2[i][y];
				y++;
			}
		}
	}
}
void Output(int** mat, int row, int col, int** index)
{
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0, x = 1; j < col; j++)
		{
			if (index[i][x] == j)
			{
				cout << mat[i][x - 1] << "  ";
				x++;
			}
			else
				cout << 0 << "  ";
		}
		cout << endl;
	}
}
int** addition(int** mat1, int row1, int col1, int** index1, int** mat2, int row2, int col2, int** index2, int**& index3)
{
	int** result = nullptr;
	int count = 0, flag = 0, flag2 = 0;
	if (row1 == row2 && col1 == col2)
	{
		index3 = new int* [row1];
		result = new int* [row1];
		for (int i = 0; i < row1; i++)
		{
			count = index1[i][0] + index2[i][0];
			for (int j = 1; j <= index1[i][0]; j++)
			{
				for (int k = 1; k <= index2[i][0]; k++)
				{
					if (index1[i][j] == index2[i][k])
						count--;
				}
				
			}
			index3[i] = new int[count + 1];
			result[i] = new int[count];
			index3[i][0] = count;
		}
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0,l=0, y = 1, x = 1,z=1; j < col1; j++)
			{
				if (index1[i][x] == j && index2[i][y] == j)
				{
					index3[i][z] = j;
					result[i][l] = mat1[i][x-1] + mat2[i][y-1];
					x++;
					l++;
					index3[i][z] = j;
					y++;
					z++;
				}
				else if (index1[i][x] == j)
				{
					
					index3[i][z] = j;
					result[i][l] = mat1[i][x-1];
					x++;
					z++;
					l++;
				}
				else if (index2[i][y] == j)
				{
					result[i][l] = mat2[i][y-1];
					index3[i][z] = j;
					z++;
					y++;
					l++;
				}
			}
		}
	}
	else
	{
		cout << "Addition is not possible with these matrixes" << endl;
		return result = nullptr;
	}
	return result;
}
int** Transpose(int** mat, int row, int col, int** index, int**& index_res,int check)
{
	int** result_transp = new int* [row];
	int size = 0, j = 0, y = 1, z = 0, count = 0;;
	for (int i = 0; i < row; i++)
		size += index[i][0];
	int** transp = new int* [size];
	int** transp2 = new int* [size];
	for (int i = 0; i < size; i++)
	{
		transp[i] = new int[3];
		transp2[i] = new int[3];
	}
	z = index[0][0];
	y = 1;
	for (int i = 0; i < size; i++)
	{
	a:		if (z == 0 && j < row)
	{

		j++;
		if (j >= row)
			goto out;
		y = 1;
		z = index[j][0];
		if (z == 0)
			goto a;
	}
	transp[i][0] = j;
	transp[i][1] = index[j][y];
	transp[i][2] = mat[j][y - 1];
	z--;
	y++;

	}
out:;

	int k = 0;
	for (int i = 0; i < col; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (transp[j][1] == i)
			{
				transp2[k][0] = transp[k][1];
				transp2[k][1] = transp[k][0];
				transp2[k][2] = transp[k][2];
				k++;
			}
		}

	}
	index_res = new int* [row];
	for (int i = 0; i < row; i++)
	{
		count = 0;
		for (int j = 0; j < size; j++)
		{
			if (transp2[j][0] == i)
				count++;

		}
		index_res[i] = new int[count + 1];
		result_transp[i] = new int[count];
		index_res[i][0] = count;
		count = 0;
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0, x = 1; j < size; j++)
		{
			if (transp2[j][0] == i)
			{
				index_res[i][x] = transp2[j][1];
				result_transp[i][x - 1] = transp2[j][2];
				x++;
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		delete[]transp[i];
		delete[]transp2[i];
	}
	delete[]transp;
	delete[]transp2;
	
	return result_transp;
}
int** Multiplication(int** mat1, int row1, int col1, int** index1, int** mat2, int row2, int col2, int** index2, int**& index3)
{
	int** result_mul = nullptr;
	if (col1 == row2)
	{
		int size1 = 0, size2 = 0, count = 0;
		int** index_transp = nullptr, ** copy_mat1 = nullptr, ** copy_transp = nullptr, ** copy_index1 = nullptr, ** copy_index_transp = nullptr;
		int** transp_mat2 = nullptr;
		transp_mat2 = Transpose(mat2, row2, col2, index2, index_transp, 1);
		for (int i = 0; i < row1; i++)
			size1 += index1[i][0];
		for (int i = 0; i < row2; i++)
			size2 += index2[i][0];
		copy_mat1 = new int* [size1];
		for (int i = 0; i < size1; i++)
		{
			copy_mat1[i] = new int[3];
		}
		copy_transp = new int* [size2];
		for (int i = 0; i < size2; i++)
		{
			copy_transp[i] = new int[3];
		}
		int z = 0, j = 0, y = 1;
		z = index1[0][0];
		for (int i = 0; i < size1; i++)
		{
			if (z == 0 && j < row1 - 1)
			{
			a:	j++;
				if (j >= row1)
					goto out;
				y = 1;
				z = index1[j][0];
			}
			if (z == 0)
				goto a;
			copy_mat1[i][0] = j;
			copy_mat1[i][1] = index1[j][y];
			copy_mat1[i][2] = mat1[j][y - 1];
			z--;
			y++;

		}
	out:;
		z = index1[0][0];
		y = 1;
		j = 0;
		for (int i = 0; i < size1; i++)
		{
			if (z == 0 && j < row2 - 1)
			{
				j++;
				y = 1;
				z = index_transp[j][0];
			}
			if (z == 0)
				continue;
			copy_transp[i][0] = j;
			copy_transp[i][1] = index_transp[j][y];
			copy_transp[i][2] = transp_mat2[j][y - 1];

			z--;
			y++;

		}
		result_mul = new int* [row1];
		index3 = new int* [row1];
		int** dumy = nullptr;
		dumy = new int* [size1 + size2];
		for (int i = 0; i < size1 + size2; i++)
		{
			dumy[i] = new int[3];
		}
		for (int i = 0; i < size2; i++)
		{
			count = 0;
			for (int j = 0; j < size1; j++)
			{
				if (copy_transp[i][1] == copy_mat1[j][1])
				{
					dumy[i][0] = copy_mat1[j][0];
					dumy[i][1] = copy_transp[i][0];
					dumy[i][2] = copy_transp[i][2] * copy_mat1[j][2];
				}
			}
			if (i == size1 - 1)
			{
				dumy[i][0] = -1;
				dumy[i][1] = -1;
				dumy[i][2] = -1;
			}
		}
		for (int i = 0; i < row1; i++)
		{
			count = 0;
			for (int j = 0; j < size1 + size2 && dumy[j][0] != -1; j++)
			{
				if (dumy[j][0] == i)
					count++;
			}
			index3[i] = new int[count + 1];
			result_mul[i] = new int[count];
			index3[i][0] = count;
		}
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0, x = 1; j < size1 + size2 && dumy[j][0] != -1; j++)
			{
				if (dumy[j][0] == i)
				{
					index3[i][x] = dumy[j][1];
					result_mul[i][x - 1] = dumy[j][2];
					x++;
				}
			}
		}
		int min = index3[0][1];
		for (int i = 0; i < row1; i++)
		{
			for (int j = 1; j < index3[i][0]; j++)
			{
				for (int k = j + 1; k < index3[i][0]; k++)
				{
					if (index3[i][j] > index3[i][k])
					{
						swap(index3[i][j], index3[i][k]);
						swap(result_mul[i][j - 1], result_mul[i][k - 1]);
					}
				}
			}
		}
		for (int i = 0; i < size1; i++)
			delete[]copy_mat1[i];
		for (int i = 0; i < size2; i++)
			delete[]copy_transp[i];
		for (int i = 0; i < size1 + size2; i++)
			delete[]dumy[i];
		delete[]copy_mat1;
		delete[]copy_transp;
		delete[]dumy;
		copy_mat1 = nullptr;
		dumy = nullptr;
		copy_transp = nullptr;
	}
	else

	{
		cout << "Multiplication is not possible with these matrixes" << endl;
		return result_mul = nullptr;
	}
	return result_mul;
}
int main()
{
	int check = 0, ** result=nullptr, ** index3 = nullptr;
	int** mat=nullptr, ** index=nullptr, row = 0, col = 0;
	int** mat2=nullptr, **index2=nullptr, row2 = 0, col2 = 0;
	Input(mat,index, row, col,mat2,index2,row2,col2);
	int choice = 0;
	cout << "Matrix 1" << endl;
	Output(mat, row, col, index);
	cout << "Matrix 2" << endl;
	Output(mat2, row2, col2, index2);
again:	cout << "Select choice" << endl;
	cout << "1 - sum" << endl;
	cout << "2 - Transpose" << endl;
	cout << "3 - Multiplication" << endl;
	cin >> choice;
	if (choice == 1)
	{
		result = addition(mat, row, col, index, mat2, row2, col2, index2, index3);
	if(result!=nullptr)
		Output(result, row, col, index3);
	}
	else if (choice == 2)
	{
again2:		cout << "Select option" << endl;
		cout << "1 - transpose of matrix 1" << endl;
		cout << "2 - transpose of matrix 2" << endl;
		cin >> choice;
		if (choice == 1)
		{
			result = Transpose(mat, row, col, index, index3,0);
			if (result != nullptr)
			Output(result, col, row, index3);
		}
		else if (choice == 2)
		{
			result = Transpose(mat2, row2, col2, index2, index3,1);
			if (result != nullptr)
			Output(result, col, row, index3);
		}
		else
		{
			cout << "wrong input" << endl << "Input again" << endl;
			goto again2;
		}
	}
	else if (choice == 3)
	{
		result = Multiplication(mat, row, col, index, mat2, row2, col2, index2, index3);
		if (result != nullptr)
		Output(result, row2, col2, index3);
	}
	else
	{
		cout << "Wrong input" << endl;
		cout << "Select again" << endl;
		goto again;
	}
	if(result!=nullptr)
	for (int i = 0; i < row; i++)
	{
		delete[]mat[i];
		delete[]mat2[i];
		delete[]result[i];
		delete[]index[i];
		delete[]index2[i];
		delete[]index3[i];
	}
	delete[]mat;
	delete[]mat2;
	delete[]result;
	delete[]index;
	delete[]index2;
	delete[]index3;
	mat = nullptr;
	mat2 = nullptr;
	result = nullptr;
	index = nullptr;
	index2 = nullptr;
	index3 = nullptr;
	return 0;
}