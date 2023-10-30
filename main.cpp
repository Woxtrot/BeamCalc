// Made by Wessel Eikelboom (S2565196) for the C++ assignment in the PiE course.
// Mechanical Engineering, Faculty of Engineering Technology, University of Twente

// This program is a simple beam calculator. It is made to handle simple bar, shaft and beam problems.

// What is beam theory?
// Beam theory considers the loading, deflection and stresses of a long one-dimensional structural member.
// This structural member can be connected (to the fixed world) and loaded in multiple different ways.
// Real-life problems can be simplified to represent a beam problem which can be analysed analytically.
// Structural members only considering longitudinal normal loading are considered to be bars.
// Members considering torsion/rotational loading around the longitudinal axis of the members are often considered to be shafts.
// Members considering bending due to transverse loading or applied transverse axis moments are considered to be beams.
// Combination of different load types is also possible but not considered in this calculator.
// Aspects such as deflection and stresses are dependent on geometric aspects such as length and cross-section, and material aspects
// such as shear and elastic modulus. For more information about beam theory: https://en.wikipedia.org/wiki/Euler%E2%80%93Bernoulli_beam_theory
// and : https://mechanicalc.com/reference/beam-analysis

// This calculator is set up to consider either a bar, shaft or beam problem.
// Some notes:
// Support
//      Bars and shafts are only cantilever supported
//      Beams can be cantilever or simply supported
// Loading
//      All three problems types support point and distributed loading
//      Beams also support moment loading
//      Point loads and moments can be put anywhere on the member
//      Distributed loads are uniform and span the entire member
// Cross-section
//      Bars and beams consider circular, rectangular and I-beam cross-sections
//      Shafts only consider circular cross-section
//

//// READ ME Important note:
////    Only cantilever point and distributed load equations for beams (all cross-sections) are fully implemented as of 30-10-2023
////    This is done as implementation of the actual calculations is repetitive and does not add significantly to this assignment.
#include <iostream>
#include <limits>
// Including headers for different classes and functions
#include "problem.h"
#include "beamProblem.h"
#include "barProblem.h"
#include "shaftProblem.h"
#include "calculateAreaMoment.h"
#include "errorCheck.h"

// Import items from standard library to avoid using "std::"
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::numeric_limits;
using std::streamsize;

int main() {
    // Declare variables
    int problemType, supportType, loadType, crossSection;
    double length, load, loadLocation, modulus;
    vector<double> areaMomentInfo; // vector as two outputs from function file are desired
    //Prompt user to choose a problem type
    cout << "Please choose a problem type: " << endl;
    cout << "1. Bar" << endl;
    cout << "2. Shaft" << endl;
    cout << "3. Beam" << endl;
    problemType = getInputInt("Enter your choice: ", 1, 3); // use getInputInt function to error check the integer user input

    if (problemType == 3){ // For a beam the problem can be (in this case) support two different ways
        cout << "Choose the support type: " << endl;
        cout << "1. Cantilever" << endl;
        cout << "2. Simply supported" << endl;
        supportType = getInputInt("Enter your choice: ", 1, 2);
    } else{ // bar and shaft are indeterminate when simply supported, requires more complex analysis
        supportType = 1; //therefore only cantilever support is possible
    }

    //Use of ternary operator to display correct problem type in text output prompts.
    cout << "Enter the length of the " << (problemType == 1 ? "bar" : (problemType == 2 ? "shaft" : "beam"))
         << " [m]: " << endl;
    length = getInputDouble(0.01, 999, true, false); // error check function for double user input

    cout << "Choose the load type: " << endl;
    cout << "1. Point " << (problemType == 2 ? "torque" : "load") << endl; // again use of ternary operator to display torque or load considering problem type
    cout << "2. Distributed " << (problemType == 2 ? "torque" : "load") << endl;
    if (problemType == 3)   { // moment loading is only applicable to beams
        cout << "3. Moment load" << endl;
        loadType = getInputInt("Enter your choice: ", 1, 3); // option 3 (moment load) is available for beams
            }
    else {
        loadType = getInputInt("Enter your choice: ", 1, 2); // only option 1 and 2 available for bars/shafts
    }

    if (loadType == 1){
        cout << "Enter the load location [m]." << endl;
        loadLocation = getInputDouble(0.01, length, true, false); // load location can not exceed member length
    }
    //Some explanation of the importance of the sign [- or none (+)] of the load input
    cout << "The sign of your input will decide the direction of the load. A minus sign (-) indicates a negative load, i.e. " << (problemType == 1 ? "left (in negative x-direction) facing load." : (problemType == 2 ? "left (in negative x-direction) facing torque." : (loadType == 3 ? "clockwise acting moment" : "downwards ( in negative y-direction) facing load.")))  << endl;
    if (problemType == 2){ // differentiation between torques for shafts and forces for bars/beams.
        cout << "Enter the " << (loadType == 1 ? "point torque magnitude [Nm]: " : "distributed torque magnitude [Nm/m]: ") << endl; // ternary used to differentiate between point and distributed loads
    } else{
        cout << "Enter the " << (loadType == 1 ? "point load magnitude [N]: " : (loadType == 2 ? "distributed load magnitude [N/m]: " : "moment load magnitude [Nm]: ")) << endl;
    }
    load = getInputDouble(-1e6, 1e6, true, true); // the sign of the load indicates direction, therefore both allowPositive and allowNegative are set to true

    cout << "Enter the " <<  (problemType == 2 ? "shear" : "elasticity") << " modulus of the material [N/m^2]: " << endl; //for shafts angle of twist is calculated, for which the shear modulus as opposed to the elastic modulus is relevant
    modulus = getInputDouble(0.01, 999e9, true, false); //variable called modulus as it could both be SHEAR or ELASTIC modulus.

    if (problemType == 2){
        crossSection = 1; // The torsional constant relevant in shaft calculation is dependent on cross-section, but not analytically calculable for a non-circular cross-section. For circular cross-section it equals the polar moment of area.
    }else{ // for bars and beams, area and second moment of area are the important parameters (respectively) and are easy to analytically calculate.
        cout << "Choose the cross section:" << endl;
        cout << "1. Circular" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. I-beam" << endl;
        crossSection = getInputInt("Enter your choice: ", 1, 3);
    }

    areaMomentInfo = calculateAreaMoment(crossSection, problemType); // calls a function to get second moment of area and cross-section height
                                                                     // a vector is used as a function can only return 1 variable and two values are needed

    problem *problem; //declare pointer to the base class, will either point to bar, shaft or beam problem
    // Creating an instance of the relevant problem type, user input https://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm
    if (problemType == 1){ //bar
        problem = new barProblem(length, load, modulus, supportType, loadType, loadLocation, areaMomentInfo[0], areaMomentInfo[1]); //all relevant parameters are used in the class
    }else if (problemType == 2){ //shaft
        problem = new shaftProblem(length, load, modulus, supportType, loadType, loadLocation, areaMomentInfo[0], areaMomentInfo[1]);
    }else{ //beam
        problem = new beamProblem(length, load, modulus, supportType, loadType, loadLocation, areaMomentInfo[0], areaMomentInfo[1]);
    }

problem->solve(); //calls the solve function based on the pointed to class. Based on https://www.geeksforgeeks.org/virtual-function-cpp/

    return 0; // Successful termination of the program
}

