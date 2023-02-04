#include<iostream>
using namespace std;
#include"Shape.h"
class Square :public Shape {
private:
	float volume;
	float area;
public:
	Square() { // default constructor
		cout << "\nSquare() called !  \n";
		volume = 0;
		area = 0;
	}
	void Area() {
		area = wid * len;
		cout << "\nThe area of shape is = " << area << "\n";
	}
	void display() {
		cout << "\nThe length of shape is = " << get_length() << " & width of shape is = " << get_width() << "\n";
	}
	void Volume() {
		volume = len * len * len;
		cout << "\nThe volume of shape : " << volume << "\n";
	}
	~Square() { //destructor
		cout << "\n~Squre() called !\n";
	}
};
