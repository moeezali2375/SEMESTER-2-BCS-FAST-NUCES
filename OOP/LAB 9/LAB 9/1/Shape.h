#pragma once
#include<iostream>
using namespace std;

class Shape {
protected:
	float wid;
	float len;
public:
	Shape() { //default constructor
		cout << "\nShape() called ! \n";
		wid = 0;
		len = 0;
	}
	void set_width(float m) { // Setter_2
		wid = m;

	}
	void set_length(float m) { // Setter_1
		len = m;
	}
	float get_width() { //getter_2
		return wid;
	}
	float get_length() { //getter_1
		return len;
	}
	~Shape() { // destructor
		cout << "\n ~Shape() called ! \n";
	}
};