#include <iostream>
#include <cmath>

using namespace std;

void CheckCircleCoordinates(float x, float y, float radius, float& sum_Xsquared_and_Ysquared, float& squaredRadius);

int main()
{
	float inputNumber_X = 0.0;
	float inputNumber_Y = 0.0;
	float sum_Xsquared_and_Ysquared = 0.0;
	float radius = 4.0;
	float triangleSide = 3.0;
	float squaredRadius = 0.0;
	float eps = 1e-3;
	float inclinationRadius = 0.0;
	float inclinationUser = 0.0;


	cout << "Enter two float numbers (up to the 3rd digit after the decimal point) so you can see where it lands on the given graph!" << endl;
	cout << "Enter first number: ";
	cin >> inputNumber_X;
	cout << "Enter second number: ";
	cin >> inputNumber_Y;


	//Formula needed to check if the dot is on the circle
	CheckCircleCoordinates(inputNumber_X, inputNumber_Y, radius, sum_Xsquared_and_Ysquared, squaredRadius);

	//Calculates the line from the axis X to the point B
	float lineX_B = sqrt((radius * radius) - (triangleSide * triangleSide));

	//Calculates the inclination of the dot given by the user
	inclinationUser = inputNumber_Y / inputNumber_X;

	//Calculates the inclination of the radius
	inclinationRadius = lineX_B / triangleSide;


	// Checks if the dot lands somewhere in the outlined graph 
	if (inputNumber_X > 4 || inputNumber_X < -4) {
		cout << "Outside!";
		return 0;
	}

	// Checks if the dot is on the circle
	if (abs(sum_Xsquared_and_Ysquared - squaredRadius) < eps) {
		cout << "On the edge!";
	}

	//Checks if the dot is on the Y axis
	if (inputNumber_X == 0) {
		if (inputNumber_Y <= 6 && inputNumber_Y >= -6) {
			cout << "On the edge!";
		}
	}
	//Checks if the dot is on the F-I line
	if (inputNumber_X >= -1 && inputNumber_X <= 1) {
		if (inputNumber_Y == 5) {
			cout << "On the edge!";
		}
	}

	//Checks if the dot is on the radius O-B
	if (abs(inclinationRadius - inclinationUser) < eps) {
		cout << "On the edge!";
	}




}
//Formula needed to check if the dot is on the circle
void CheckCircleCoordinates(float x, float y, float radius, float& sum_Xsquared_and_Ysquared, float& squaredRadius) {
	sum_Xsquared_and_Ysquared = (x * x) + (y * y);
	squaredRadius = radius * radius;
}


