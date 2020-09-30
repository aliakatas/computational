#pragma once

float logarithmf(float x, float base = 10.f);

double logarithmd(double x, double base = 10.);

long long int fibonacci(long long int n);

long long int gcd(long long int a, long long int b);

bool isPrime(long long int n, const float selection = 0.5f);

bool differenceBelowThreshold(float *ref, float *value, int n, float threshold = .0001f);

bool differenceBelowThreshold(double *ref, double *value, int n, double threshold = .0001);

