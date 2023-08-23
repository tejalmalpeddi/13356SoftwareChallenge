#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START IQ MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END IQ MACROS


// Robot configuration code.
motor LeftDriveSmart = motor(PORT1, 1, false);
motor RightDriveSmart = motor(PORT6, 1, true);
gyro DrivetrainGyro = gyro(PORT4, true);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainGyro, 200);

motor ClaspMotor = motor(PORT12, false);
sonar Distance9 = sonar(PORT9);
motor ArmMotor = motor(PORT10, false);
colorsensor Color3 = colorsensor(PORT3);

void calibrateDrivetrain() {
  wait(200, msec);
  Brain.Screen.print("Calibrating");
  Brain.Screen.newLine();
  Brain.Screen.print("Gyro");
  DrivetrainGyro.calibrate();
  while (DrivetrainGyro.isCalibrating()) {
    wait(25, msec);
  }

  // Clears the screen and returns the cursor to row 1, column 1.
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
}
#pragma endregion VEXcode Generated Robot Configuration
// Include the IQ Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

// User defined function
void myblockfunction_safezone2();
// User defined function
void myblockfunction_grab_an_aid_pack();
// User defined function
void myblockfunction_safezone1();
// User defined function
void myblockfunction_safezone3();

int Brain_precision = 0, Console_precision = 0;

float myVariable, GreenPicked, Leftturns, check, position;

// User defined function
void myblockfunction_safezone2() {
  Drivetrain.driveFor(reverse, 30.0, inches);
  Drivetrain.turnFor(right, 180.0, degrees);
  ClaspMotor.spin(forward);
  wait(1.0, seconds);
  ArmMotor.spinFor(reverse, 1000.0, degrees);
  ClaspMotor.spin(reverse);
  Drivetrain.turnFor(right, 90.0, degrees);
  Drivetrain.driveFor(forward, 18.0, inches);
}

// User defined function
void myblockfunction_grab_an_aid_pack() {
  Drivetrain.driveFor(reverse, 2.0, inches);
  ClaspMotor.spin(reverse);
  ArmMotor.spinFor(reverse, 1100.0, degrees);
  Drivetrain.driveFor(forward, 4.5, inches);
  ClaspMotor.spin(forward);
  wait(1.0, seconds);
  ArmMotor.spinFor(forward, 1000.0, degrees);
  ClaspMotor.spin(reverse);
}

// User defined function
void myblockfunction_safezone1() {
  Drivetrain.driveFor(reverse, 30.0, inches);
  Drivetrain.turnFor(left, 90.0, degrees);
  ClaspMotor.spin(forward);
  wait(1.0, seconds);
  ArmMotor.spinFor(reverse, 1000.0, degrees);
  ClaspMotor.spin(reverse);
  Drivetrain.driveFor(forward, 36.0, inches);
}

// User defined function
void myblockfunction_safezone3() {
  Drivetrain.driveFor(reverse, 30.0, inches);
  Drivetrain.turnFor(right, 90.0, degrees);
  ClaspMotor.spin(forward);
  wait(1.0, seconds);
  ArmMotor.spinFor(reverse, 1000.0, degrees);
  ClaspMotor.spin(reverse);
}

// "when started" hat block
int whenStarted1() {
  GreenPicked = 0.0;
  Drivetrain.setDriveVelocity(50.0, percent);
  Drivetrain.setTurnVelocity(50.0, percent);
  Color3.setLight(100, percent);
  return 0;
}

const char* convertColorTypeToString(colorType col) {
  switch (col) {
    case colorType::none:           return "none";
    case colorType::red:            return "red";
    case colorType::green:          return "green";
    case colorType::blue:           return "blue";
    case colorType::white:          return "white";
    case colorType::yellow:         return "yellow";
    case colorType::orange:         return "orange";
    case colorType::purple:         return "purple";
    case colorType::cyan:           return "cyan";
    case colorType::red_violet:     return "red_violet";
    case colorType::violet:         return "violet";
    case colorType::blue_violet:    return "blue_violet";
    case colorType::blue_green:     return "blue_green";
    case colorType::yellow_green:   return "yellow_green";
    case colorType::yellow_orange:  return "yellow_orange";
    case colorType::red_orange:     return "red_orange";
    case colorType::black:          return "black";
    case colorType::transparent:    return "transparent";
    default:                        return "";
  }
}

