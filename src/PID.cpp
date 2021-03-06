#include "PID.h"
#include <limits>

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

    dp = 1.0;
    di = 1.0;
    dd = 1.0;

    best_error = std::numeric_limits<double>::max();
    twiddle_iterations = 10;
}

PID::~PID() {}

void PID::Init(double p, double i, double d) {
    Kp = p;
    Ki = i;
    Kd = d;

    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;

    moves = 0;
    total_error = 0.0;
}

void Twiddle(){
    
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;

    total_error += cte*cte;
    moves++;
}

double PID::CumulativeError(){
    return total_error/(double)moves;
}

double PID::TotalError() {
    return (- Kp * p_error - Kd * d_error - Ki * i_error);
}

