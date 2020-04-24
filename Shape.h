
#include<iostream>
class Shape                                        
{
public:
	Shape(){cout << "constructer 1" << endl;}
	~Shape(){cout << " destructor 1" << endl;}
	double area_;
};

class Rectangle :public Shape                      
{
public:
	Rectangle(double x, double y);
	~Rectangle(){cout << "destructor 2" << endl;}
	double GetArea();
private:
	double xx;
	double yy;
};

class Circle :public Shape
{
public:
	Circle(double r);
	~Circle(){cout << "destructor 3" << endl;}
	double GetArea();
private:
	double rr;
};

class square :public Rectangle
{
public:
	square(double l);
	~square(){cout << "destructor 4" << endl;}
private:
	double ll;
};
