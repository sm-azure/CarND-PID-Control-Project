#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;

    Kp = 0.0;
    Ki = 0.0;
    Kd = 0.0;
}

PID::~PID() {}

void PID::Init(double p, double i, double d) {
    Kp = p;
    Ki = i;
    Kd = d;

    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
}

void PID::UpdateError(double cte) {
    
}

double PID::TotalError() {
}

