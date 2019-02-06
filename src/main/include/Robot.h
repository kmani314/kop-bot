/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>
#include <frc/RobotDrive.h>
#include <frc/Encoder.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  const int joystickID = 0;
  const int leftFrontID = 10;
  const int leftBackID = 5;
  const int rightFrontID = 2;
  const int rightBackID = 6;
  const double fiveFeetTicks = 13037.9729381;
 private:
  WPI_TalonSRX* leftFrontMotor = new WPI_TalonSRX(leftFrontID);
  WPI_TalonSRX* rightFrontMotor = new WPI_TalonSRX(rightFrontID);
  WPI_TalonSRX* leftBackMotor = new WPI_TalonSRX(leftBackID);
  WPI_TalonSRX* rightBackMotor = new WPI_TalonSRX(rightBackID);
  frc::Joystick* stick = new frc::Joystick(joystickID);
  frc::RobotDrive *drive;
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
