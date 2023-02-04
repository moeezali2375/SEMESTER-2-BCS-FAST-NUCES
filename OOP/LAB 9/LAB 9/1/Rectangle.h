#include<iostream>
using namespace std;
#include"Shape.h"
class rectangle :public Shape {
private:
	float volume;
	float area;
public:
	rectangle() { // default constructor
		volume = 0;
		area = 0;
		cout << "\nRectangle() called ! \n";
	}
	void Area() { //functions
		cout << "hello";
		cout << get_width();
		area = wid * len;
		cout << "The Area of shape is = " << area << "\n";
	}
	void display() {
		cout << "The length of shape is : " << len << "  & width is : " << wid << "\n";
	}
	void Volume() {
		volume = len * len * len;
		cout << "The volume of shape : " << volume << "\n";
	}
	~rectangle() { //Destructor
		cout << "\n~Rectangle() called ! \n";
	}
};
