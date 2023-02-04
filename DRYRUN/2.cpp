#include<iostream>
using namespace std;
class baseClass{
public:
string name;
string traits;
double age;
};
class petClass {
private:
string name;
string traits;
double * age; //age in years
public:
baseClass basebj;
petclass (string name="Bailey", string traits="Husky", double* age=NULL){
this->name=name;
this->traits=traits;
this->age= age;
}
petClass (baseClass base0bj){
cout<<baseObj.name<<end1<<baseObj.traits<<endl<<"Of the base object";
}


void showPet(){
cout << this->name<<"It"<< this->traits;
cout<<"It" << *this->age << endl;
};

int main ()
{
 petClass *dog= new petClass();
dog->baseObj.name="Jacky";
dog->baseObj.traits="Siberian";
dog->baseObj.age= 4.5;
petClass * myDog = new petClass(dog->baseObj);
myDog->showPet();
delete myDog;
delete dog;   
}