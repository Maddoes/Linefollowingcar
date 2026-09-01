#include <Sensors.h>
#include <Motor.h>
#include <PID.h>
#include <Arduino.h>

double GetError();

Motor rightmotor(10, 11,9);
Motor leftmotor(7, 8, 6);
int lspeed;
int rspeed;
Sensor sensor1(A0);
Sensor sensor2(A1);
Sensor sensor3(A2);
Sensor sensor4(A3);
Sensor sensor5(A4);

PID pid(0,0);
int basespeed = 100;

void setup() {
  Serial.begin(9600);
  Sensor::Calibrating();

  double kp = 75;
  double ki = 0;
  double kd = 0;
  pid.SetPid(kp, ki, kd);

  for (double data : Sensor:: min){
    Serial.print("\n");
    Serial.print(data);
  }
  for (double data : Sensor:: max){
    Serial.print("\n"); 
    Serial.print(data);
  }

}

void loop() {
  
  double currentPosition = GetError();
  Serial.print("\n");
  Serial.print("Error: ");
  Serial.print(currentPosition);

  double correction = pid.pid(currentPosition);
  
  if (correction > 0){
   
      rspeed = constrain(basespeed - int(correction), 0, 200);
      lspeed = constrain(basespeed + int(correction), 0, 200);
    
  }
  else if(correction < 0){
      rspeed = constrain(basespeed - int(correction), 0, 200);
      lspeed = constrain(basespeed + int(correction), 0, 200);
    
  }
  else{
    rspeed = basespeed;
    lspeed = basespeed;
  }

  leftmotor.SetSpeed(lspeed);
  rightmotor.SetSpeed(rspeed);
  Serial.print("\n");
  Serial.print("Rspeed: ");
  Serial.print(rspeed);
  Serial.print("\t");
  Serial.print("lspeed: ");
  Serial.print(lspeed);

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