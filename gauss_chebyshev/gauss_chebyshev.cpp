#define _USE_MATH_DEFINES
#include "gauss_chebyshev.h"
#include <cmath>

float gauss_chebyshevf(float first, float last, int npoints, float (*f)(float)) {
	float out = 0.f;
	float x_i = 0.f;
	float arg = 0.f;
	float diff = last - first;
	float sum = last + first;

	for (auto i = 0; i <= npoints; ++i) {
		arg = M_PI * (2 * i + 1) / (2 * (npoints + 1));
		x_i = -cos(arg);
		out += sin(arg) * f(0.5f * diff * x_i + 0.5f * sum);
	}
	return 0.5f * diff * (M_PI / (npoints + 1)) * out;
}

double gauss_chebyshevd(double first, double last, int npoints, double (*f)(double)) {
	double out = 0.;
	double x_i = 0.;
	double arg = 0.;
	double diff = last - first;
	double sum = last + first;

	for (auto i = 0; i <= npoints; ++i) {
		arg = M_PI * (2 * i + 1) / (2 * (npoints + 1));
		x_i = -cos(arg);
		out += sin(arg) * f(0.5 * diff * x_i + 0.5 * sum);
	}
	return 0.5 * diff * (M_PI / (npoints + 1)) * out;
}