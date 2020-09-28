#define _USE_MATH_DEFINES
#include "utilities.h"
#include <iostream>
#include <cmath>

int main() {
	float solf = 0.f;
	double sol = 0.;

	std::cout << "\n  Testing \"utilities\" -->\n";
	std::cout << " ********************** \n";
	std::cout << " F :: log(1, 10) = " << logarithmf(1.f) << "  (exp: 0.0)\n";
	std::cout << " D :: log(1, 10) = " << logarithmd(1.) << "  (exp: 0.0)\n";
	std::cout << " F :: log(e, e) = " << logarithmf(M_E, M_E) << "  (exp: 1.0)\n";
	std::cout << " D :: log(e, e) = " << logarithmd(M_E, M_E) << "  (exp: 1.0)\n";
	std::cout << " F :: log(98, 22) = " << logarithmf(98.f, 22.f) << "  (exp: 1.483307832)\n";
	std::cout << " D :: log(98, 22) = " << logarithmd(98., 22.) << "  (exp: 1.483307832)\n";
	std::cout << " F :: log(5, 11) = " << logarithmf(5.f, 11.f) << "  (exp: 0.6711877)\n";
	std::cout << " D :: log(5, 11) = " << logarithmd(5., 11.) << "  (exp: 0.6711877)\n";
	std::cout << " ********************** \n";
	std::cout << " Fibonacci(0) = " << fibonacci(0) << "  (exp: 0)\n";
	std::cout << " Fibonacci(1) = " << fibonacci(1) << "  (exp: 1)\n";
	std::cout << " Fibonacci(13) = " << fibonacci(13) << "  (exp: 233)\n";
	std::cout << " Fibonacci(-5) = " << fibonacci(-5) << "  (exp: -5)\n";
	std::cout << " Fibonacci(100) = " << fibonacci(71) << "  (exp: 308061521170129)\n";
	std::cout << " ********************** \n";
	std::cout << " GCD(11, 3) = " << gcd(11, 3) << "  (exp: 1)\n";
	std::cout << " GCD(25, 5) = " << gcd(25, 5) << "  (exp: 5)\n";
	std::cout << " GCD(69, 23) = " << gcd(69, 23) << "  (exp: 23)\n";
	std::cout << " GCD(9, 4) = " << gcd(9, 4) << "  (exp: 1)\n";
	std::cout << " GCD(1234, 87) = " << gcd(1234, 87) << "  (exp: 1)\n";
	std::cout << " GCD(7539, 36) = " << gcd(7539, 36) << "  (exp: 3)\n";
	std::cout << " ********************** \n";

	std::cout << "  <-- Done. \n";
}