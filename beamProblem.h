// Made by Wessel Eikelboom (S2565196) for the C++ assignment in the PiE course.
// Mechanical Engineering, Faculty of Engineering Technology, University of Twente

#ifndef BEAMCALC_BEAMPROBLEM_H
#define BEAMCALC_BEAMPROBLEM_H

#include "problem.h"

// Derived class for a beam problem
class beamProblem : public problem {
public:
    beamProblem (double l, double F, double E, int st, int lt, double ll, double I, double h): problem(l, F, E, st, lt, ll, I, h) {}// Constructor: initializes beam class with problem parameters
    void solve() override;// overrides the solve function from base class
};


#endif //BEAMCALC_BEAMPROBLEM_H
