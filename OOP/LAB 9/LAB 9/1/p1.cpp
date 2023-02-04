#include<iostream>
using namespace std;
#include"Square.h"
#include"Rectangle.h"

int main() {
	rectangle y;
	Square x;
	x.set_width(20); // calling setter
	x.set_length(10);
	y.set_width(40);
	y.set_length(30);
	x.display(); //displaying
	y.display();
	x.Area(); //Function
	y.Area();
	x.Volume();
	y.Volume();
	x.~Square(); //calling destructor
	y.~rectangle();
	return 0;
}