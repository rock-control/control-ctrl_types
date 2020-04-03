#ifndef __BASE_RIGID_BODY_STATES_SE3_HPP__
#define __BASE_RIGID_BODY_STATES_SE3_HPP__

#include <base/NamedVector.hpp>
#include "RigidBodyStateSE3.hpp"

namespace base { namespace samples {

    /**
     * A named vector of base::RigidBodyStateSE3 with sampled Time.
     */
    class RigidBodyStatesSE3 : public base::NamedVector< base::RigidBodyStateSE3>
    {
        base::Time time;
        /** Common coordinate frame for all elements of the vector */
        std::string frame_id;
    };
}}

#endif
