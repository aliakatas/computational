#include "bisection.h"
#include <cmath>

float bisectionf(float start, float finish, float (*f)(float), float tol, int maxIter) {
	int iter = 0;
	float mid = 0.0f;
	while (iter < maxIter) {
		mid = (start + finish) / 2.0f;
		if (f(start) * f(mid) < 0.0f)
			finish = mid;
		else if (f(mid) * f(finish) < 0.0f)
			start = mid;
		else
			return mid;
		
		if (fabsf(f(mid)) < tol)
			return mid;
		++iter;
	}
	return mid;
}

double bisectiond(double start, double finish, double (*f)(double), double tol, int maxIter) {
	int iter = 0;
	double mid = 0.0;
	while (iter < maxIter) {
		mid = (start + finish) / 2.0;
		if (f(start) * f(mid) < 0.0)
			finish = mid;
		else if (f(mid) * f(finish) < 0.0)
			start = mid;
		else
			return mid;

		if (fabs(f(mid)) < tol)
			return mid;
		++iter;
	}
	return mid;
}

float bisectionf_reg_falsi(float start, float finish, float (*f)(float), float tol, int maxIter) {
	int iter = 0;
	float mid = 0.0f;
	while (iter < maxIter) {
		mid = (f(finish) * start - f(start) * finish) / (f(finish) - f(start));
		if (f(start) * f(mid) < 0.0f)
			finish = mid;
		else if (f(mid) * f(finish) < 0.0f)
			start = mid;
		else
			return mid;

		if (fabsf(f(mid)) < tol)
			return mid;
		++iter;
	}
	return mid;
}

double bisectiond_reg_falsi(double start, double finish, double (*f)(double), double tol, int maxIter) {
	int iter = 0;
	double mid = 0.0;
	while (iter < maxIter) {
		mid = (f(finish) * start - f(start) * finish) / (f(finish) - f(start));
		if (f(start) * f(mid) < 0.0)
			finish = mid;
		else if (f(mid) * f(finish) < 0.0)
			start = mid;
		else
			return mid;

		if (fabs(f(mid)) < tol)
			return mid;
		++iter;
	}
	return mid;
}