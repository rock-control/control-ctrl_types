#ifndef __BASE_TOOLS_HPP__
#define __BASE_TOOLS_HPP__

namespace base { namespace  samples {

class CartesianState;
class RigidBodyState;

void toRigidBodyState(const CartesianState& in, RigidBodyState& out);
void fromRigidBodyState(const RigidBodyState& in, CartesianState& out);

}
}
#endif
