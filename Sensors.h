#pragma once
#include <Arduino.h>

class Sensor{
    public:
        static double max[5];
        static double min[5];
        int analogPin;
        static int sensordata[5];
        static int correlation[5];
        static int pin[5];

        Sensor(int analogPin);

        static void Calibrating();

};
