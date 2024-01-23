# smc_arduino_i2c_comm
This is a child project of the Samuko Motor Control (SMC) project. This is an Arduino library meant to be used in your Arduino robotic project to communicate with the **smc_driver module** in order to send target angular velocities to the motors or receive the motor's angular velocity and angular position, after successful velocity PID setup with the [**smc_app**](https://github.com/samuko-things/EMC2_gui_application).

> you can use it in your Arduino-based robotics project (e.g Arduino UNO, Arduino NANO, Arduino MEGA, Esp32, Stm32, etc.)

A simple way to get started is simply to try out and follow the example code


## How to Use the Library
- Ensure you have the smc_driver module shield fully set up for velocity PID control.

- Download download the library by clicking on the green Code button above

- move the downloaded library file to your Arduino library folder
  > e.g on linux: ... home/Arduino/libraries/
  >
  > e.g on windows: ... Documents/Arduino/libraries/

- restart your ArduinoIDE and navigate to examples and run the example code and see how the motors behave.

- you can copy this example code into your project and modify it to your taste.


## Basic Library functions and usage

- send target angular velocity command
  > sendTargetVel(motorATargetVel, motorBTargetVel)

- read motors angular position
  > getMotorsPos(&angPosA, &angPosB) // copies the motors angular position into angPosA, angPosB

- read motors angular velocity
  > getMotorsVel(&angVelA, &angVelB) // copies the motors ang vel angVelA, angVelB
