#include<iostream>
using namespace std;


class Box
{
private:
	int length;
	int breadth;
	int height;

public:
	static int  objectCount ;
	Box()
	{
		length = 0;
		breadth = 0;
		height = 0;
		objectCount++;
	}
	Box(int a, int b, int c)
	{
		length = a;
		breadth = b;
		height = c;
		objectCount++;
	}

	int get_height(){//Getters
		return height;
	}
	int get_length(){
		return length;
	}
	int get_breadth(){
		return breadth;
	}


	void set_height(int temp1){	//Setters
		height = temp1;
	}
	void set_length(int temp2){
		length = temp2;
	}
	void set_breadth(int temp3){
		breadth = temp3;
	}
	

	float Box_Volume(){
		int vol = length*breadth*height;
		return vol;
	}
	float Box_Area(){
		int Area = 2 * (length*breadth + length*height + breadth*height);
		return Area;
	}


};
int Box::objectCount = 0;
int main()
{
	Box x(1, 2, 3);
	Box y(4, 5, 6);

	cout << "\nArea of x = " << x.Box_Area() << "\n";
	cout << "\nVolume of y = " << y.Box_Volume() << "\n";
	cout << "\nArea of y = " << y.Box_Area() << "\n";
	cout << "\nStatic count = " <<  x.objectCount << "\n\n";


	return 0;
}