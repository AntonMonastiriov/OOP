#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

class Figure
{
	protected:
	string color;
	public:
	Figure()
	{
		color = "orange";
  		printf("Created paramentless figure\n");
	}
	Figure(string s)
	{
		color = s;
  		printf("Created figure\n");
	}
	virtual ~Figure()
	{
		cout << "Destroyed figure\n";
	}
	virtual void show()
	{
  		cout << "Figure of "<< color << " color" << endl;
	}
};
class Sphere : public Figure
{
	private:
	double radius;
	public:

	Sphere(double r)
	{
		radius = r;
  		printf("Created Sphere\n");
	}
 	void show()
	{
  		cout << "Sphere of " << color << " color with radius of " << radius << " cm" << endl;
	}
	double get()  
	{
		return radius;
	}
	void set(double r)
	{
		radius = r;
  		cout << "New radius of the sphere: " << radius << " cm\n";
	}
	double area()
	{
		return 4*radius*radius*M_PI;
	}
	double volume()
	{
		return (4/3)*M_PI*radius*radius*radius;
	}
	virtual ~Sphere()
	{
		cout << "Destroyed sphere\n";
	}
};



int main () 
{
	Figure f1 = Figure();
	f1.show();
	
	Figure f2 = Figure("green");
	f2.show();
	
	Sphere s1 = Sphere(4.2);
	s1.show();
	
	s1.set(2);
	
	cout << "Area: " << s1.area() << "cm^2\n";
	cout << "Volume " << s1.volume() << "cm^3\n";
	
	Figure* figures[2];
	figures[0] = new Figure("Red");
	figures[1] = new Sphere(14.2);
	figures[0] -> show();
	figures[1] -> show();
	
	delete figures[0];
	delete figures[1];
	}

