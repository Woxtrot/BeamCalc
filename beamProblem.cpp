// Made by Wessel Eikelboom (S2565196) for the C++ assignment in the PiE course.
// Mechanical Engineering, Faculty of Engineering Technology, University of Twente
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "beamProblem.h"

using std::cout;
using std::endl;
using std::vector;
using std::ofstream;

// Calculation based on https://mechanicalc.com/reference/beam-analysis
// Derived class for a beam problem
void beamProblem::solve() {
    cout << "Solving a beam problem....." << endl; // Prompt to indicate that code has reached calculation
    vector<double> positions, shearLoads, momentLoads, deflections, slopes, stress; // declaring vectors used for the results

    if (supportType == 1){ // Cantilever support
        if (loadType == 1){ // Point load
            double a = loadLocation; // Changing variables for ease of calculation.
            double F = -load;
             for (double x = 0; x <= loadLocation; x += 0.01) { // Calculate results along length of the beam (steps of 10 mm) can be adjusted start at 0 up to load location
                positions.push_back(x); //saving position in vector
                // Internal shear
                shearLoads.push_back(F); //saving shear in vector
                // Internal moment
                double moment = -F*(a-x); //moment is later used for stress so not directly put into push_back command
                momentLoads.push_back(moment);
                // Deflection
                deflections.push_back(-(F*pow(x,2)) / (6 * modulus * areaMoment) * (3 * a - x));
                // Slope
                slopes.push_back(-(F*x) / (2 * modulus * areaMoment) * (2 * a - x));
                // Stress
                stress.push_back(moment * height/2 /(areaMoment));
            }
            if (loadLocation != length) { // if the load location is not located at the end of the beam, the part between load and beam end needs consideration.
                for (double x = loadLocation; x <= length; x += 0.01) {
                    positions.push_back(x);
                    // Internal shear
                    shearLoads.push_back(0);
                    // Internal moment
                    double moment = 0;
                    momentLoads.push_back(moment);
                    // Deflection
                    deflections.push_back(-(F * pow(a, 2)) / (6 * modulus * areaMoment) * (3 * x - a));
                    // Slope
                    slopes.push_back(-(F * pow(a, 2)) / (2 * modulus * areaMoment));
                    // Stress
                    stress.push_back(moment * height/2 /(areaMoment));
                }
            }
         }
        if (loadType == 2){ // distributed load
            double w = -load;
            for (double x = 0; x <= length; x += 0.01) { // not single force application point so only one for loop and calculation needed
                positions.push_back(x);
                // Internal shear
                shearLoads.push_back(w*(length-x));
                // Internal moment
                double moment = -w*pow((length-x),2)/2;
                momentLoads.push_back(moment);
                // Deflection
                deflections.push_back(-(w*pow(x,2) * (6 * pow(length,2) - 4*length*x + pow(x,2)))/(24 * modulus * areaMoment));
                // Slope
                slopes.push_back(-(w * x * (3 * pow(length,2) - 3*length*x + pow(x,2)))/(6 * modulus * areaMoment));
                // Stress
                stress.push_back(moment * height/2 /(areaMoment));
            }
        }
        if (loadType == 3){ // moment load, not implemented
            cout << "Moment loadtype for a cantilever beam is still to be implemented." << endl;
        }
    }
    if (supportType == 2){ // simply supported, not implemented
        if (loadType == 1){} // point load, not implemented
        if (loadType == 2){} // distributed load, not implemented
        if (loadType == 3){} // moment load, not implemented
    }

    // Export the data to a file
    ofstream outFile("beam_data.csv"); // exporting to csv file as it is easy to import into for example excel
    outFile << "Position (m), Deflection (m), Slope (radians), Shear Force (N), Bending Moment (Nm), Bending Stress (Pa)\n"; // column names
    for (size_t i = 0; i < positions.size(); i++) { //for every entry of the vectors, value is printed for different results and separated between commas
        outFile << positions[i] << "," << deflections[i] << "," << slopes[i] << "," << shearLoads[i] << "," << momentLoads[i] << "," << stress[i] << "\n";
    }
    outFile.close(); // closing of the file

}

