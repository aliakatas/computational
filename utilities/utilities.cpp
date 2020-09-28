#include "utilities.h"
#include <cmath>

float logarithmf(float x, float base) {
	return log10f(x) / log10f(base);

}

double logarithmd(double x, double base) {
	return log10(x) / log10(base);
}

long long int fibonacci(long long int n) {
	if (n <= 0)
		return n;
	if (n == 1)
		return 1;

	long long int fn0 = 0;
	long long int fn1 = 1;
	long long int fn = 0;
	for (auto i = 2; i <= n; ++i) {
		fn = fn0 + fn1;
		fn0 = fn1;
		fn1 = fn;
	}
	return fn;
}

long long int gcd(long long int a, long long int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}