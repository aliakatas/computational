#pragma once

float secantf(float p0, float p1, float (*f)(float), float tol = 1.e-5, int maxIter = 100);

double secantd(double p0, double p1, double (*f)(double), float tol = 1.e-8, int maxIter = 100);