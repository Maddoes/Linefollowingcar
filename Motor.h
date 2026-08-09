#pragma once
#include <Arduino.h>

class Motor{
    public:
        // int pinA, pinB, pwmPin;
        Motor(int pinA, int pinB, int pwmPin);
        void SetSpeed(int speed);
        void Brake();

    private:
        int _pinA, _pinB, _pwmPin;

};

