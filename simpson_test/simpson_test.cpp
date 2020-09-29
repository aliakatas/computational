#define _USE_MATH_DEFINES
#include "simpson.h"
#include <iostream>
#include <cmath>

float poly(float x) {
	return 0.5f * pow(x, 4) + 6.f * x * x - 3.8f * x + 4.2f;
}

double poly(double x) {
	return 0.5 * pow(x, 4) + 6. * x * x - 3.8 * x + 4.2;
}

float trigon(float x) {
	return cos(x / 2.f) - 3.f * x;
}

double trigon(double x) {
	return cos(x / 2.) - 3. * x;
}

int main() {

	std::cout << "\n  Testing \"simpson\" -->\n";
	std::cout << " ********************** \n";
	std::cout << "  Int_{-3, 3} 0.5 * x^4 + 6 * x^2 - 3.8 * x + 4.2  (50 segments) \n";
	std::cout << " F ::  " << simpsonf(-3.f, 3.f, 50, poly) << "  (exact: 181.8)\n";
	std::cout << " D ::  " << simpsond(-3., 3., 50, poly) << "  (exact: 181.8)\n";
	std::cout << " ********************** \n";
	std::cout << "  Int_{-pi, pi} cos(x/2) - 3 * x  (50 segments) \n";
	std::cout << " F ::  " << simpsonf(-M_PI, M_PI, 50, trigon) << "  (exact: 4.0)\n";
	std::cout << " D ::  " << simpsond(-M_PI, M_PI, 50, trigon) << "  (exact: 4.0)\n";
	std::cout << " ********************** \n";

	std::cout << "  <-- Done. \n";
}