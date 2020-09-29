#include "simpson.h"

float simpsonf(float first, float last, int npoints, float (*f)(float)) {
	float h = (last - first) / npoints;
	float integral = 0.f;

	for (auto i = 0; i < npoints - 1; i += 2)
		integral += f(first + h * i) + 4.f * f(first + h * (i + 1)) + f(first + h * (i + 2));

	return h * integral / 3.f;
}

double simpsond(double first, double last, int npoints, double (*f)(double)) {
	double h = (last - first) / npoints;
	double integral = 0.f;

	for (auto i = 0; i < npoints - 1; i += 2)
		integral += f(first + h * i) + 4. * f(first + h * (i + 1)) + f(first + h * (i + 2));

	return h * integral / 3.;
}
