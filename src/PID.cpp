#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  // Proportional
  this->Kp = Kp;
  p_error = 0.0;
  // Integral
  this->Ki = Ki;
  i_error = 0.0;
  // Differential
  this->Kd = Kd;
  d_error = 0.0;
}

void PID::UpdateError(double cte) {
  // Update differential error
  d_error = cte - p_error;
  // Update proportional error
  p_error = cte;
  // Update integral error
  i_error += cte;
}

double PID::TotalError() {
  return (-Kp * p_error) - (Kd * d_error) - (Ki * i_error);
}
