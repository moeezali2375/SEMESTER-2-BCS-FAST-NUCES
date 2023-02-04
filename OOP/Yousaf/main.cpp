#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
	Matrix m1;
	Matrix m2;
	Matrix m3;
	cin >> m1;
	cout << m1;
	cin >> m2;
	cout << m1;
	cout << m2;
	m3 = m1 + m2;
	// Matrix m3=m1+m2;
	cout << m3;
	return 0;
}