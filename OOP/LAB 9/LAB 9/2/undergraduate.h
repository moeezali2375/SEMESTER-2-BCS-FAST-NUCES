#pragma once
#include<iostream>
using namespace std;
#include<string.h>
#include"Person.h"

class undergraduate :public Person {
protected:
	int roll_number;
	float cgpa;
	string fyp_name;
	string supervisor_name;
public:
	undergraduate() { //default constructor
		roll_number = 0;
		cgpa = 0;
		fyp_name = "\0";
		supervisor_name = '\0';
	}

	void set_roll_number(int m) {//setter_1
		roll_number = m;
	}
	void set_cgpa(float m) {//Setter_2
		cgpa = m;
	}
	void set_fyp(string m) {//setter_3
		fyp_name= m;
	}
	void set_supervisor_name(string m) {//setter_4
		supervisor_name = m;
	}
	
	int get_roll_number() {//getters_1
		return roll_number;
	}
	 float get_cgpa() {//getters_2
		return cgpa;
	}
	string get_fyp() {//getters_3
		return fyp_name;
	}
	string get_supervisor_name() {//getters_4
		return supervisor_name;
	}
};