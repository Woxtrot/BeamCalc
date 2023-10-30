// Made by Wessel Eikelboom (S2565196) for the C++ assignment in the PiE course.
// Mechanical Engineering, Faculty of Engineering Technology, University of Twente

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "barProblem.h"

using std::cout;
using std::endl;
using std::vector;
using std::ofstream;

// Derived class for a bar problem
void barProblem::solve() {
    cout << "Solving a bar problem....." << endl;
    vector<double> positions, normalLoads, deflections, stress;
    if (supportType == 1){
        if (loadType == 1){}
        if (loadType == 2){}
    }

    // Export the data to a file
    ofstream outFile("bar_data.csv");
    outFile << "Position (m), Deflection (m), Normal Force (N), Normal Stress (Pa)\n";
    for (size_t i = 0; i < positions.size(); i++) {
        outFile << positions[i] << "," << deflections[i] << ","  << normalLoads[i] << "," << stress[i] << "\n";
    }
    outFile.close();

}



