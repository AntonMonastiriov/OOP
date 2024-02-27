#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

class Complex
{	
	protected:
	double x;
	double y;
	public:
	Complex()
	{x = 0; y = 0;}
	
	Complex(double p_x, double p_y)
	{
		x = p_x;
  		y = p_y;
	}	
	void show()
	{
		cout << "z = " << x;
	 	if(y > 0 ) cout << "+" << y << "i\n";
 	 	else cout  << y << "i\n";
	}
	
	double complex_abs()
	{
		return sqrt(x*x + y*y);
	}
	
	double complex_arg()
	{
	if(x >= 0 && y >= 0) return atan(y/x);
	else if(x > 0 && y < 0) return -atan(y/x);
	else if(x < 0 && y > 0) return M_PI-atan(y/x);
	else return -M_PI+atan(y/x);
	}

	void print_trigonometric_form()
	{
		cout <<"Trigonometric form of complex number: " << complex_abs() << "*(cos(" << complex_arg() << ")+i*sin(" << complex_arg() << ")\n";
	}
	void print_exponential_form()
	{
		cout <<"Exponential form of complex number: " << complex_abs() << "*exp(" << complex_arg() << "i)\n";
	}
	~Complex() {}
};

int main()
{
	cout << "Input x and y\n";
	double x,y;
	cin >> x >> y;
	Complex z = Complex(x, y);
	z.show();
	cout << setprecision(3);
	cout << "Abs of complex number: " << z.complex_abs() << endl;
	cout << "Argument of complex number: " << z.complex_arg() << endl;
	z.print_trigonometric_form();
	z.print_exponential_form();
}