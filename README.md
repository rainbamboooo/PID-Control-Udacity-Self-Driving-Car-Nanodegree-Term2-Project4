PID Controller
==============

Definition
----------

> A proportional–integral–derivative controller (PID controller or three term controller) is a control loop feedback
mechanism (controller) widely used in industrial control systems and a variety of other applications 
requiring continuously modulated control. A PID controller continuously calculates an error as the difference 
between a desired setpoint and a measured process variable and applies a correction based on proportional
, integral, and derivative terms (sometimes denoted P, I, and D respectively) which give their name to the 
controller type. (From Wikipedia)

Parameters
----------

 - Kp has a direct relationship with cross track error(cte)
 - Ki has a relationship with the total sum of cte
 - Kd has a relationship with the derivative of cte

Formula
-------
**steering_value = - Kp \* cte - Ki \* sum(cte) - Kd \* d/dt(cte)**

My PID Controller
-----------------

The parameters I choose are:

 - Kp = 0.2, Ki = 0.001, Kd = 2.0;

Using these parameters, my PID controller performs well on the simulator. The car does not have any very sharp turns or drives into the water.

Problems and Solution
---------------------

Although I set the Ki to a very small value, i_error is accumulating and becomes larger and larger. After the car runs many laps, 
it will turn at a very wired angel.

Therefore, after the i_error accumulates for 100 times, I reset it to 0. In this way, my car can run as far as it can.

Improvement
-----------

I will try to add twiddle to set my parameters.
