#pragma once

void eulerf(float start, int i, float dh, float& t, float& y, float (*f)(float, float));

void eulerd(double start, int i, double dh, double& t, double& y, double (*f)(double, double));

