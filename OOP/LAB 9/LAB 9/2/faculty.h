#include<iostream>
using namespace std;
#include"Person.h"
#include<string.h>

class faculty :public Person {
private:
	char exten[4];
	int course_cnt;
public:
	faculty() { // efault constructor
		course_cnt = 0;
		//exten[0] = nullptr;
	}
	void set_extension(char m[]) {// setter_2
		strcpy(exten,m);
	}
	void set_course(int m) {//Setters_1
		course_cnt = m;
	}
	int get_course() {//getter_1
		return course_cnt;
	}
	char* get_extension() {
		return exten;
	}
};