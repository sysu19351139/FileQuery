#include"Shape.h"
using namespace std;

Rectangle::Rectangle(double x, double y) :xx(x), yy(y)
{
	cout << "constructor 2" << endl;
}

double Rectangle::GetArea()
{
	area_ = xx * yy;
	return area_;
}

Circle::Circle(double r) :rr(r)
{
	cout << "constructor 3" << endl;
}

double Circle::GetArea()
{
	const double pi = 3.14;
	area_ = pi * rr * rr;
	return area_;
}
square::square(double l) :ll(l), Rectangle(l, l)
{
	cout << "constructor 4" << endl;
}