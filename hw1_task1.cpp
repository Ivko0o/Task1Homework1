#include <iostream>
#include <cmath>

using namespace std;

void Inclination(double x1, double x2, double y1, double y2, double& inclination);

int main()
{
	double firstNumberX = 0.0;
	double secondNumberY = 0.0;
	double radius = 4.0;
	double inclinationDiameter = 0;
	double inclinationRadius = 0;
	double eps = 1e-4;
	double x1 = 3.0;
	double x2 = -3.0;
	double y1 = 2.646;
	double y2 = -2.646;
	double radiusX = 0.0;
	double radiusY = 0.0;

	

	//Dot B is with coordinates (x = 3 and y = 2,646) - калкулирано с Питагорова теорема
	double lengthB = sqrt(radius * radius - 3 * 3);

	//Calculates the inclination of the diameter B-D
	Inclination(x1, x2, y1, y1, inclinationDiameter);

	// Calculates the inclination of the radius O-C
	Inclination(radiusX, x2, radiusY, y1, inclinationRadius);

	
	cout << "Enter two numbers (up to 3 numbers after the decimal point) to check in which color field of a given figure they land!" << endl;

	//Takes the input from the user
	cout << "Enter X coordinate number: ";
	cin >> firstNumberX;
	cout << "Enter Y coordinate number: ";
	cin >> secondNumberY;
	cout << endl;


	double diameterPoint = inclinationDiameter * firstNumberX;
	

	// If X is bigger than 4 or smalled than -4 it will always be Outside of the field
	if (firstNumberX >= 4.000|| firstNumberX <= -4.000) {
		cout << "Outside!";
	}

	// Checks if the point is on the diameter B-D line
	if (abs(secondNumberY - diameterPoint) < eps) {
		cout << "On the edge!";
		return 0;
	}


	//Checks if the point is on the Y line
	if (firstNumberX == 0.0){
		if (secondNumberY <= 6.0 && secondNumberY >= -5.9999) {
			cout << "On the edge!";
		}
	}

	//Checks if the point is on the B-A line
	if (firstNumberX == 3.0){
		if (secondNumberY <= 2.646 && secondNumberY >= -2.646) {
			cout << "On the edge!";
		}
		else {
			cout << "Outside!";
		}
	}

	//Checks if the point is on the C-D line
	if (firstNumberX == -3.0) {
		if (secondNumberY <= 2.646 && secondNumberY >= -2.646) {
			cout << "On the edge!";
		}
		else {
			cout << "Outside!";
		}
	}
	
	//Checks if the point is on the F-I line
	if (firstNumberX >= -1.0 && firstNumberX <= 1.0) {
		if (secondNumberY == 5.0) {
			cout << "On the edge!";
		}
	}

	//Checks if its in the grey area or on its edges
	if (firstNumberX >= -2.0 && firstNumberX <= 2.0) {
		if (secondNumberY == -6.0 || secondNumberY == -7.0) {
			cout << "On the edge!";

		}
		else if (secondNumberY > -7.0 && secondNumberY < -6.0) {
			cout << "Grey!";
		}
	
	}

}

//Checks the DiameterInclination and rounds it up to the 3rd digit after the decimal point
void Inclination(double x1, double x2, double y1, double y2, double& inclination) {
	inclination = (y2 - y1) / (x2 - x1);
	inclination = (inclination * 1000) / 1000;
}

