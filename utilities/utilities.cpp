#include "utilities.h"
#include <cmath>
#include <stdlib.h>
#include <time.h>

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

long long int randomInRange(long long int s, long long int e) {
	return s + (rand() % static_cast<long long>(e - s + 1));
}

bool isPrime(long long int n, const float selection) {
	if (n < 2)
		return false;
	if (n == 2)
		return true;

	for (auto i = 2; i < sqrt(n); ++i) {
		if (!(n % i))
			return false;
	}
	return true;
}

bool differenceBelowThreshold(float* ref, float* value, int n, float threshold) {
	for (auto i = 0; i < n; ++i) {
		if (fabsf(ref[i] - value[i]) >= threshold)
			return false;
	}
	return true;
}

bool differenceBelowThreshold(double* ref, double* value, int n, double threshold) {
	for (auto i = 0; i < n; ++i) {
		if (fabs(ref[i] - value[i]) >= threshold)
			return false;
	}
	return true;
}