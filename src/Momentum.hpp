#ifndef __BASE_MOMENTUM_HPP__
#define __BASE_MOMENTUM_HPP__

#include <base/Eigen.hpp>

namespace base {

struct Momentum{
    Momentum(){
        setNaN();
    }
    /** Set all members to NaN*/
    void setNaN();
    /** Check if the linear entries are valid (not NaN)*/
    bool hasValidLinearMomentum() const;
    /** Check if the angular entries are valid (not NaN)*/
    bool hasValidAngularMomentum() const;
    /** Check if the all entries are valid (not NaN)*/
    bool isValid() const;

    /** Linear momentum in order x-y-z (kg*m/s)*/
    base::Vector3d linear;
    /** Angular momentum in order x-y-z (kg*rad/s)*/
    base::Vector3d angular;
};

}

#endif
