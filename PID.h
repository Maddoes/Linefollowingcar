#pragma once
#include <Arduino.h>

class PID{
    
    private:
         
        double _kp;
        double _ki;
        double _kd;
        
        double _proportional;
        double _integral;
        double _derivative;
        double _previousError;
        unsigned long _lastTime;

    public:
        double error;
        PID(double integral, double previousError);
        double pid(double error);
        void SetPid(double kp, double ki, double kd);
};


