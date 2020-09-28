#include "newton_cotes.h"

float newton_cotesf(float first, float last, int npoints, float (*f)(float)) {
	float h = (last - first) / npoints;
	float integral = 0.f;

	for (auto i = 0; i < npoints; ++i)
		integral += .5f * h * (f(first + i * h) + f(first + (i + 1) * h));

	return integral;
}

double newton_cotesd(double first, double last, int npoints, double (*f)(double)) {
	double h = (last - first) / npoints;
	double integral = 0.;

	for (auto i = 0; i < npoints; ++i)
		integral += .5 * h * (f(first + i * h) + f(first + (i + 1) * h));

	return integral;
}

