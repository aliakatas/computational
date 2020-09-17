#include "detect_machine_precision.h"

float get_machine_precision_float() {
    float e = 1.0f;
    while (e + 1.0f != 1.0f)
        e *= 0.5f;

    return e;
}

double get_machine_precision_double() {
    double e = 1.0;
    while (e + 1.0 != 1.0)
        e *= 0.5;
    
    return e;
}