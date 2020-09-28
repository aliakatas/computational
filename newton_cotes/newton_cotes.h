#pragma once

float newton_cotesf(float first, float last, int npoints, float (*f)(float));

double newton_cotesd(double first, double last, int npoints, double (*f)(double));
