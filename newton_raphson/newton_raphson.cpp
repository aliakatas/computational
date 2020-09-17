#include "newton_raphson.h"
#include <cmath>

float newtonRaphsonf(float start, float (*f)(float), float (*df)(float), float tol, int maxIter) {
	int iter = 0;
	float last = start;
	while (iter < maxIter) {
		start = last - f(last) / df(last);
		if (fabsf(start - last) < tol)
			return start;
		last = start;
		++iter;
	}
	return start;
}

double newtonRaphsond(double start, double (*f)(double), double (*df)(double), double tol, int maxIter) {
	int iter = 0;
	double last = start;
	while (iter < maxIter) {
		start = last - f(last) / df(last);
		if (fabs(start - last) < tol)
			return start;
		last = start;
		++iter;
	}
	return start;
}
