/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

#include <frc/RobotDrive.h>

#include <frc/DriverStation.h>




void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);

  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  //drive = new frc::RobotDrive(leftFrontMotor, rightFrontMotor);
  
  timer = new frc::Timer();

  ctre::phoenix::motorcontrol::FeedbackDevice quadEncoder = QuadEncoder;

  rightBackMotor->ConfigSelectedFeedbackSensor(quadEncoder, 0, 0);
  leftBackMotor->ConfigSelectedFeedbackSensor(quadEncoder, 0, 0);
   
  rightBackMotor->SetSensorPhase(true);
  leftBackMotor->SetSensorPhase(true);
  
  rightBackMotor->SetSelectedSensorPosition(0, 0, 0);
  leftBackMotor->SetSelectedSensorPosition(0, 0, 0);

  leftFrontMotor->Follow(*leftBackMotor);
  rightFrontMotor->Follow(*rightBackMotor);

  rightFrontMotor->SetInverted(true);
  rightBackMotor->SetInverted(true);
  
  
 
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  std::cout << "Auto selected: " << m_autoSelected << std::endl;
  timer->Reset();
  timer->Start();

  
}

void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {
//    frc::DriverStation::ReportError("Started Moving.");
    
//    rightBackMotor->SetSelectedSensorPosition(0, 0, 0);
//    leftBackMotor->SetSelectedSensorPosition(0, 0, 0);

//    leftBackMotor->Set(ctre::phoenix::motorcontrol::ControlMode::Position, fiveFeetTicks);
//    rightBackMotor->Set(ctre::phoenix::motorcontrol::ControlMode::Position, fiveFeetTicks);
}

void Robot::TeleopPeriodic() {
//    frc::DriverStation::ReportError("Left: " + std::to_string(leftBackMotor->GetSelectedSensorPosition()));
//    frc::DriverStation::ReportError("Right: " + std::to_string(rightBackMotor->GetSelectedSensorPosition()));
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
