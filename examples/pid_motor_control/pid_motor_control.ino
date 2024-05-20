
/*
 * Basic example code on how to control via I2C your geared DC motor with quadrature 
 * encoder which is already connected to the smc_l298n_pid_driver module and have already
 * succesfully set up their velocity PID control using the smc_l298n_setup_application
 * 
 * The code basically sends a low target velocity (in rad/s), waits for some time and then
 * sends a high target velocity (in rad/s). it also prints out the motors' angular positions
 * (in rad) and angular velocities (in rad/s).
 * 
 * you can copy the code and use it in your project as you will.
 */

// SMC i2c communication library
#include <smc_l298n_i2c_lib.h>


int smcAddress = 1; // set this address to the same address you have during setup via the GUI app
SMC smc(smcAddress);

///////// my sepcial delay function ///////////////
void delayMs(int ms) {
  for (int i = 0; i < ms; i += 1) {
    delayMicroseconds(1000);
  }
}
//////////////////////////////////////////////////


bool isSuccessful;
float angPosA, angPosB; //motorA, motorB (in rad)
float angVelA, angVelB; //motorA, motorB (in rad/sec)

float lowTargetVel = 1.571; // rad/sec
float highTargetVel = 3.142; // rad/sec
bool sendHigh = true;

long prevTime;
long sampleTime = 20; // millisec

long ctrlPrevTime;
long ctrlSampleTime = 10000; // millisec

void setup()
{
  // start i2c communication
  Wire.begin(); 

  // setup serial communication to print result on serial minitor               
  Serial.begin(115200);

  // wait for the driver module to fully setup (5 to 10 sec)
  for(int i=0; i<=10; i+=1){
    delayMs(1000);
    Serial.println(i);
  }

  smc.sendTargetVel(lowTargetVel, lowTargetVel); // targetA, targetB
  sendHigh = true;

  prevTime = millis();
  ctrlPrevTime = millis();
}


 
void loop()
{  
  if ((millis() - ctrlPrevTime) >= ctrlSampleTime) {
    if (sendHigh){
      smc.sendTargetVel(highTargetVel, highTargetVel); // targetA, targetB
      sendHigh = false;
    }
    else {
      smc.sendTargetVel(lowTargetVel, lowTargetVel); // targetA, targetB
      sendHigh = true;
    }
    ctrlPrevTime = millis();
  }

  
  
  if ((millis() - prevTime) >= sampleTime) {
    /* CODE SHOULD GO IN HERE*/

    smc.getMotorsPos(angPosA, angPosB); // gets angPosA, angPosB
    smc.getMotorsVel(angVelA, angVelB); // gets angVelA, angVelB

    Serial.print(angPosA,4);
    Serial.print(", ");
    Serial.println(angVelA,4);

    Serial.print(angPosB,4);
    Serial.print(", ");
    Serial.println(angVelB,4);

    Serial.println();
    
    prevTime = millis();
  }


}
