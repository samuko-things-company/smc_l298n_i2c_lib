#ifndef SMC_L298N_I2C_LIB_H
#define SMC_L298N_I2C_LIB_H

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <Wire.h>

class SMC
{
public:
  SMC(int);

  bool sendTargetVel(float, float);

  bool sendPwm(int, int);

  void getMotorsPos(float &, float &);

  void getMotorsVel(float &, float &);

  void getMotorAData(float &, float &);

  void getMotorBData(float &, float &);

private:
  int slaveAddr;
  String dataMsg = "", dataMsgBuffer = "", dataBuffer[2];
  float valA, valB;

  void get(String);

  bool send(String, float, float);

  void masterSendData(String);

  String masterReceiveData();

  String masterReceiveCharData();
};

#endif