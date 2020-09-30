#include "runge_kutta_4thOrder.h"

void runge_kutta_4thOrderf(float start, int i, float dh, float& t, float& y, float (*f)(float, float)) {
	float k1, k2, k3, k4;
	t = start + i * dh;
	k1 = f(t, y);
	k2 = f(t + .5f * dh, y + .5f * dh * k1);
	k3 = f(t + .5f * dh, y + .5f * dh * k2);
	k4 = f(t + dh, y + dh * k3);
	y += (dh / 6.f) * (k1 + 2.f * k2 + 2.f * k3 + k4);
}

void runge_kutta_4thOrderd(double start, int i, double dh, double& t, double& y, double (*f)(double, double)) {
	double k1, k2, k3, k4;
	t = start + i * dh;
	k1 = f(t, y);
	k2 = f(t + .5 * dh, y + .5 * dh * k1);
	k3 = f(t + .5 * dh, y + .5 * dh * k2);
	k4 = f(t + dh, y + dh * k3);
	y += (dh / 6.) * (k1 + 2. * k2 + 2. * k3 + k4);
}
