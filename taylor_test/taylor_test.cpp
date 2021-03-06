#define _USE_MATH_DEFINES
#include "utilities.h"
#include "taylor.h"
#include <iostream>
#include <cmath>

float y1f(float t, float y) {
	return -1.f * y;
}

double y1d(double t, double y) {
	return -1. * y;
}

double exactSolution(double t) {
	return pow(M_E, -t);
}

int main() {

	std::cout << "\n  Testing \"taylor\" -->\n";
	std::cout << " ********************** \n";
	std::cout << " Solving y'(t) = -y(t), with t in [0,3], y(0) = 1 \n";
	std::cout << " Exact solution :: y(t) = e^(-t) \n";
	std::cout << " Step :: dt = 0.1 \n";

	float yf = 1.f;
	double yd = 1.;
	double dt = 0.1;
	double t = 0.;

	bool errorOccurred = false;
	double tolerance = 0.02;
	std::cout << " Tolerance :: tol = " << tolerance << "\n";
	int iter = 0;
	while (t <= 3.) {
		++iter;
		float tf = t;
		taylorf(0.f, iter, dt, tf, yf, y1f);
		taylord(0., iter, dt, t, yd, y1d);

		float exactf = exactSolution(t);
		double exactd = exactSolution(t);

		if (!differenceBelowThreshold(&exactf, &yf, 1, tolerance)) {
			std::cout << " Difference beyond tolerance level detected (float) at t = " << t << "\n";
			errorOccurred = true;
			break;
		}

		if (!differenceBelowThreshold(&exactd, &yd, 1, tolerance)) {
			std::cout << " Difference beyond tolerance level detected (double) at t = " << t << "\n";
			errorOccurred = true;
			break;
		}
	}

	if (!errorOccurred)
		std::cout << " Method works fine (within tolerance " << tolerance << ")...\n";

	std::cout << "  <-- Done. \n";
}