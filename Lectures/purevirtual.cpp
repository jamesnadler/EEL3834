#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Figure { 
	public: 
		virtual double perimeter() = 0;
		virtual double area() = 0;
};

class Circle : public Figure {

	public:
		double perimeter() {return (2 * 3.14 * radius);};
		double area() {	return (3.14 * radius * radius);};
		Circle(double r) {radius = r;}

	private:
		double radius;
};


class Rectangle : public Figure {

	public:
		double perimeter() {return (2 * (side1 + side2));};
		double area() {return (side1 * side2);};
		Rectangle(double s1, double s2) {side1= s1;side2 = s2;};

	private:
		double side1, side2;
 

};

class Triangle : public Figure {

	public:
		double perimeter() {return (2 * (side1 + side2 + side3));};
		double area() {return ((side1 * side2)/2);};
		Triangle(double s1, double s2, double s3) {side1= s1; side2 = s2; side3 = s3;};

	private:
		double side1, side2, side3;
 

};


int main() {


	Figure *rect = new Rectangle(2,5);
	Figure *circle = new Circle(10);
	Figure *triangle = new Triangle(3,4,5);

		
	cout << "Rectangle - Area: " << rect->area() << " Perimeter: " << rect->perimeter() << endl;	
	cout << "Circle - Area: " << circle->area() << " Perimeter: " << circle->perimeter() << endl;	
	cout << "Rectangle - Area: " << rect->area() << " Perimeter: " << rect->perimeter() << endl;	
	cout << "Tiangle - Area: " << triangle->area() << " Perimeter: " << triangle->perimeter() << endl;	
        
        return 0;

}
