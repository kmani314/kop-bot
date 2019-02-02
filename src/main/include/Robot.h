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
  const int leftFrontMotor = 10;
  const int leftBackMotor = 5;
  const int rightFrontMotor = 2;
  const int rightBackMotor = 6;

 private:
  WPI_TalonSRX* leftFront = new WPI_TalonSRX(leftFrontMotor);
  WPI_TalonSRX* rightFront = new WPI_TalonSRX(rightFrontMotor);
  WPI_TalonSRX* leftBack = new WPI_TalonSRX(leftBackMotor);
  WPI_TalonSRX* rightBack = new WPI_TalonSRX(rightBackMotor);
  frc::Joystick* stick = new frc::Joystick(joystickID);
  frc::RobotDrive *drive;
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
