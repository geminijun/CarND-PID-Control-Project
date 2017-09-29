#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;

    init = 0;
}

void PID::UpdateError(double cte) {
  if (init == 0) {
    p_error = cte;
    init++;
  }
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;

  total_error += cte * cte;
}

double PID::TotalError() {
  return total_error;
}

double PID::CalculateSteering() {
  return -Kp * p_error - Kd * d_error - Ki * i_error;
}
