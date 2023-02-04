#include<iostream>
using namespace std;
#include"graduate.h"
#include"faculty.h"
#include"undergraduate.h"

int main() {
	faculty x;
	graduate y;
	undergraduate z;

	x.set_age(20);
	x.set_course(1);
	x.set_Full_Name("Moeez");
	x.set_Last_Name("Ali");
	cout<<"Enter extension: ";
	char extensionnn[4];
	cin.getline (extensionnn,4);
	x.set_extension(extensionnn);
	cout << "\nFaculty member first name :" << x.get_Full_Name()
		<< "\nFaculty member last name :" << x.get_Last_Name()
		<< "\nAge of faculty member is : " << x.get_age()
		<< "\nThe course of faculty member is : " << x.get_course()
		<< "\nThe extension of faculty member is : " << x.get_extension() << endl;



	y.set_Full_Name("SAAD");
	y.set_Last_Name("Ali");
	y.set_roll_number(9876);
	y.set_age(19);
	y.set_cgpa(3.98);
	y.set_fyp("machine learning");
	y.set_supervisor_name("Aamir Wali");
	y.set_thes("Virtual Assistant");
	cout << "\n\nGraduate member first name :" << y.get_Full_Name()
		<< "\nGraduate member last name :" << y.get_Last_Name()
		<< "\nRoll number of Graduate is : " << y.get_roll_number()
		<< "\nAge of Graduate member is : " << y.get_age()
		<< "\nCGPA of Graduate is : " << y.get_cgpa()
		<< "\nFinal Year project of Graduate is : " << y.get_fyp()
		<< "\nSupervisor name of Graduate is : " << y.get_supervisor_name()
		<< "\nThesis of Graduate is : " << y.get_thes();

	z.set_Full_Name("Ali");
	z.set_Last_Name("Asghar");
	z.set_roll_number(123456);
	z.set_age(17);
	z.set_cgpa(3.99);
	z.set_fyp("Smart phones & telecommunication");
	z.set_supervisor_name("Mamona Akbar");

	cout << "\n\nUndergraduate member first name :" << z.get_Full_Name()
		<< "\nUndergraduate member last name :" << z.get_Last_Name()
		<< "\nRoll number of Undergraduate is : " << z.get_roll_number()
		<< "\nAge of Undergraduate member is : " << z.get_age()
		<< "\nCGPA of Undergraduate is : " << z.get_cgpa()
		<< "\nFinal Year project of Undergraduate is : " << z.get_fyp()
		<< "\nSupervisor name of Undergraduate is : " << z.get_supervisor_name()<<"\n\n";


	return 0;
}