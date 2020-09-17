#pragma once

float newtonRaphsonf(float start, float (*f)(float), float (*df)(float), float tol = 1.e-5, int maxIter = 100);

double newtonRaphsond(double start, double (*f)(double), double (*df)(double), double tol = 1.e-8, int maxIter = 100);