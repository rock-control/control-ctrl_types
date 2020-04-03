#include "RigidBodyStateSE3.hpp"

namespace base {

void RigidBodyStateSE3::setNaN(){
    pose.position.setConstant(std::numeric_limits<double>::quiet_NaN());
    pose.orientation.coeffs().setConstant(std::numeric_limits<double>::quiet_NaN());
    twist.setNaN();
    acceleration.setNaN();
    wrench.force.setConstant(std::numeric_limits<double>::quiet_NaN());
    wrench.torque.setConstant(std::numeric_limits<double>::quiet_NaN());
}

bool RigidBodyStateSE3::hasValidPose() const{
    return base::isnotnan(pose.position) && base::isnotnan(pose.orientation.coeffs()) &&
           (abs(pose.orientation.squaredNorm()-1.0) < 1e-6);
}

bool RigidBodyStateSE3::hasValidTwist() const{
    return twist.isValid();
}

bool RigidBodyStateSE3::hasValidAcceleration() const{
    return acceleration.isValid();
}

bool RigidBodyStateSE3::hasValidWrench() const{
    return base::isnotnan(wrench.force) && base::isnotnan(wrench.torque);
}

Twist operator-(const Pose& a, const Pose& b){
    Eigen::Affine3d tf_a = a.toTransform();
    Eigen::Affine3d tf_b = b.toTransform();

    Eigen::Matrix3d rot_mat = tf_b.rotation().inverse() * tf_a.rotation();
    Eigen::AngleAxisd angle_axis;
    angle_axis.fromRotationMatrix(rot_mat);

    Twist twist;
    twist.linear = tf_a.translation() - tf_b.translation();
    twist.angular = tf_b.rotation() * (angle_axis.axis() * angle_axis.angle());
    return twist;
}

Acceleration operator-(const Twist&a, const Twist &b){
    Acceleration acc;
    acc.linear = a.linear-b.linear;
    acc.angular = a.angular-b.angular;
    return acc;
}

Acceleration operator+(const Twist&a, const Acceleration &b){
    Acceleration c;
    c.linear = a.linear + b.linear;
    c.angular = a.angular + b.angular;
}
}
