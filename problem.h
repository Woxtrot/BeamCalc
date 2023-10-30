// Made by Wessel Eikelboom (S2565196) for the C++ assignment in the PiE course.
// Mechanical Engineering, Faculty of Engineering Technology, University of Twente

#ifndef BEAMCALC_PROBLEM_H
#define BEAMCALC_PROBLEM_H

// Base class for structural problems
class problem { // define base class https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
protected: //make variables accessible to derived classes but not to code outside
    double length, load, modulus, loadLocation, areaMoment, height;
    int supportType, loadType;
public:
    problem(double l, double F, double E, int st, int lt, double ll, double I, double h)
    : length(l), load(F), modulus(E), supportType(st), loadType(lt), loadLocation(ll), areaMoment(I), height(h) {} // Constructor: initializes base class with problem parameters
    virtual void solve() = 0; // A virtual function to be overridden by derived classes
};


#endif //BEAMCALC_PROBLEM_H
