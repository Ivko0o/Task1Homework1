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
	float squaredRadius = 0.0;
	float eps = 1e-4;



	cout << "Enter two float numbers (up to the 3rd digit after the decimal point) so you can see where it lands on the given graph!" << endl;
	cout << "Enter first number: ";
	cin >> inputNumber_X;
	cout << "Enter second number: ";
	cin >> inputNumber_Y;


	CheckCircleCoordinates(inputNumber_X, inputNumber_Y, radius, sum_Xsquared_and_Ysquared, squaredRadius);


	// Checks if the dot lands in the graph 
	if (inputNumber_X > 4 || inputNumber_X < -4) {
		cout << "Outside!";
	}

	// Checks if the dot is on the circle
	if (abs(sum_Xsquared_and_Ysquared - squaredRadius) < eps) {
		cout << "On the edge!";
	}



}

void CheckCircleCoordinates(float x, float y, float radius, float& sum_Xsquared_and_Ysquared, float& squaredRadius) {
	sum_Xsquared_and_Ysquared = (x * x) + (y * y);
	squaredRadius = radius * radius;
}