// Used to find the format string for printing numbers with the
// desired number of decimal places
const char* printToBrain_numberFormat() {
  // look at the current precision setting to find the format string
  switch(Brain_precision){
    case 0:  return "%.0f"; // 0 decimal places (1)
    case 1:  return "%.1f"; // 1 decimal place  (0.1)
    case 2:  return "%.2f"; // 2 decimal places (0.01)
    case 3:  return "%.3f"; // 3 decimal places (0.001)
    default: return "%f"; // use the print system default for everthing else
  }
}

// "when started" hat block
int whenStarted2() {
  while (true) {
    Brain.Screen.print("%s", convertColorTypeToString(Color3.colorname()));
    Brain.Screen.newLine();
    Brain.Screen.print(printToBrain_numberFormat(), static_cast<float>(GreenPicked));
    wait(0.1, seconds);
    Brain.Screen.setCursor(1, 1);
  wait(20, msec);
  }
  return 0;
}

// "when started" hat block
int whenStarted3() {
  position = 0.0;
  Drivetrain.turnFor(right, 90.0, degrees);
  Drivetrain.driveFor(forward, 18.0, inches);
  Drivetrain.turnFor(left, 86.0, degrees);
  Drivetrain.drive(forward);
  waitUntil((Distance9.distance(inches) < 4.0));
  Drivetrain.stop();
  repeat(2) {
    if ((Color3.detects(red_orange) || Color3.detects(red)) || (Color3.detects(red_violet) || Color3.detects(orange))) {
      Drivetrain.driveFor(reverse, 3.0, inches);
      Drivetrain.turnFor(left, 90.0, degrees);
      Drivetrain.driveFor(forward, 15.0, inches);
      Drivetrain.turnFor(right, 90.0, degrees);
      position = position + 1.0;
    }
    else {
      Drivetrain.driveFor(reverse, 2.0, inches);
      myblockfunction_grab_an_aid_pack();
      if (position == 0.0) {
        myblockfunction_safezone1();
      } else if (position == 1.0) {
        myblockfunction_safezone2();
      } else if (position == 2.0) {
        myblockfunction_safezone3();
      } else {
      }
    }
    wait(20, msec);
  }
  Drivetrain.turnFor(right, 90.0, degrees);
  Drivetrain.driveFor(forward, 8.0, inches);
  Drivetrain.turnFor(left, 90.0, degrees);
  Drivetrain.drive(forward);
  waitUntil((Distance9.distance(inches) < 4.0));
  Drivetrain.stop();
  check = 0.0;
  repeat(3) {
    if ((Color3.detects(red_orange) || Color3.detects(red)) || (Color3.detects(red_violet) || Color3.detects(orange))) {
      Drivetrain.driveFor(reverse, 3.0, inches);
      Drivetrain.turnFor(left, 90.0, degrees);
      Drivetrain.driveFor(forward, 15.0, inches);
      Drivetrain.turnFor(right, 90.0, degrees);
      position = position + 1.0;
    }
    else {
      Drivetrain.driveFor(reverse, 2.0, inches);
      myblockfunction_grab_an_aid_pack();
      if (position == 0.0) {
        myblockfunction_safezone1();
      } else if (position == 1.0) {
        myblockfunction_safezone2();
      } else if (position == 2.0) {
        myblockfunction_safezone3();
      } else {
      }
    }
    wait(20, msec);
  }
  Drivetrain.turnFor(right, 90.0, degrees);
  Drivetrain.driveFor(forward, 8.0, inches);
  Drivetrain.turnFor(left, 90.0, degrees);
  Drivetrain.drive(forward);
  return 0;
}


int main() {
  // Calibrate the Drivetrain Gyro
  calibrateDrivetrain();

  vex::task ws1(whenStarted2);
  vex::task ws2(whenStarted3);
  whenStarted1();
}
