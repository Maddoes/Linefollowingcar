#include <Motor.h>
#include <Arduino.h>

Motor:: Motor(int pinA, int pinB, int pwmPin) 
: _pinA(pinA), _pinB(pinB), _pwmPin(pwmPin){
    pinMode(_pinA, OUTPUT);
    pinMode(_pinB, OUTPUT);
    pinMode(_pwmPin, OUTPUT);

}

void Motor :: SetSpeed(int speed){
    if (speed >= 0){
        digitalWrite(_pinA, HIGH);
        digitalWrite(_pinB, LOW);
    }
    else{
        digitalWrite(_pinB, HIGH);
        digitalWrite(_pinA, LOW);
        speed = -speed;
    }
    analogWrite(_pwmPin, constrain(speed, 0, 255));
}

void Motor:: Brake(){
    digitalWrite(_pinA, LOW);
    digitalWrite(_pinB, LOW);
    
}

