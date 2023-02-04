#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"undergraduate.h"
class graduate :public  undergraduate {
private:
	string thes;
public:
	graduate() { //default constructor
		thes = '\0';
	}
	void set_thes(string m) {//function
		thes = m;
	}
	string get_thes() {
		return thes;
	}
};