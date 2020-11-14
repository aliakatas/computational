#pragma once

void adams_bashforthf(float t0, int i, float dt, float& t, float& y0, float& y1, float& ynew, float (*f)(float, float));

void adams_bashforthd(double t0, int i, double dt, double& t, double& y0, double& y1, double& ynew, double (*f)(double, double));

