#define _USE_MATH_DEFINES
#include "newton_raphson.h"
#include <iostream>
#include <cmath>

float quadf(float x) {
	return 2.0f * x * x - 5.0f * x + 1.0f;
}

double quadd(double x) {
	return 2.0 * x * x - 5.0 * x + 1.0;
}

float dquadf(float x) {
	return 2.0f * x - 5.0f;
}

double dquadd(double x) {
	return 2.0 * x - 5.0;
}

float myFuncf(float x) {
	return tanf(x) - x;
}

double myFuncd(double x) {
	return tan(x) - x;
}

float dmyFuncf(float x) {
	return 1.f / (cosf(x) * cosf(x)) - 1.f;
}

double dmyFuncd(double x) {
	return 1. / (cos(x) * cos(x)) - 1.;
}

float expFuncf(float x) {
	return expf(x) - 8.f;
}

double expFuncd(double x) {
	return exp(x) - 8.;
}

float dexpFuncf(float x) {
	return expf(x);
}

double dexpFuncd(double x) {
	return exp(x);
}

int main() {
	float solf = 0.f;
	double sol = 0.;

	std::cout << "\n  Testing \"newton_raphson\" -->\n";
	std::cout << "  Solving 2*x^2 - 5*x + 1 == 0 \n";
	solf = newtonRaphsonf(0.5f, quadf, dquadf);
	std::cout << "   Float 1 :: " << solf << ", f(sol) = " << quadf(solf) << "\n";
	solf = newtonRaphsonf(2.5f, quadf, dquadf);
	std::cout << "   Float 2 :: " << solf << ", f(sol) = " << quadf(solf) << "\n";
	sol = newtonRaphsond(0.5, quadd, dquadd);
	std::cout << "  Double 1 :: " << sol << ", f(sol) = " << quadd(sol) << "\n";
	sol = newtonRaphsond(2.5, quadd, dquadd);
	std::cout << "  Double 2 :: " << sol << ", f(sol) = " << quadd(sol) << "\n";
	std::cout << " ********************** \n";

	std::cout << "  Solving tan(x) - x == 0 for x in (pi/2, 3*pi/2) and (3*pi/2, 5*pi/2) \n";
	solf = newtonRaphsonf(M_PI, myFuncf, dmyFuncf);
	std::cout << "   Float 1 :: " << solf << ", f(sol) = " << myFuncf(solf) << "\n";
	solf = newtonRaphsonf(4.f * M_PI, myFuncf, dmyFuncf);
	std::cout << "   Float 2 :: " << solf << ", f(sol) = " << myFuncf(solf) << "\n";
	sol = newtonRaphsond(M_PI, myFuncd, dmyFuncd);
	std::cout << "  Double 1 :: " << sol << ", f(sol) = " << myFuncd(sol) << "\n";
	sol = newtonRaphsond(4. * M_PI, myFuncd, dmyFuncd);
	std::cout << "  Double 2 :: " << sol << ", f(sol) = " << myFuncd(sol) << "\n";
	std::cout << " ********************** \n";

	std::cout << "  Solving exp(x) - 8 == 0 \n";
	solf = newtonRaphsonf(1.5f, expFuncf, dexpFuncf);
	std::cout << "   Float 1 :: " << solf << ", f(sol) = " << expFuncf(solf) << "\n";
	sol = newtonRaphsond(1.5, expFuncd, dexpFuncd);
	std::cout << "  Double 1 :: " << sol << ", f(sol) = " << expFuncd(sol) << "\n";
	std::cout << " ********************** \n";

	std::cout << "  <-- Done. \n";
}