#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this -> Kp = Kp;
	this -> Ki = Ki;
	this -> Kd = Kd;

	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
	
	cte_pre = 0.0;
	step = 0;
}

void PID::UpdateError(double cte) {
	p_error = cte;
	i_error += cte;
	d_error = cte - cte_pre;
	cte_pre = cte;
	step += 1;
	cout << "step = " << step << endl;
	cout << "i_error = " << i_error << endl << "\n";
	if (step > 100){
		i_error = 0;
		step = 0;
	}
}

double PID::TotalError() {
	double steer = -Kp * p_error - Ki * i_error - Kd * d_error;

	return steer;
}

