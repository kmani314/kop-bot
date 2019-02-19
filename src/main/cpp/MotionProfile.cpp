#include <iostream>

#include <MotionProfile.h>

motionProfiler::motionProfiler(double _accel, double _maxSpeed, double _finalPos) {
    accel = _accel;
    maxSpeed = _maxSpeed;
    finalPos = _finalPos;
}

double motionProfiler::getValue(frc::Timer* timer) {

}