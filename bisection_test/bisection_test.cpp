#define _USE_MATH_DEFINES
#include "bisection.h"
#include <iostream>
#include <cmath>

float quadf(float x) {
	return 2.0f * x * x - 5.0f * x + 1.0f;
}

double quadd(double x) {
	return 2.0 * x * x - 5.0 * x + 1.0;
}

float myFuncf(float x) {
	return tanf(x) - x;
}

double myFuncd(double x) {
	return tan(x) - x;
}

int main() {
	std::cout << "\n  Testing \"bisection\" -->\n";
	std::cout << "  Solving 2*x^2 - 5*x + 1 == 0 \n";
	std::cout << "   Float :: " << quadf(bisectionf(0.f, 1.f, quadf)) << ", " << quadf(bisectionf(2.f, 3.f, quadf)) << "\n";
	std::cout << "  Double :: " << quadd(bisectiond(0., 1., quadd)) << ", " << quadd(bisectiond(2., 3., quadd)) << "\n";
	std::cout << " ********************** \n";
	std::cout << "  Solving tan(x) - x == 0 for x in (pi/2, 3*pi/2) and (3*pi/2, 5*pi/2) \n";
	std::cout << "   Float :: " << myFuncf(bisectionf(10.f * FLT_EPSILON + M_PI / 2.f, 3.f * M_PI / 2.f - 10.f * FLT_EPSILON, myFuncf)) << ", " 
		<< myFuncf(bisectionf(10.f * FLT_EPSILON + 3.f * M_PI / 2.f, 5.f * M_PI / 2.f - 10.f * FLT_EPSILON, myFuncf)) << "\n";
	std::cout << "  Double :: " << myFuncd(bisectiond(10. * DBL_EPSILON + M_PI / 2., 3. * M_PI / 2. - 10. * DBL_EPSILON, myFuncd)) << ", " 
		<< myFuncd(bisectiond(10. * DBL_EPSILON + 3. * M_PI / 2., 5. * M_PI / 2. - 10. * DBL_EPSILON, myFuncd)) << "\n";
	std::cout << " ********************** \n";
	std::cout << "  <-- Done. \n";
}