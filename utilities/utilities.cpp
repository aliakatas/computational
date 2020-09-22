#include "utilities.h"
#include <cmath>

float logarithmf(float x, float base) {
	return log10f(x) / log10f(base);

}

double logarithmd(double x, double base) {
	return log10(x) / log10(base);
}

