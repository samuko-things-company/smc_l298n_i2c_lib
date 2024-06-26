
#include "smc_l298n_i2c_lib.h"


SMC::SMC (int slave_addr){
  slaveAddr = slave_addr;
}


void SMC::sendTargetVel(float valA=0.0, float valB=0.0){
  send("/tag", valA, valB);
}

void SMC::sendPwm(int valA=0, int valB=0){
  send("/pwm", (float)valA, (float)valB);
}

void SMC::getMotorsPos(float &angPosA, float &angPosB){
  get("/pos");

  angPosA = valA;
  angPosB = valB;

  valA = 0.0;
  valB = 0.0;
}

void SMC::getMotorsVel(float &angVelA, float &angVelB){
  get("/vel");
  
  angVelA = valA;
  angVelB = valB;

  valA = 0.0;
  valB = 0.0;
}

void SMC::getMotorAData(float &angPos, float &angVel){
  get("/dataA");
  
  angPos = valA;
  angVel = valB;

  valA = 0.0;
  valB = 0.0;
}

void SMC::getMotorBData(float &angPos, float &angVel){
  get("/dataB");
  
  angPos = valA;
  angVel = valB;

  valA = 0.0;
  valB = 0.0;
}

void SMC::masterSendData(String i2c_msg)
{
  char charArray[i2c_msg.length() + 1];
  i2c_msg.toCharArray(charArray, i2c_msg.length() + 1);

  Wire.beginTransmission(slaveAddr);
  Wire.write(charArray);
  Wire.endTransmission();
}

String SMC::masterReceiveData(byte dataSize)
{
  String i2c_msg = "";
  Wire.requestFrom((int)slaveAddr, (int)dataSize);
  while (Wire.available())
  {
    char c = Wire.read();
    i2c_msg += c;
  }
  int indexPos = i2c_msg.indexOf((char)255);
  if (indexPos != -1)
  {
    return i2c_msg.substring(0, indexPos);
  }
  return i2c_msg;
}

void SMC::get(String address_route)
{
  masterSendData(address_route);
  dataMsg = masterReceiveData(32);

  int indexPos = 0, i = 0;
  do
  {
    indexPos = dataMsg.indexOf(',');
    if (indexPos != -1)
    {
      dataMsgBuffer = dataMsg.substring(0, indexPos);
      dataMsg = dataMsg.substring(indexPos + 1, dataMsg.length());
      dataBuffer[i] = dataMsgBuffer;
      dataMsgBuffer = "";
    }
    else
    {
      if (dataMsg.length() > 0)
        dataBuffer[i] = dataMsg;
    }
    i += 1;
  } while (indexPos >= 0);

  valA = dataBuffer[0].toFloat();
  valB = dataBuffer[1].toFloat();

  dataMsg = "";
  dataMsgBuffer = "";
  dataBuffer[0] = "";
  dataBuffer[1] = "";
}

void SMC::send(String address_route, float valA, float valB)
{
  String msg_buffer = address_route;
  msg_buffer += ",";
  msg_buffer += String(valA, 3);
  msg_buffer += ",";
  msg_buffer += String(valB, 3);

  masterSendData(msg_buffer);
}