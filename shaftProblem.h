// Made by Wessel Eikelboom (S2565196) for the C++ assignment in the PiE course.
// Mechanical Engineering, Faculty of Engineering Technology, University of Twente

#ifndef BEAMCALC_SHAFTPROBLEM_H
#define BEAMCALC_SHAFTPROBLEM_H

#include "problem.h"

// Derived class for a shaft problem
class shaftProblem : public problem {
public:
    shaftProblem (double l, double F, double E, int st, int lt, double ll, double I, double h): problem(l, F, E, st, lt, ll, I, h) {} // Constructor: initializes shaft class with problem parameters
    void solve() override; // overrides the solve function from base class
};

#endif //BEAMCALC_SHAFTPROBLEM_H
