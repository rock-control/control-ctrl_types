#include "tools.hpp"
#include "CartesianState.hpp"
#include <base/samples/RigidBodyState.hpp>

namespace base { namespace samples {

void toRigidBodyState(const CartesianState& in, RigidBodyState& out){
    out.time = in.time;
    out.setPose(in.pose);
    out.velocity         = in.twist.linear;
    out.angular_velocity = in.twist.angular;
}

void fromRigidBodyState(const RigidBodyState& in, CartesianState& out){
    out.time = in.time;
    out.pose = in.getPose();
    out.twist.linear = in.velocity;
    out.twist.angular = in.angular_velocity;
}

}
}
