//Hung Nguyen
//October 18th, 2012
//ELEC 415 Midterm

#include <iostream>
#include <math.h>
using namespace std;

const double PI=2.0*asin(1.0);

class Circle
{
	protected:
		double radius;
	public:
		Circle(double=1.0);
		double calcval();
};

Circle::Circle(double r)
{
	radius=r;
}

double Circle::calcval()
{
	return(PI*pow(radius,2));
}

class Cylinder:public Circle
{
	protected:
		double length;
	public:
		Cylinder(double r=1.0, double l=1.0):Circle(r),length(l){}
		double calcval();
		double surface();
};

double Cylinder::calcval()
{
	return(length*Circle::calcval());
}

class Sphere:public Circle
{
	public:
		Sphere(double r=1.0):Circle(r){}
		double calcval();
		double surface();
};

double Sphere::calcval()
{
	return (PI*pow(radius,3)*4/3);
}

double Sphere::surface()
{
	return(4*Circle::calcval());
}

int main()
{
	Circle C1(12.5);
	Cylinder Cyl1(2,5);
	Sphere S1(5.75),S2;

	cout<<"The area of circle, C1, is "<<C1.calcval()<<"."<<endl;

	cout<<"The volume of cylinder, Cyl1, is "<<Cyl1.calcval()<<"."<<endl;
	cout<<"The surface area of cylinder, Cyl1, is "<<Cyl1.surface()<<"."<<endl;

	cout<<"The volume of sphere, S1, is "<<S1.calcval()<<"."<<endl;
	cout<<"The surface area of sphere, S1, is "<<S1.surface()<<"."<<endl;

	return 0;
}
