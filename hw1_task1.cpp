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
	float triangleSideА = 3.0;
	float triangleSideB = -3.0;
	float squaredRadius = 0.0;
	float eps = 1e-3;
	float inclinationRadiusO_B = 0.0;
	float inclinationRadiusO_C = 0.0;
	float inclinationUser = 0.0;
	float inclinationLineY = 0.0;


	cout << "Enter two float numbers (up to the 3rd digit after the decimal point) so you can see where it lands on the given graph!" << endl;
	cout << "Enter first number: ";
	cin >> inputNumber_X;
	cout << "Enter second number: ";
	cin >> inputNumber_Y;
	cout << endl;


	//Formula needed to check if the dot is on the circle
	CheckCircleCoordinates(inputNumber_X, inputNumber_Y, radius, sum_Xsquared_and_Ysquared, squaredRadius);

	//Calculates the line from the axis X to the point B
	float lineX_B = sqrt((radius * radius) - (triangleSideА * triangleSideА));                // Тhis is needed so we can find the coordinate of dot B

	//Calculates the inclination of the dot given by the user
	inclinationUser = inputNumber_Y / inputNumber_X;

	//Calculates the inclination of the radius
	inclinationRadiusO_B = lineX_B / triangleSideА;								//This can be used for the radius O-D as well
	inclinationRadiusO_C = lineX_B / triangleSideB;


	// If X is bigger than 4 and smalled than -4 it doesn`t matter what the value of Y will be cause it will be always out of the graph
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
	if (abs(inclinationRadiusO_B - inclinationUser) < eps) {
		cout << "On the edge!";
	}



	//Checks if the dot is in the circle
	if (sum_Xsquared_and_Ysquared < squaredRadius) {
		// Checks if the dot is in the Green area
		if (inclinationUser > inclinationRadiusO_B && inputNumber_Y < 4) {
			cout << "Green!";
		}
		// Checks if the dot is in the Yellow area
		if (inclinationUser < inclinationRadiusO_B && inputNumber_X < 3 && inputNumber_X > 0) {
			cout << "Yellow!";
		}
		// Checks if the dot is in the Purple area
		if (inclinationUser < inclinationRadiusO_B && inputNumber_X > 3) {
			cout << "Purple!";
		}
		// Checks if the dot is in the Red area
		if (inclinationUser < inclinationRadiusO_C && inputNumber_Y < 4) {
			cout << "Red!";
		}
		//Checks if the dot is in the Pink area
		if (inclinationUser > inclinationRadiusO_C && inclinationUser < inclinationRadiusO_B && inputNumber_X > -3) {
			cout << "Pink!";
		}
		//Checks if the dot is in the Empty space of the circle
		if (inclinationUser > inclinationRadiusO_C && inclinationUser < inclinationRadiusO_B && inputNumber_X < -3) {
			cout << "Outside!";
		}
	}




}
//Formula needed to check if the dot is on the circle
void CheckCircleCoordinates(float x, float y, float radius, float& sum_Xsquared_and_Ysquared, float& squaredRadius) {
	sum_Xsquared_and_Ysquared = (x * x) + (y * y);
	squaredRadius = radius * radius;
}




