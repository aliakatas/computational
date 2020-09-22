#include "fixed_point.h"
#include <cmath>

float fixed_pointf(float p0, float (*f)(float), float tol, int maxIter) {
	int iter = 0;
	float last = p0;
	while (iter < maxIter) {
		p0 = f(p0);
		if (fabsf(p0 - last) < tol)
			return p0;
		last = p0;
		++iter;
	}
	return p0;
}

double fixed_pointd(double p0, double (*f)(double), float tol, int maxIter) {
	int iter = 0;
	double last = p0;
	while (iter < maxIter) {
		p0 = f(p0);
		if (fabs(p0 - last) < tol)
			return p0;
		last = p0;
		++iter;
	}
	return p0;
}