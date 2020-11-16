#pragma once

#define TOLERANCE 0.00001
#define MAXITERATIONS 100


bool hasConverged_f(const float* xnew, const float* xold, size_t N, float tol = TOLERANCE);

bool hasConverged_d(const double* xnew, const double* xold, size_t N, double tol = TOLERANCE);

bool isDiagonallyDominant_f(const float* A, size_t N);

bool isDiagonallyDominant_d(const double* A, size_t N);

int jacobi_f(const float* A, float* x, const float* b, size_t N, float tol = TOLERANCE, size_t max_iter = MAXITERATIONS);

int jacobi_d(const double* A, double* x, const double* b, size_t N, double tol = TOLERANCE, size_t max_iter = MAXITERATIONS);



