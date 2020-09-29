#define _USE_MATH_DEFINES
#include "gauss_chebyshev.h"
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

float trigon2(float x) {
	return cos(4.f * x / 3.f) * sin(x) - 3.f * x * x + 1.f / x;;
}

double trigon2(double x) {
	return cos(4. * x / 3.) * sin(x) - 3. * x * x + 1. / x;;
}


int main() {

	std::cout << "\n  Testing \"gauss_chebyshev\" -->\n";
	std::cout << " ********************** \n";
	std::cout << "  Int_{-3, 3} 0.5 * x^4 + 6 * x^2 - 3.8 * x + 4.2  (50 segments) \n";
	std::cout << " F ::  " << gauss_chebyshevf(-3.f, 3.f, 50, poly) << "  (exact: 181.8)\n";
	std::cout << " D ::  " << gauss_chebyshevd(-3., 3., 50, poly) << "  (exact: 181.8)\n";
	std::cout << " ********************** \n";
	std::cout << "  Int_{-pi, pi} cos(x/2) - 3 * x  (50 segments) \n";
	std::cout << " F ::  " << gauss_chebyshevf(-M_PI, M_PI, 50, trigon) << "  (exact: 4.0)\n";
	std::cout << " D ::  " << gauss_chebyshevd(-M_PI, M_PI, 50, trigon) << "  (exact: 4.0)\n";
	std::cout << " ********************** \n";
	std::cout << "  Int_{3pi/4, pi} cos(4 * x / 3) * sin(x) - 3 * x^2 + 1 / x  (50 segments) \n";
	std::cout << " F ::  " << gauss_chebyshevf(3.f * M_PI / 4.f, M_PI, 50, trigon2) << "  (exact: -17.90410178...)\n";
	std::cout << " D ::  " << gauss_chebyshevd(3. * M_PI / 4., M_PI, 50, trigon2) << "  (exact: -17.90410178...)\n";
	std::cout << " ********************** \n";

	std::cout << "  <-- Done. \n";
}