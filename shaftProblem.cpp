// Made by Wessel Eikelboom (S2565196) for the C++ assignment in the PiE course.
// Mechanical Engineering, Faculty of Engineering Technology, University of Twente

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "shaftProblem.h"

using std::cout;
using std::endl;
using std::vector;
using std::ofstream;

// Derived class for a shaft problem
void shaftProblem::solve() {
    double G = modulus; // Changing variable for ease of calculation.
    cout << "Solving a shaft problem....." << endl;
    vector<double> positions, torsionLoads, deflections, stress;
    if (supportType == 1){
        if (loadType == 1){}
        if (loadType == 2){}
    }

    // Export the data to a file
    ofstream outFile("shaft_data.csv");
    outFile << "Position (m), Angle of Twist (radians), Torsion (Nm), Torsion Stress (Pa)\n";
    for (size_t i = 0; i < positions.size(); i++) {
        outFile << positions[i] << "," << deflections[i]  << "," << torsionLoads[i] << "," << stress[i] << "\n";
    }
    outFile.close();

}



