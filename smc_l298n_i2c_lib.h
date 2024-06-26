#ifndef SMC_L298N_I2C_LIB_H
#define SMC_L298N_I2C_LIB_H

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif


#include <Wire.h>


class SMC {
public:
  SMC (int);

  void sendTargetVel(float, float);
  void sendPwm(int, int);
  void getMotorsPos(float&, float&);
  void getMotorsVel(float&, float&);
  void getMotorAData(float&, float&);
  void getMotorBData(float&, float&);

  

private:
  int slaveAddr;
  String dataMsg = "", dataMsgBuffer = "", dataBuffer[2];
  float valA, valB;

  void get(String);
  void send(String, float, float);
  void masterSendData(String);
  String masterReceiveData(byte);
};

#endif
