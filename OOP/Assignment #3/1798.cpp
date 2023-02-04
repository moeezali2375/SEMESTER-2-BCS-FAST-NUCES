#include <iostream>
#include "vector.h"
#include <cmath>
using namespace std;
int main()

{
	Vector V(4);  // Calling parameterize Constructor
	cout << " Input of Vector v - " << endl;
	cin >> V;//1,2,3,4
	cout << " Output of Vector : " << V << endl << endl;

	cout << " - Copy Constructor - " << endl;
	Vector X(V);
	cout << " Output of ( Copy - Constructor ) Vector : " << X << endl << endl;

	cout << " - Default Constructor - " << endl;
	Vector Y;
	cout << " Output of ( Default ) Vector : " << Y << endl << endl;  // No Output

	cout << " - Overloaded Assignment Operator - " << endl;
	Y = X;
	cout << " Output of ( Assignment operator ) Vector : " << Y << endl << endl;

	cout << " - Testing == operator - " << endl;
	if (V == X)
		cout << " Both Vectors are Equal " << endl;
	else
		cout << " Function not Working Properly " << endl;
	cout << endl;

	cout << " - Subscript Operator -  " << endl;
	cout << " Reading Value from Vector of Index 2 : " << X[2] << endl << endl;

	cout << " Writing Value in Vector " << endl;
	X[2] = 55;
	cout << " Vector After Writing : " << X << endl << endl;

	cout << " - Testing != operator - " << endl;
	if (V != X)
		cout << " Both Vectors are not Equal " << endl;
	else
		cout << " Function not Working Properly " << endl;
	cout << endl;
	cout << " - Dot Product - " << endl;
	float dot = X*Y;
	cout << " Output Of Dot Product : " << dot << endl << endl;

	cout << " - Unit Vector - " << endl;
	//    if you have used and Binary Operator( you can only change your operator sign) than Un-comment the below line
	//    Vector unit = X^Y;

	//    if you have used an unary Operator ( you can only change your operator sign) than Un-Comment the below line
	Vector unit = !X ;

	//    if You have used an used pre or post increment ( you can only change the position of signs )
	Vector temp = X;
	cout << "Unit Vector - " << endl;
	X = temp;
	cout << " Output of Unit vector : " << unit << endl;
	cout << " Program Exited " << endl;
}