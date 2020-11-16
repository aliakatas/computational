#include "jacobi.h"
#include <cmath>
#include <cstring>

bool hasConverged_f(const float* xnew, const float* xold, size_t N, float tol) {
	for (auto idx = 0; idx < N; ++idx) {
		if (fabsf(xnew[idx] - xold[idx]) > tol)
			return false;
	}
	return true;
}

bool hasConverged_d(const double* xnew, const double* xold, size_t N, double tol) {
	for (auto idx = 0; idx < N; ++idx) {
		if (fabs(xnew[idx] - xold[idx]) > tol)
			return false;
	}
	return true;
}

bool isDiagonallyDominant_f(const float* A, size_t N) {
	// weak check
	float diag = 0.f;
	float val = 0.f;
	for (auto row = 0; row < N; ++row) {
		diag = fabsf(A[row * N + row]);

		val = 0.f;
		for (auto col = 0; col < N; ++col) {
			if (col != row)
				val += fabsf(A[row * N + col]);
		}
		if (diag <= val)
			return false;
	}
	return true;
}

bool isDiagonallyDominant_d(const double* A, size_t N) {
	//weak check
	double diag = 0.;
	double val = 0.;
	for (auto row = 0; row < N; ++row) {
		diag = fabs(A[row * N + row]);

		val = 0.f;
		for (auto col = 0; col < N; ++col) {
			if (col != row)
				val += fabs(A[row * N + col]);
		}
		if (diag <= val)
			return false;
	}
	return true;
}

int jacobi_f(const float* A, float* x, const float* b, size_t N, float tol, size_t max_iter) {
	float* xold = (float*)malloc(N * sizeof(float));
	if (!xold)
		return -1;

	memcpy(xold, x, N * sizeof(float));
	
	float s = 0.f;
	size_t iter = 0;
	while (iter < max_iter) {
		for (auto row = 0; row < N; ++row) {
			s = 0.f;
			for (auto col = 0; col < N; ++col) {
				if (row != col)
					s += A[row * N + col] * xold[col];
			}
			x[row] = (1.f / A[row * N + row]) * (b[row] - s);
		}

		if (hasConverged_f(x, xold, N, tol))
			break;

		memcpy(xold, x, N * sizeof(float));
		++iter;
	}

	free(xold);
	if (iter >= max_iter)
		return 1;
	return 0;
}

int jacobi_d(const double* A, double* x, const double* b, size_t N, double tol, size_t max_iter) {
	double* xold = (double*)malloc(N * sizeof(double));
	if (!xold)
		return -1;

	memcpy(xold, x, N * sizeof(double));

	double s = 0.;
	size_t iter = 0;
	while (iter < max_iter) {
		for (auto row = 0; row < N; ++row) {
			s = 0.f;
			for (auto col = 0; col < N; ++col) {
				if (row != col)
					s += A[row * N + col] * xold[col];
			}
			x[row] = (1.f / A[row * N + row]) * (b[row] - s);
		}

		if (hasConverged_d(x, xold, N, tol))
			break;

		memcpy(xold, x, N * sizeof(double));
		++iter;
	}

	free(xold);
	if (iter >= max_iter)
		return 1;
	return 0;
}