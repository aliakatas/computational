#include "euler.h"

void eulerf(float start, int i, float dh, float& t, float& y, float (*f)(float, float)) {
	t = start + i * dh;
	y += dh * f(t + .5f * dh, y + .5f * dh * f(t, y));
}

void eulerd(double start, int i, double dh, double& t, double& y, double (*f)(double, double)) {
	t = start + i * dh;
	y += dh * f(t + .5 * dh, y + .5 * dh * f(t, y));
}
