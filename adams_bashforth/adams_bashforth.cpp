#include "adams_bashforth.h"

void adams_bashforthf(float t0, int i, float dt, float& t, float& y0, float& y1, float& ynew, float (*f)(float, float)) {
	ynew = y1 + dt * (1.5f * f(t, y1) - .5f * f(t - dt, y0));
	t = t0 + i * dt;
}

void adams_bashforthd(double t0, int i, double dt, double& t, double& y0, double& y1, double& ynew, double (*f)(double, double)) {
	ynew = y1 + dt * (1.5 * f(t, y1) - .5 * f(t - dt, y0));
	t = t0 + i * dt;
}

