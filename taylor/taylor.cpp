#include "taylor.h"

void taylorf(float start, int i, float dh, float& t, float& y, float (*f)(float, float)) {
	t = start + i * dh;
	y += dh * f(t, y);
}

void taylord(double start, int i, double dh, double& t, double& y, double (*f)(double, double)) {
	t = start + i * dh;
	y += dh * f(t, y);
}

