#pragma once
#include <Arduino.h>

class PID{
    
    private:
        const double _kp = 0.5;
        const double _ki = 0.002;
        const double _kd = 0.01;
        
        double _proportional;
        double _integral = 0;
        double _derivative;
        double _previousError = 0;
        unsigned long _lastTime = 0;

    public:
        double error;

        double pid(double error);
};


