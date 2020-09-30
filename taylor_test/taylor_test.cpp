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
	while (t <= 3.) {
		t += dt;
		yf += dt * y1f(t, yf);
		yd += dt * y1d(t, yd);

		float exactf = pow(M_E, -t);
		double exactd = pow(M_E, -t);

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