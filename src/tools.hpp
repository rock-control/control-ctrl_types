#ifndef __BASE_TOOLS_HPP__
#define __BASE_TOOLS_HPP__

namespace base { namespace  samples {

class RigidBodyStateSE3;
class RigidBodyState;

void toRigidBodyState(const RigidBodyStateSE3& in, RigidBodyState& out);
void fromRigidBodyState(const RigidBodyState& in, RigidBodyStateSE3& out);

}
}
#endif
