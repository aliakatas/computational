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

float expFuncf(float x) {
	return expf(x) - 8.f;
}

double expFuncd(double x) {
	return exp(x) - 8.;
}

int main() {
	float solf = 0.f;
	double sol = 0.;

	std::cout << "\n  Testing \"bisection\" -->\n";
	std::cout << "  Solving 2*x^2 - 5*x + 1 == 0 \n";
	solf = bisectionf(0.f, 1.f, quadf);
	std::cout << "   Float 1 :: " << solf << ", f(sol) = " << quadf(solf) << "\n";
	solf = bisectionf(2.f, 3.f, quadf);
	std::cout << "   Float 2 :: " << solf << ", f(sol) = " << quadf(solf) << "\n";
	sol = bisectiond(0., 1., quadd);
	std::cout << "  Double 1 :: " << sol << ", f(sol) = " << quadd(sol) << "\n"; 
	sol = bisectiond(2., 3., quadd);
	std::cout << "  Double 2 :: " << sol << ", f(sol) = " << quadd(sol) << "\n";
	std::cout << " ********************** \n";

	std::cout << "  Solving tan(x) - x == 0 for x in (pi/2, 3*pi/2) and (3*pi/2, 5*pi/2) \n";
	solf = bisectionf(10.f * FLT_EPSILON + M_PI / 2.f, 3.f * M_PI / 2.f - 10.f * FLT_EPSILON, myFuncf);
	std::cout << "   Float 1 :: " << solf << ", f(sol) = " << myFuncf(solf) << "\n";
	solf = bisectionf(10.f * FLT_EPSILON + 3.f * M_PI / 2.f, 5.f * M_PI / 2.f - 10.f * FLT_EPSILON, myFuncf);
	std::cout << "   Float 2 :: " << solf << ", f(sol) = " << myFuncf(solf) << "\n";
	sol = bisectiond(10. * DBL_EPSILON + M_PI / 2., 3. * M_PI / 2. - 10. * DBL_EPSILON, myFuncd);
	std::cout << "  Double 1 :: " << sol << ", f(sol) = " << myFuncd(sol) << "\n";
	sol = bisectiond(10. * DBL_EPSILON + 3. * M_PI / 2., 5. * M_PI / 2. - 10. * DBL_EPSILON, myFuncd);
	std::cout << "  Double 2 :: " << sol << ", f(sol) = " << myFuncd(sol) << "\n";
	std::cout << " ********************** \n";

	std::cout << " ______________________ \n";
	std::cout << "\n  Testing \"bisection_reg_falsi\" -->\n";
	std::cout << "  Solving 2*x^2 - 5*x + 1 == 0 \n";
	solf = bisectionf_reg_falsi(0.f, 1.f, quadf);
	std::cout << "   Float 1 :: " << solf << ", f(sol) = " << quadf(solf) << "\n";
	solf = bisectionf_reg_falsi(2.f, 3.f, quadf);
	std::cout << "   Float 2 :: " << solf << ", f(sol) = " << quadf(solf) << "\n";
	sol = bisectiond_reg_falsi(0., 1., quadd);
	std::cout << "  Double 1 :: " << sol << ", f(sol) = " << quadd(sol) << "\n";
	sol = bisectiond_reg_falsi(2., 3., quadd);
	std::cout << "  Double 2 :: " << sol << ", f(sol) = " << quadd(sol) << "\n";
	std::cout << " ********************** \n";
	
	std::cout << "  Solving exp(x) - 8 == 0 \n";
	solf = bisectionf_reg_falsi(0.5f, 3.f, expFuncf);
	std::cout << "   Float 1 :: " << solf << ", f(sol) = " << expFuncf(solf) << "\n";
	sol = bisectiond_reg_falsi(0.5, 3., expFuncd);
	std::cout << "  Double 1 :: " << sol << ", f(sol) = " << expFuncd(sol) << "\n";
	std::cout << " ********************** \n";
	


	std::cout << "  <-- Done. \n";
}