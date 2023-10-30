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
void barProblem::solve() { // Prompt to indicate that code has reached calculation
    cout << "Solving a bar problem....." << endl;
    vector<double> positions, normalLoads, deflections, stress; // declaring vectors used for the results
    if (supportType == 1){ //cantilever
        if (loadType == 1){} //point load
        if (loadType == 2){} //distributed load
    }

    // Export the data to a file
    ofstream outFile("bar_data.csv"); // exporting to csv file as it is easy to import into for example excel
    outFile << "Position (m), Deflection (m), Normal Force (N), Normal Stress (Pa)\n"; // column names
    for (size_t i = 0; i < positions.size(); i++) { //for every entry of the vectors, value is printed for different results and separated between commas
        outFile << positions[i] << "," << deflections[i] << ","  << normalLoads[i] << "," << stress[i] << "\n";
    }
    outFile.close(); // closing of the file

}



