

#ifndef MOTION_PROFILE_H
#define MOTION_PROFILE_H

#include <frc/Timer.h>
class motionProfiler {
    private:
    double accel;
    double maxSpeed;
    double finalPos;
    
    public:

    motionProfiler(double _accel, double _maxSpeed, double _finalPos);
    double getValue(frc::Timer* timer);
    

};

#endif