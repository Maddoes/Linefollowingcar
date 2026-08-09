#include <Sensors.h>
#include <Motor.h>
#include <PID.h>

double GetError();

void setup() {
  Sensor::Calibrating();

}

void loop() {




  
}



double GetError(){
  double position = 0;
  double sum = 0;

  for(int i = 0; i < 5; i ++){
      Sensor:: sensordata[i] = map(analogRead(Sensor:: pin[i]), Sensor::min[i], Sensor::max[i], 0, 1000);   
      position += Sensor:: sensordata[i] * Sensor:: correlation[i];
  }
  for(double data : Sensor:: sensordata){
    sum += data;
  }
  position /= sum;
  return position;
}