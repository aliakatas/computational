#include "jacobi.h"
#include <cmath>

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

void jacobi_f(const float* A, const float* x, const float* b, size_t N, float tol, size_t max_iter) {

}

void jacobi_d(const double* A, const double* x, const double* b, size_t N, double tol, size_t max_iter) {

}