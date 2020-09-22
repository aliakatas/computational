#pragma once

float fixed_pointf(float p0, float (*f)(float), float tol = 1.e-5, int maxIter = 100);

double fixed_pointd(double p0, double (*f)(double), float tol = 1.e-8, int maxIter = 100);