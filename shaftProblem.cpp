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
    cout << "Solving a shaft problem....." << endl; // Prompt to indicate that code has reached calculation
    vector<double> positions, torsionLoads, deflections, stress;
    if (supportType == 1){ // cantilever
        if (loadType == 1){} //point load
        if (loadType == 2){} //distributed load
    }

    // Export the data to a file
    ofstream outFile("shaft_data.csv");
    outFile << "Position (m), Angle of Twist (radians), Torsion (Nm), Torsion Stress (Pa)\n"; // column names
    for (size_t i = 0; i < positions.size(); i++) { //for every entry of the vectors, value is printed for different results and separated between commas
        outFile << positions[i] << "," << deflections[i]  << "," << torsionLoads[i] << "," << stress[i] << "\n";
    }
    outFile.close(); // closing of the file

}



