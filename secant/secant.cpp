#include "secant.h"
#include <cmath>

float secantf(float p0, float p1, float (*f)(float), float tol, int maxIter) {
	int iter = 0;
	float temp;
	while (iter < maxIter) {
		temp = p1;
		p1 = p1 - f(p1) * (p1 - p0) / (f(p1) - f(p0));
		if (fabsf(p0 - p1) < tol)
			return p1;
		p0 = temp;
		++iter;
	}
	return p0;
}

double secantd(double p0, double p1, double (*f)(double), float tol, int maxIter) {
	int iter = 0;
	double temp;
	while (iter < maxIter) {
		temp = p1;
		p1 = p1 - f(p1) * (p1 - p0) / (f(p1) - f(p0));
		if (fabs(p0 - p1) < tol)
			return p1;
		p0 = temp;
		++iter;
	}
	return p0;
}

