#pragma once

void runge_kutta_4thOrderf(float start, int i, float dh, float& t, float& y, float (*f)(float, float));

void runge_kutta_4thOrderd(double start, int i, double dh, double& t, double& y, double (*f)(double, double));

