#include <PID.h>
#include <Arduino.h>


PID:: PID(double integral, double previousError) 
: _integral(integral), _previousError(previousError){
    _lastTime = millis();
}

void PID :: SetPid(double kp, double ki, double kd){
    _kp = kp;
    _ki = ki;
    _kd = kd;
}

double PID :: pid(double error){
    unsigned long now = millis();
    double dt = (now - _lastTime) / 1000.00;
    _lastTime = now;

    _proportional = error;
    _integral += error * dt;
    _derivative  = (error - _previousError) / dt; 
    _previousError = error;

    double correction = (_kp * _proportional) + (_ki * _integral) + (_kd * _derivative);

    
    return correction;
}