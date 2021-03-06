#pragma once

float bisectionf(float start, float finish, float (*f)(float), float tol = 1.e-5, int maxIter = 100);

double bisectiond(double start, double finish, double (*f)(double), double tol = 1.e-8, int maxIter = 100);

float bisectionf_reg_falsi(float start, float finish, float (*f)(float), float tol = 1.e-5, int maxIter = 100);

double bisectiond_reg_falsi(double start, double finish, double (*f)(double), double tol = 1.e-8, int maxIter = 100);
