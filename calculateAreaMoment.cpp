// Made by Wessel Eikelboom (S2565196) for the C++ assignment in the PiE course.
// Mechanical Engineering, Faculty of Engineering Technology, University of Twente
// Calculation based on : https://amesweb.info/section/second-moment-of-area-calculator.aspx

#include <iostream>
#include <cmath>
#include <vector>
#include "calculateAreaMoment.h"
#include "errorCheck.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<double> calculateAreaMoment(int crossSection, int problemType){// vector output as multiple results are relevant and functions can only output one variable
    vector<double> areaMomentInfo;
    double areaMoment;
    double height;
    //double areaMoment;
    if (crossSection == 1){
        double diameter;
        cout << "Please input the cross section diameter [mm]." << endl;
        diameter = getInputDouble(0.01, 9999, true, false);
        diameter /= 1000; // convert mm to m
        height = diameter; // for circular cross-sections height equals the diameter
        areaMoment = M_PI*pow(diameter,4)/64; // Calculating second moment of area Ixx
        if (problemType == 2){ // when considering a shaft problem the polar moment (J) of area is relevant
            areaMoment *= 2; // J = Ixx + Iyy, for circle Ixx=Iyy, therefore J=2*Ixx
        }
    }
    else if (crossSection==2){
        double width;
        cout << "Please enter the cross section height and width [mm]." << endl;
        height = getInputDouble(0.01, 9999, true, false);
        width = getInputDouble(0.01, 9999, true, false);
        height /=1000; // convert mm to m
        width /=1000; // convert mm to m
        areaMoment = width*pow(height,3)/12;
    } else{
        double t_flange, t_web, width;
        cout << "Please enter the I beam inside flange to flange height and total width [mm]."<< endl;
        height = getInputDouble(0.01, 9999, true, false);
        width = getInputDouble(0.01, 9999, true, false);
        height /=1000;
        width /=1000;
        cout << "Please also enter the flange and web thickness [mm]." << endl;
        t_flange = getInputDouble(0.01, 9999, true, false);
        t_web = getInputDouble(0.01, 9999, true, false);
        t_flange /=1000;
        t_web /=1000;
        areaMoment = pow(height,3)*t_web/12 + 2*(pow(t_flange,3)*width/12 + t_flange*width*pow(height+t_flange,2)/4);
    }
    areaMomentInfo.push_back(areaMoment); // second or polar moment of area is assigned to 0th element of the vector
    areaMomentInfo.push_back(height); //height is assigned to 1st element
    return areaMomentInfo;
}