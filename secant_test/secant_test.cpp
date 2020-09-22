#define _USE_MATH_DEFINES
#include "secant.h"
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

float expFuncf(float x) {
	return expf(x) - 8.f;
}

double expFuncd(double x) {
	return exp(x) - 8.;
}

int main() {
	float solf = 0.f;
	double sol = 0.;

	std::cout << "\n  Testing \"secant\" -->\n";
	std::cout << "  Solving 2*x^2 - 5*x + 1 == 0 \n";
	solf = secantf(0.f, 1.f, quadf);
	std::cout << "   Float 1 :: " << solf << ", f(sol) = " << quadf(solf) << "\n";
	solf = secantf(2.f, 3.f, quadf);
	std::cout << "   Float 2 :: " << solf << ", f(sol) = " << quadf(solf) << "\n";
	sol = secantd(0., 1., quadd);
	std::cout << "  Double 1 :: " << sol << ", f(sol) = " << quadd(sol) << "\n";
	sol = secantd(2., 3., quadd);
	std::cout << "  Double 2 :: " << sol << ", f(sol) = " << quadd(sol) << "\n";
	std::cout << " ********************** \n";

	std::cout << "  Solving exp(x) - 8 == 0 \n";
	solf = secantf(0.5f, 3.f, expFuncf);
	std::cout << "   Float 1 :: " << solf << ", f(sol) = " << expFuncf(solf) << "\n";
	sol = secantd(0.5, 3., expFuncd);
	std::cout << "  Double 1 :: " << sol << ", f(sol) = " << expFuncd(sol) << "\n";
	std::cout << " ********************** \n";

	std::cout << "  <-- Done. \n";
}