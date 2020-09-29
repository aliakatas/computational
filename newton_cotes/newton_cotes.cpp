#include "newton_cotes.h"

float newton_cotesf(float first, float last, int npoints, float (*f)(float)) {
	float h = (last - first) / npoints;
	float integral = 0.f;

	for (auto i = 0; i < npoints; ++i)
		integral += f(first + i * h) + f(first + (i + 1) * h);

	return h * integral / 2.f;
}

double newton_cotesd(double first, double last, int npoints, double (*f)(double)) {
	double h = (last - first) / npoints;
	double integral = 0.;

	for (auto i = 0; i < npoints; ++i)
		integral += f(first + i * h) + f(first + (i + 1) * h);

	return h * integral / 2.;
}

float newton_cotes38f(float first, float last, int npoints, float (*f)(float)) {
	float h = (last - first) / npoints;
	float integral = 0.f;

	for (auto i = 0; i < npoints - 2; i += 3)
		integral += f(first + i * h) + 3.f * f(first + (i + 1) * h) + 3.f * f(first + (i + 2) * h) + f(first + (i + 3) * h);

	return 3.f * h * integral / 8.f;
}

double newton_cotes38d(double first, double last, int npoints, double (*f)(double)) {
	double h = (last - first) / npoints;
	double integral = 0.;

	for (auto i = 0; i < npoints - 2; i += 3)
		integral += f(first + i * h) + 3. * f(first + (i + 1) * h) + 3. * f(first + (i + 2) * h) + f(first + (i + 3) * h);

	return 3. * h * integral / 8.;
}

