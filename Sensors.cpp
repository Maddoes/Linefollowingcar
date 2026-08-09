#include <Sensors.h>
#include <Arduino.h>

int Sensor:: correlation[5] = {1, 1, 0, -1, -1};
int Sensor:: sensordata[5];
int Sensor:: max[5] = {0,0,0,0,0};
int Sensor:: min[5] = {0,0,0,0,0};
int Sensor:: pin[5] = {A0, A1, A2, A3, A4};

Sensor :: Sensor(int analogPin) 
: analogPin(analogPin){
    pinMode(analogPin, INPUT);
    
}


void Sensor:: Calibrating(){

    Serial.print("Calibrating....");
    unsigned long startTime = millis();
    unsigned long now = millis();
    while ((now - startTime) / 1000 < 15){

        for(int i = 0; i < 5; i ++){
            double current = analogRead(pin[i]);

            if (current > max[i]){
                max[i] = current;
            }
            else if(current < min[i]){
                min[i] = current;
            }
        }
        now = millis();
    }
}