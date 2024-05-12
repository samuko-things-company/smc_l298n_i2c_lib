# smc_i2c_lib
This is a child project of the Samuko Motor Control (SMC) project. This is an Arduino library meant to be used in your Arduino robotic project to communicate with the **`smc_l298n_pid_driver module`** in order to send target angular velocities to the motors or receive the motor's angular velocity and angular position, after successful velocity PID setup with the [**`smc_setup_application`**](https://github.com/samuko-things-company/smc_setup_application).

> you can use it in your Arduino-based robotics project (e.g Arduino UNO, Arduino NANO, Arduino MEGA, Esp32, etc.)

A simple way to get started is simply to try out and follow the example code


## How to Use the Library
- Ensure you have the **`smc_l298n_pid_driver module`** with motors interfaced with it and the encoder and pid parameters are fully setup with the **`smc_setup_application`**.

- Download download the library by clicking on the green Code button above (or clone it)

- move the downloaded library file to your Arduino library folder
  > e.g on linux: ... home/Arduino/libraries/
  >
  > e.g on windows: ... Documents/Arduino/libraries/

- restart your ArduinoIDE and navigate to examples and run the example code and see how the motors behave.

- you can copy this example code into your project and modify it to your taste.


## Basic Library functions and usage

- initialize the smc i2c communication
  > SMC(i2c_address)

- send target angular velocity command
  > .sendTargetVel(motorATargetVel, motorBTargetVel)

- send PWM command
  > .sendPwm(motorA_PWM, motorB_PWM)

- read motors angular position
  > .getMotorsPos(&angPosA, &angPosB) // copies the motors angular position into angPosA, angPosB

- read motors angular velocity
  > .getMotorsVel(&angVelA, &angVelB) // copies the motors ang vel angVelA, angVelB
