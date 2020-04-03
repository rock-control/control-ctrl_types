#ifndef __BASE_RIGID_BODY_STATE_SE3_HPP__
#define __BASE_RIGID_BODY_STATE_SE3_HPP__

#include <base/Pose.hpp>
#include <base/Wrench.hpp>
#include <base/Time.hpp>
#include "Twist.hpp"
#include "Acceleration.hpp"

namespace base {

struct RigidBodyStateSE3{
    RigidBodyStateSE3(){
        setNaN();
    }
    /** Set all members to NaN*/
    void setNaN();
    /** Check if the pose is valid, e.g. not NaN*/
    bool hasValidPose() const;
    /** Check if the twist is valid, e.g. not NaN*/
    bool hasValidTwist() const;
    /** Check if the acceleration is valid, e.g. not NaN*/
    bool hasValidAcceleration() const;
    /** Check if the wrench is valid, e.g. not NaN*/
    bool hasValidWrench() const;

    /** 3D position and orientation*/
    base::Pose pose;
    /** 3D Linear and angular velocity*/
    Twist twist;
    /** 3D Linear and angular acceleration*/
    Acceleration acceleration;
    /** Force and torque*/
    Wrench wrench;
};

namespace samples {
struct RigidBodyStateSE3 : public base::RigidBodyStateSE3{
    base::Time time;
    /** Coordinate frame in which all quantities are expressed */
    std::string frame_id;
};

}

Twist operator-(const base::Pose& a, const base::Pose& b);
Acceleration operator-(const Twist&a, const Twist &b);
Acceleration operator+(const Twist&a, const Acceleration &b);

}

#endif
