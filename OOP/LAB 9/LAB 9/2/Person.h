#pragma once
#include<iostream>
using namespace std;
#include<string.h>

class Person {
protected:
	string Full_Name;
	string Last_Name;
	int age;
public:
	Person() { //default constructor
		Full_Name = "\0";
		Last_Name = '\0';
		age = 0;
	}
	void set_Full_Name(string a) {//Setter_1
		Full_Name = a;
	}
	void set_Last_Name(string a) {//Setter_2
		Last_Name = a;
	}
	void set_age(int a) {//Setter_3
		age = a;
	}
	string get_Full_Name() {//getter_1
		return Full_Name;
	}
	string get_Last_Name() {//getter_2
		return Last_Name;
	}
	int get_age() {//getter_3
		return age;
	}
};