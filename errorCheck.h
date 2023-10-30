// Made by Wessel Eikelboom (S2565196) for the C++ assignment in the PiE course.
// Mechanical Engineering, Faculty of Engineering Technology, University of Twente

#ifndef BEAMCALC_ERRORCHECK_H
#define BEAMCALC_ERRORCHECK_H
using std::string;

// Function to get an integer input with error checking
int getInputInt(const string& prompt, int min, int max); //declaring function
// Function to get a double input with error checking
double getInputDouble(double min, double max, bool allowPositive, bool allowNegative);//declaring function


#endif //BEAMCALC_ERRORCHECK_H
