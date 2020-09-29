#pragma once

float gauss_chebyshevf(float first, float last, int npoints, float (*f)(float));

double gauss_chebyshevd(double first, double last, int npoints, double (*f)(double));
